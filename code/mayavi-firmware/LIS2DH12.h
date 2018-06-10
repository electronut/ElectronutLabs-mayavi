/** @file LIS2DH12.h
 *
 * @brief Driver for LIS2DH12 chip
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2018 Electronut Labs.
 * All rights reserved. 
*/

#ifndef __LIS2DH12_H__
#define __LIS2DH12_H__

#include <stdint.h>
#include <stdbool.h>

/*Pin Definitions*/
// #define SA0                     14
// #define CS                      13
#define INT1                    15
#define INT2                    16

/*Device Address*/
#define LIS2DH12_ADDR           0x19U     // SA0 HIGH.
// #define LIS2DH12_ADDR           0x18U     // SA0 LOW.

/*Register Addresses*/
#define WHO_AM_I                0x0F

#define CTRL_REG0               0x1E
#define TEMP_CFG_REG            0X1F
#define CTRL_REG1               0x20
#define CTRL_REG2               0x21
#define CTRL_REG3               0x22
#define CTRL_REG4               0x23
#define CTRL_REG5               0x24
#define CTRL_REG6               0x25

#define STATUS_REG              0x27

#define OUT_X_L                 0x28
#define OUT_X_H                 0x29
#define OUT_Y_L                 0x2A
#define OUT_Y_H                 0x2B
#define OUT_Z_L                 0x2C
#define OUT_Z_H                 0x2D

#define FIFO_CTRL_REG           0x2E
#define FIFO_SRC_REG            0x2F

#define INT1_CFG                0x30
#define INT1_SRC                0x31
#define INT1_THS                0x32
#define INT1_DURATION           0x33
#define INT2_CFG                0x34
#define INT2_SRC                0x35
#define INT2_THS                0x36
#define INT2_DURATION           0x37

/*
 * Enable X/Y/Z axes, as per your choice
 * CTRL_REG1
*/
typedef enum {
  LIS2DH12_ENABLE_AXIS_X        =   0x01,
  LIS2DH12_ENABLE_AXIS_Y        =   0x02,
  LIS2DH12_ENABLE_AXIS_Z        =   0x04,
  LIS2DH12_ENABLE_AXIS_XY       =   0x03,
  LIS2DH12_ENABLE_AXIS_YZ       =   0x06,
  LIS2DH12_ENABLE_AXIS_XZ       =   0x05,
  LIS2DH12_ENABLE_AXIS_XYZ      =   0x07
} LIS2DH12_ENABLE_AXIS_t;

/**
 * Select Output Data Rate (ODR)
 * CTRL_REG1
 */
typedef enum {
  LIS2DH12_POWER_DOWN           =   0x00,
  LIS2DH12_ODR_1_HZ             =   0x10,
  LIS2DH12_ODR_10_HZ            =   0x20,
  LIS2DH12_ODR_25_HZ            =   0x30,
  LIS2DH12_ODR_50_HZ            =   0x40,
  LIS2DH12_ODR_100_HZ           =   0x50,
  LIS2DH12_ODR_200_HZ           =   0x60,
  LIS2DH12_ODR_400_HZ           =   0x70,
  LIS2DH12_ODR_1_620_KHZ        =   0x80,         // Low-power (1.620 kHz)
  LIS2DH12_ODR_1_344_OR_5_376_KHZ = 0x90        // Normal/HR (1.344 kHz), Low-power (5.376 kHz)
} LIS2DH12_ODR_t;

/**
 * Low power mode
 * CTRL_REG1
 */
typedef enum {
  LIS2DH12_LOW_PWR_MODE_DISABLE =   0x00,
  LIS2DH12_LOW_PWR_MODE_ENABLE  =   0x08,
} LIS2DH12_LOW_PWR_MODE_t;

/**
 * Operation mode selection between Normal and High-resolution modes
 * CTRL_REG4
 */
typedef enum {
  LIS2DH12_OP_MODE_NORMAL       =   0x00,
  LIS2DH12_OP_MODE_HR           =   0x08,
} LIS2DH12_OP_MODE_t;

typedef enum {
  LIS2DH12_CURR_OP_MODE_LP      = 0x01,
  LIS2DH12_CURR_OP_MODE_NRML    = 0x02,
  LIS2DH12_CURR_OP_MODE_HR      = 0x03
} LIS2DH12LIS2DH12_CURR_OP_MODE_t;
/**
 * Full scale mode selection
 * CTRL_REG4
 */
typedef enum {
  LIS2DH12_FS_2G                =   0x00,
  LIS2DH12_FS_4G                =   0x10,
  LIS2DH12_FS_8G                =   0x20,
  LIS2DH12_FS_16G               =   0x30
} LIS2DH12_FS_t;

typedef enum {
  LIS2DH12_EN_PIN_INT1          =   0x01,
  LIS2DH12_EN_PIN_INT2          =   0x02,
  LIS2DH12_EN_PIN_INT1_INT2     =   0x03,
} LIS2DH12_EN_PIN_t;

struct LIS2DH12_settings {
  uint8_t op_mode;
  uint8_t low_power_mode;
  uint8_t curr_mode;
  uint8_t full_scale;
  uint8_t odr;
  uint8_t select_axes;
};

// random accelerometer data generator
void accelerometer_data(int16_t *x_val, int16_t *y_val, int16_t *z_val);

/*
 * function to read accelerometer registers.
*/
ret_code_t LIS2DH12_read_register(uint8_t device_addr, uint8_t register_addr, uint8_t *p_data, uint32_t bytes);

/*
 * function to test availablility of accelerometer
*/
uint8_t LIS2DH12_who_am_i(void);

/*
 * function for setting active mode on MMA7660 accelerometer.
*/
void LIS2DH12_init(void);

/*
 * function to read available accelerometer data
*/
void LIS2DH12_read_acc_data(int16_t *x_value, int16_t *y_value, int16_t *z_value);

float get_accel_data_in_g(int16_t val);

/*
 * function to set LIS2DH12 in BYPASS mode.
*/
void LIS2DH12_set_BYPASS_mode(void);

/*
 * function to set LIS2DH12 in FIFO mode.
*/
void LIS2DH12_set_FIFO_mode(void);

/*
 * function to set LIS2DH12 in STREAM mode.
*/
void LIS2DH12_set_STREAM_mode(void);

/*
 * function to set LIS2DH12 in STREAM-FIFO mode.
*/
void LIS2DH12_set_STREAM_to_FIFO_mode(void);

/*
 * function to configure FIFO mode and get data.
*/
void LIS2DH12_FIFO_mode_data(int16_t *x_value, int16_t *y_value, int16_t *z_value);

/*
 * function to configure STREAM mode and get data.
*/
void LIS2DH12_STREAM_mode_data(int16_t *x_value, int16_t *y_value, int16_t *z_value);

/*
 * function to read data from fifo buffer.
*/
void read_fifo_data(int16_t *x_fifo, int16_t *y_fifo, int16_t *z_fifo);

/*
 * function to check for inertial wake-up
*/
bool LIS2DH12_inertial_wake_detect(void);

/*
 * function to enable free-fall detect.
*/
void LIS2DH12_free_fall_config(void);

/*
 * function to enable 6D orientation detect functionality.
*/
void LIS2DH12_6D_config(void);

/*
 *  Read (to clear) interrupt status register.
 */
uint8_t LIS2DH12_read_int_status();

/*
 * function to configure inertial wake-up detection.
*/
void LIS2DH12_inertial_wake_config(void);

/**
 * @brief TWI initialization.
 */
void twi_init(void);

#endif