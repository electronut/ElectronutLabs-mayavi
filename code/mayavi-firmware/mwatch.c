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
    p_mwatch_cfg->time_count = 0;
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
    p_mwatch_cfg->time_count++;

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
            char str_count[16];
            sprintf(str_count, "%d", p_mwatch_cfg->time_count);

            // set text style
            Adafruit_GFX_setTextSize(2);
            Adafruit_GFX_setTextColor(WHITE, BLACK);

            // set text position
            Adafruit_GFX_setCursor(10, 10);

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