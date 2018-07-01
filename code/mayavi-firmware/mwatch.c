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

#include "mwatch_melody.h"
#include "mwatch.h"

#include "SSD1306.h"
#include "SSD1306/Adafruit_GFX.h"

// melody module configuration 
static mwatch_melody_config_t g_melody_config;

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
    // set mode
    p_mwatch_cfg->mode = eMWATCH_SPLASH;

    // set delay function
    p_mwatch_cfg->delay_ms = f;

    // initialise display
    SSD1306_begin(SSD1306_SWITCHCAPVCC, 0x3C, false);
    Adafruit_GFX_init(SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, SSD1306_drawPixel);

    // set display flag
    p_mwatch_cfg->b_pending_refresh = true;

    // set melody pin 
    g_melody_config.pin = 20;

    // initialise melody module
    mwatch_melody_init(&g_melody_config);
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

/*!
 * @brief Refresh display
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_refresh_display(mwatch_cfg_t* p_mwatch_cfg)
{
    // display according to mode
    switch(p_mwatch_cfg->mode)
    {
        case eMWATCH_SPLASH: // show splash screen
        {
            SSD1306_clearDisplay();
            Adafruit_GFX_drawBitmap(0, 0,  el_logo, 128, 64, 1);
            SSD1306_display();

            // play melody
            mwatch_melody_t melody;

            mwatch_melody_play(&g_melody_config, &melody);

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

}
