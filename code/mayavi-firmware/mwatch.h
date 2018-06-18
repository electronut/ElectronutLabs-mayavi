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

#ifdef __cplusplus 
extern “C” { 
#endif

/**@brief Watch modes  */
typedef enum
{
    eMWATCH_SPLASH = 0,
    eMWATCH_TIME_DISPLAY, 
    eMWATCH_SLEEP,
    eMWATCH_SHOW_TEXT
} mwatch_mode_t;

/**@brief Mayavi Watch configuration structure. */
typedef struct 
{
    bool b_pending_refresh;   /**< One shot flag to indicate pending refresh */
    uint64_t time_count;      /**< time counter */
    mwatch_mode_t mode;       /**< Current watch mode (state machine) */

    void (*delay_ms)(uint32_t ms);        /**< Pointer to delay ms function */
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


#ifdef __cplusplus 
}
#endif

#endif /* _MWATCH_H */
