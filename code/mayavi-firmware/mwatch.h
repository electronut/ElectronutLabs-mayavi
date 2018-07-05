/** @file mwatch.h
 *
 * @brief Module that represents the watch
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2018 Electronut Labs.
 * All rights reserved. 
*/

#ifndef _MWATCH_H
#define _MWATCH_H

#include <stdint.h>
#include <stdbool.h>

#include "mwatch_melody.h"

#ifdef __cplusplus 
extern “C” { 
#endif

/**@brief Watch modes  */
typedef enum
{
    eMWATCH_SPLASH = 0,
    eMWATCH_TIME_DISPLAY, 
    eMWATCH_SLEEP,
    eMWATCH_SHOW_TEXT,
    eMWATCH_DRAW
} mwatch_mode_t;

/**@brief Watch events  */
typedef enum
{
    eMWATCH_EVT_NULL = 0,        /**< no event */
    eMWATCH_EVT_LEFT,        /**< left button press */
    eMWATCH_EVT_RIGHT        /**< right button press */
} mwatch_evt_t;

/**@brief Mayavi Watch configuration structure. */
typedef struct 
{
    bool b_pending_refresh;   /**< One shot flag to indicate pending refresh */
    bool b_pending_cmd;       /**< One shot flag to indicate pending cmd  */

    uint32_t seconds;         /**< time counter in seconds */
    mwatch_mode_t mode;       /**< Current watch mode (state machine) */

    // last cmd
    char last_cmd[128];       /**< last cmd isued */

    void (*delay_ms)(uint32_t ms);        /**< Pointer to delay ms function */

    mwatch_melody_config_t melody_config;  /**< melody configuration */

    uint16_t x_pos;                         /**< draw mode last x position*/
    uint16_t y_pos;                         /**< draw mode last y position*/
    
    mwatch_evt_t event;                     /**< last event */
} mwatch_cfg_t;

/*!
 * @brief Initialise watch module
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_init(mwatch_cfg_t* p_mwatch_cfg, void (*delay_ms)(uint32_t));


/*!
 * @brief Called for every clock tick (1 Hz)
 * 
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_tick(mwatch_cfg_t* p_mwatch_cfg);


/*!
 * @brief Is a display refresh pending?
 * @param[in] @mwatch_cfg_t
 * @return bool
 */
bool mwatch_is_refresh_pending(mwatch_cfg_t* p_mwatch_cfg);

/*!
 * @brief Refresh display
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_refresh_display(mwatch_cfg_t* p_mwatch_cfg);

/*!
 * @brief Sleep - go to power save mode 
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_sleep(mwatch_cfg_t* p_mwatch_cfg);

/*!
 * @brief cmd - handle serial command 
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_cmd(mwatch_cfg_t* p_mwatch_cfg, char* cmd, uint32_t len);

/*!
 * @brief set event
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_set_event(mwatch_cfg_t* p_mwatch_cfg, mwatch_evt_t event);

/*!
 * @brief clear events
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_clear_event(mwatch_cfg_t* p_mwatch_cfg);

#ifdef __cplusplus 
}
#endif

#endif /* _MWATCH_H */
