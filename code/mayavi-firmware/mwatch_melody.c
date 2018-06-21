/** @file melody.c
 *
 * @brief Play a melody
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2018 Electronut Labs.
 * All rights reserved. 
*/

#include "app_pwm.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

#include "mwatch_melody.h"

APP_PWM_INSTANCE(PWM1,1);                   // Create the instance "PWM1" using TIMER1.

static volatile bool ready_flag;            // A flag indicating PWM status.

void pwm_ready_callback(uint32_t pwm_id)    // PWM callback function
{
    ready_flag = true;
}

/*!
 * @brief Initialise melody module
 * @param[in] melody module configuration
 * @return void
 */
void mwatch_melody_init(mwatch_melody_config_t* melody_config)
{
    /* 2-channel PWM, 200Hz, output on DK LED pins. */
    app_pwm_config_t pwm1_cfg = APP_PWM_DEFAULT_CONFIG_1CH(5000L, melody_config->pin);

    /* Initialize and enable PWM. */
    ret_code_t err_code = app_pwm_init(&PWM1, &pwm1_cfg, pwm_ready_callback);
    APP_ERROR_CHECK(err_code);

    //app_pwm_enable(&PWM1);

    //while (app_pwm_channel_duty_set(&PWM1, 0, 50) == NRF_ERROR_BUSY);
}

/*!
 * @brief play melody
 * @param[in] melody Melody to play
 * @return void
 */
void mwatch_melody_play(mwatch_melody_config_t* melody_config, 
    mwatch_melody_t* melody)
{

    app_pwm_enable(&PWM1);
    while (app_pwm_channel_duty_set(&PWM1, 0, 50) == NRF_ERROR_BUSY);

    nrf_delay_ms(1000);

    while (app_pwm_channel_duty_set(&PWM1, 0, 0) == NRF_ERROR_BUSY);
    app_pwm_disable(&PWM1);

    // set pin to LOW
    nrf_gpio_pin_clear(melody_config->pin);
}
