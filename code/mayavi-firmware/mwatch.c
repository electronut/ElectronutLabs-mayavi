/** @file mwatch.c
 *
 * @brief Module that represents the watch
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2018 Electronut Labs.
 * All rights reserved. 
*/

#include <string.h>
#include <stdio.h>

#include "nrf_log.h"

#include "mwatch_melody.h"
#include "mwatch.h"

#include "SSD1306.h"
#include "SSD1306/Adafruit_GFX.h"

/*!
 * @brief Initialise watch module
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_init(mwatch_cfg_t* p_mwatch_cfg, void (*f)(uint32_t))
{
    // initialise variables:

    // reset time
    p_mwatch_cfg->seconds = 0;
    // reset display flag
    p_mwatch_cfg->b_pending_refresh = false;
    // reset cmd flag
    p_mwatch_cfg->b_pending_cmd = false;
    // set mode
    p_mwatch_cfg->mode = eMWATCH_DRAW; // eMWATCH_SPLASH;

    // set coords 
    p_mwatch_cfg->x_pos = 0;
    p_mwatch_cfg->y_pos = 0;
    
    // set delay function
    p_mwatch_cfg->delay_ms = f;

    // initialise display
    SSD1306_begin(SSD1306_SWITCHCAPVCC, 0x3C, false);
    Adafruit_GFX_init(SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, SSD1306_drawPixel);

    // set display flag
    p_mwatch_cfg->b_pending_refresh = true;

    // set melody pin 
    p_mwatch_cfg->melody_config.pin = 20;

    // initialise melody module
    mwatch_melody_init(&p_mwatch_cfg->melody_config);
}


/*!
 * @brief Called for every clock tick (1 Hz)
 * 
 * @param[in] @mwatch_cfg_t
 * @return void
 */
inline void mwatch_tick(mwatch_cfg_t* p_mwatch_cfg)
{
    // increment time counter
    p_mwatch_cfg->seconds++;

    // set display flag
    p_mwatch_cfg->b_pending_refresh = true;
}

/*!
 * @brief Is a display refresh pending?
 * @param[in] @mwatch_cfg_t
 * @return bool
 */
inline bool mwatch_is_refresh_pending(mwatch_cfg_t* p_mwatch_cfg)
{
    return p_mwatch_cfg->b_pending_refresh;
}


/*!
 * @brief convert seconds to hr/min/sec
 * @param[in] seconds
 * @return void
 * 
 * Example:
 * 
 * 7400 -> (2, 3, 20)
 * 
 */
static inline void seconds_to_time(uint32_t count, uint8_t* hrs, uint8_t* min, 
                            uint8_t* sec)
{
    *hrs = (count / 3600) % 24;
    *min = (count / 60) % 60;
    *sec = count % 60;
}

/*!
 * @brief convert hr/min/sec to count (seconds)
 * @param[in] seconds
 * @return seconds
 * 
 * Example:
 * 
 * (2, 3, 20) -> 7400
 * 
 */
static inline uint32_t time_to_seconds(uint8_t hrs, uint8_t min, 
                            uint8_t sec)
{
    return 3600*hrs + 60*min + sec;
}

static void handle_cmd(mwatch_cfg_t* p_mwatch_cfg)
{
    int hrs;
    int min;
    int sec;
    char cmd1[4];
    sscanf(p_mwatch_cfg->last_cmd, "%2s %2d:%2d:%2d", cmd1, &hrs, &min, &sec);

    NRF_LOG_INFO("%2d %2d %2d", hrs, min, sec);

    p_mwatch_cfg->seconds = time_to_seconds((uint8_t)hrs, (uint8_t)min, (uint8_t)sec);
}

/*!
 * @brief Refresh display
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_refresh_display(mwatch_cfg_t* p_mwatch_cfg)
{
    // take care of pending commands
    if (p_mwatch_cfg->b_pending_cmd)
    {
        handle_cmd(p_mwatch_cfg);
        // reset 
        p_mwatch_cfg->b_pending_cmd = false;
    }

    // display according to mode
    switch(p_mwatch_cfg->mode)
    {
        case eMWATCH_SPLASH: // show splash screen
        {
            SSD1306_clearDisplay();
            Adafruit_GFX_drawBitmap(0, 0,  el_logo, 128, 64, 1);
            SSD1306_display();

            mwatch_melody_play(&(p_mwatch_cfg->melody_config));

            // delay
            p_mwatch_cfg->delay_ms(1000);

            // clear screen
            SSD1306_clearDisplay();
            SSD1306_display();

            // set mode
            p_mwatch_cfg->mode = eMWATCH_TIME_DISPLAY;
        }
        break;

        case eMWATCH_TIME_DISPLAY: // show current time
        {
            // convert count to time
            uint8_t hrs;
            uint8_t min;
            uint8_t sec;
            seconds_to_time(p_mwatch_cfg->seconds, &hrs, &min, &sec);
            char str_count[16];
            sprintf(str_count, "%02d:%02d:%02d", hrs, min, sec);

            // set text style
            Adafruit_GFX_setTextSize(2);
            Adafruit_GFX_setTextColor(WHITE, BLACK);

            // set text position
            Adafruit_GFX_setCursor(15, 20);

            // draw string
            for (int i = 0; i < strlen(str_count); i++) 
            {
                Adafruit_GFX_write(str_count[i]);
            }

            // show
            SSD1306_display();
        }
        break;

        case eMWATCH_DRAW: // drawing mode
        {
            // line offset in pixels
            uint16_t offset = 2;
            
            // draw line to the current cursor position
            if (p_mwatch_cfg->event == eMWATCH_EVT_LEFT)
            {
                // new pos
                uint16_t x_pos = p_mwatch_cfg->x_pos + offset;
                Adafruit_GFX_drawLine(p_mwatch_cfg->x_pos, p_mwatch_cfg->y_pos,
                                x_pos, p_mwatch_cfg->y_pos, WHITE);
                // save 
                p_mwatch_cfg->x_pos = x_pos;
            }
            else if (p_mwatch_cfg->event == eMWATCH_EVT_RIGHT)
            {
                // new pos
                uint16_t y_pos = p_mwatch_cfg->y_pos + offset;
                Adafruit_GFX_drawLine(p_mwatch_cfg->x_pos, p_mwatch_cfg->y_pos,
                                p_mwatch_cfg->x_pos, y_pos, WHITE);
                // save 
                p_mwatch_cfg->y_pos = y_pos;
            }

            // clear event
            mwatch_clear_event(p_mwatch_cfg);

            // show
            SSD1306_display();
        }
        break;

        default:
            break;
    }

    // reset pending display
    p_mwatch_cfg->b_pending_refresh = false;
}

/*!
 * @brief Sleep - go to power save mode 
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_sleep(mwatch_cfg_t* p_mwatch_cfg)
{

}

/*!
 * @brief cmd - handle serial command 
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_cmd(mwatch_cfg_t* p_mwatch_cfg, char* cmd, uint32_t len)
{
    strncpy(p_mwatch_cfg->last_cmd, cmd, len);
    p_mwatch_cfg->last_cmd[len] = '\0';

    NRF_LOG_INFO("data:%s", p_mwatch_cfg->last_cmd);

    // set cmd flag
    p_mwatch_cfg->b_pending_cmd = true;
}

/*!
 * @brief set event
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_event(mwatch_cfg_t* p_mwatch_cfg, mwatch_evt_t event)
{
    p_mwatch_cfg->event = event;
    p_mwatch_cfg->b_pending_refresh = true;
}

/*!
 * @brief clear events
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_clear_event(mwatch_cfg_t* p_mwatch_cfg)
{
    p_mwatch_cfg->event = eMWATCH_EVT_NULL;
}