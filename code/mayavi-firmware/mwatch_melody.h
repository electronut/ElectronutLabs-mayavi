/** @file melody.h
 *
 * @brief Play a melody
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2018 Electronut Labs.
 * All rights reserved. 
*/

#ifndef _MELODY_H
#define _MELODY_H

#include <stdint.h>

#ifdef __cplusplus 
extern "C" { 
#endif

// Reference:
// https://www.arduino.cc/en/Tutorial/toneMelody

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define DUR_F 8    // full note 
#define DUR_H 4    // half note
#define DUR_Q 2    // quarter note
#define DUR_E 1    // eighth note
#define DUR_R 0    // rest

/**@brief Max no. of notes  */
#define MAX_NOTES 128

/**@brief Melody structure  */
typedef struct
{
  uint16_t notes[MAX_NOTES];              /**< notes in melody  */
  uint8_t durations[MAX_NOTES];           /**< note durations: 4 = quarter note, 8 = eighth note, etc. */
  uint8_t length;                         /**< Number of notes used */
  uint8_t curr_note;                      /**< Index of current note */
} mwatch_melody_t; 

/**@brief Melody module configuration  */
typedef struct
{
  uint32_t pin;                       /**< Pin used for output */
  mwatch_melody_t curr_melody;       /**< Ptr to current melody */
} mwatch_melody_config_t;

/*!
 * @brief Initialise melody module
 * @param[in] melody module configuration
 * @return void
 */
void mwatch_melody_init(mwatch_melody_config_t* melody_config);

/*!
 * @brief play melody
 * @param[in] melody Melody to play
 * @return void
 */
void mwatch_melody_play(mwatch_melody_config_t* melody_config);

/*!
 * @brief Called for every melody timer tick
 * 
 * @param[in] @mwatch_cfg_t
 * @return void
 */
void mwatch_melody_tick(mwatch_melody_config_t* melody_config);


#ifdef __cplusplus 
}
#endif

#endif /* _MELODY_H */
