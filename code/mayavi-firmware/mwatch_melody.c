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
#include "nrf_log.h"

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
    
}

// create a test melody
static void create_melody(mwatch_melody_t* melody)
{
    uint16_t notes[] = {NOTE_C7, NOTE_D7, NOTE_E7, 
                        NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7, NOTE_C8};
    uint8_t durations[] = {DUR_H, DUR_H, DUR_H, DUR_H, DUR_H, DUR_H, DUR_H, DUR_H};
    uint8_t num_notes = 8;

    for(int i = 0; i < num_notes; i++)
    {
        melody->notes[i] = notes[i];
        melody->durations[i] = durations[i];
    }
    melody->curr_note = 0;
    melody->length = 8;

}
/*!
 * @brief play melody
 * @param[in] melody Melody to play
 * @return void
 */
void mwatch_melody_play(mwatch_melody_config_t* melody_config)
{
    // create a test melody
    create_melody(&(melody_config->curr_melody));
}

/*!
 * Convert frequnecy to us for PWM 
 */
inline static uint32_t freq_to_us(uint16_t freq)
{   
    return 1000000/freq;
}

/*!
 * @brief Called for every melody timer tick
 * 
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_melody_tick(mwatch_melody_config_t* melody_config)
{
    // how many 
    static uint8_t count = 0;
    // get melody parameters
    mwatch_melody_t* melody = &(melody_config->curr_melody);
   
    uint8_t curr_note = melody->curr_note;
    uint8_t curr_duration = melody->durations[curr_note];

    // are we still playing this melody?
    if (melody->curr_note < melody->length)
    {
        // starting note
        if (count == 0)
        {            
            // set PWM frequency
            uint32_t freq = freq_to_us(melody->notes[curr_note]);
            NRF_LOG_INFO("count 0, f = %d", freq);
            // set PWM config
            app_pwm_config_t pwm1_cfg = APP_PWM_DEFAULT_CONFIG_1CH(freq, melody_config->pin);
            // init PWM
            ret_code_t err_code = app_pwm_init(&PWM1, &pwm1_cfg, pwm_ready_callback);
            APP_ERROR_CHECK(err_code);
            // enable PWM
            app_pwm_enable(&PWM1);
            // 50 % duty cycle
            while (app_pwm_channel_duty_set(&PWM1, 0, 50) == NRF_ERROR_BUSY);
            // increment count
            count++;
        }   
        else if (count == curr_duration) // stop note
        {
            NRF_LOG_INFO("count %d", curr_duration);

            // stop PWM
            // enable PWM
            app_pwm_disable(&PWM1);
            ret_code_t err_code = app_pwm_uninit(&PWM1);
            APP_ERROR_CHECK(err_code);

            // reset count
            count = 0;

            // next note
            melody->curr_note++;
        }
        else 
        {
            // increment count
            count++;
        }
        
    }
}