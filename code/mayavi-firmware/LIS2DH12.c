/** @file LIS2DH12.c
 *
 * @brief Driver for LIS2DH12 chip
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2018 Electronut Labs.
 * All rights reserved. 
*/

#include "nrf_drv_gpiote.h"
#include "nrf_drv_twi.h"

#include "LIS2DH12.h"

// TWI handle
extern nrf_drv_twi_t m_twi_master;

static struct LIS2DH12_settings settings;

/*
 * function to read accelerometer registers.
*/
ret_code_t LIS2DH12_read_register(uint8_t device_addr, uint8_t register_addr, uint8_t *p_data, uint32_t bytes)
{
  ret_code_t err_code;

  err_code = nrf_drv_twi_tx(&m_twi_master, device_addr, &register_addr, 1, false);
  APP_ERROR_CHECK(err_code);

  if (err_code != NRF_SUCCESS)
  {
    return err_code;
  }

  err_code = nrf_drv_twi_rx(&m_twi_master, device_addr, p_data, bytes);
  return err_code;
}

/**
 * @brief function to configure sensor's boot settings
 */
static void LIS2DH12_config(void)
{
  ret_code_t err_code;
  uint8_t tx_data[2];

  tx_data[0] = CTRL_REG1;
  tx_data[1] = settings.odr | settings.low_power_mode | settings.select_axes;

  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  tx_data[0] = CTRL_REG4;
  tx_data[1] = settings.full_scale | settings.op_mode;

  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);
}

/*
 * function for setting active mode on MMA7660 accelerometer.
*/
void LIS2DH12_init(void)
{
  settings.select_axes = LIS2DH12_ENABLE_AXIS_XYZ;
  settings.low_power_mode = LIS2DH12_LOW_PWR_MODE_ENABLE;
  settings.op_mode = LIS2DH12_OP_MODE_NORMAL;
  settings.full_scale = LIS2DH12_FS_4G;
  settings.odr = LIS2DH12_ODR_1_HZ;

  if (settings.low_power_mode != 0)
  { // if low power mode is enabled
    settings.curr_mode = LIS2DH12_CURR_OP_MODE_LP;
  }
  else
  {
    if (settings.op_mode == LIS2DH12_OP_MODE_HR)
    {
      // if high resol. mode is enabled
      settings.curr_mode = LIS2DH12_CURR_OP_MODE_HR;
    }
    else
    { // if normal mode is enabled
      settings.curr_mode = LIS2DH12_CURR_OP_MODE_NRML;
    }
  }
  // enable I2C mode
  // nrf_gpio_pin_dir_set(CS, NRF_GPIO_PIN_DIR_OUTPUT);
  // nrf_gpio_pin_set(CS);

  // nrf_gpio_pin_dir_set(SA0, NRF_GPIO_PIN_DIR_OUTPUT);
  // nrf_gpio_pin_set(SA0);

  LIS2DH12_config();
}

/*
 * function to test availablility of accelerometer
*/
uint8_t LIS2DH12_who_am_i(void)
{
  uint8_t who_am_i = 0;
  LIS2DH12_read_register(LIS2DH12_ADDR, WHO_AM_I, &who_am_i, 1);
  return who_am_i;
}

/*
 * function to set LIS2DH12 in BYPASS mode.
*/
void LIS2DH12_set_BYPASS_mode(void)
{
  ret_code_t err_code;
  // FM[1:0] = [0,0] for BYPASS mode
  uint8_t tx_data[2] = {FIFO_CTRL_REG, 0x00};

  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);
}

/*
 * function to set LIS2DH12 in FIFO mode.
*/
void LIS2DH12_set_FIFO_mode(void)
{
  ret_code_t err_code;
  // FM[1:0] = [0,1] for FIFO mode
  uint8_t tx_data[2] = {FIFO_CTRL_REG, 0x40};

  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);
}

/*
 * function to set LIS2DH12 in STREAM mode.
*/
void LIS2DH12_set_STREAM_mode(void)
{
  ret_code_t err_code;
  // FM[1:0] = [1,0] for STREAM mode
  uint8_t tx_data[2] = {FIFO_CTRL_REG, 0x80};

  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);
}

/*
 * function to set LIS2DH12 in STREAM-FIFO mode.
*/
void LIS2DH12_set_STREAM_to_FIFO_mode(void)
{
  ret_code_t err_code;
  // FM[1:0] = [1,1] for STREAM-TO-FIFO mode
  uint8_t tx_data[2] = {FIFO_CTRL_REG, 0xC0};

  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);
}

/*
 * function to configure FIFO mode and get data.
*/
void LIS2DH12_FIFO_mode_data(int16_t *x_value, int16_t *y_value, int16_t *z_value)
{
  ret_code_t err_code;
  int16_t x_data, y_data, z_data;

  uint8_t fifo_src_status = 0;

  // enable FIFO by setting FIFO_EN bit to 1 in CTRL_REG5
  uint8_t tx_data[2] = {CTRL_REG5, 0x40};
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // Activate FIFO mode
  LIS2DH12_set_FIFO_mode();

  // check for OVRN_FIFO
  do
  {
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, FIFO_SRC_REG, &fifo_src_status, sizeof(fifo_src_status));
    APP_ERROR_CHECK(err_code);
  } while (!(fifo_src_status && 0b01000000));

  // read data from output registers.
  read_fifo_data(&x_data, &y_data, &z_data);
  *x_value = x_data;
  *y_value = y_data;
  *z_value = z_data;

  // enable BYPASS mode to reset FIFO buffer
  LIS2DH12_set_BYPASS_mode();
}

/*
 * function to read data from fifo buffer.
*/
void read_fifo_data(int16_t *x_fifo, int16_t *y_fifo, int16_t *z_fifo)
{
  ret_code_t err_code;
  uint8_t i;

  // arrays to hold 32 samples from output registers updated by FIFO buffer.
  uint8_t xL[32], xH[32], yL[32], yH[32], zL[32], zH[32];

  // arrays to hold lower and higher byte of each axis.
  int16_t x_val[32], y_val[32], z_val[32];

  // variable to store average data from each axis.
  int16_t x_avg, y_avg, z_avg;
  // collect 32 samples from output registers.
  for (i = 0; i < 32; i++)
  {
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_X_L, &xL[i], 1);
    APP_ERROR_CHECK(err_code);

    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_X_H, &xH[i], 1);
    APP_ERROR_CHECK(err_code);

    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_Y_L, &yL[i], 1);
    APP_ERROR_CHECK(err_code);

    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_Y_H, &yH[i], 1);
    APP_ERROR_CHECK(err_code);

    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_Z_L, &zL[i], 1);
    APP_ERROR_CHECK(err_code);

    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_Z_H, &zH[i], 1);
    APP_ERROR_CHECK(err_code);
  }

  // store the higher and lower byte data from each axis in a single variable.
  for (i = 0; i < 32; i++)
  {
    x_val[i] = (xH[i] << 8) | xL[i];
    y_val[i] = (yH[i] << 8) | yL[i];
    z_val[i] = (zH[i] << 8) | zL[i];

    // bit manipulation of left justified data.
    // x_val[i] = x_val[i] >> 6;
    // y_val[i] = y_val[i] >> 6;
    // z_val[i] = z_val[i] >> 6;

    // data from accelerometer is left justified by default. Bit manipulation for valid data.
    switch (settings.curr_mode)
    {
    case LIS2DH12_CURR_OP_MODE_LP: // 8-bit data
      x_val[i] = (x_val[i] >> 8);
      y_val[i] = (y_val[i] >> 8);
      z_val[i] = (z_val[i] >> 8);
      break;

    case LIS2DH12_CURR_OP_MODE_NRML: // 10-bit data
      x_val[i] = (x_val[i] >> 6);
      y_val[i] = (y_val[i] >> 6);
      z_val[i] = (z_val[i] >> 6);
      break;

    case LIS2DH12_CURR_OP_MODE_HR: // 12-bit data
      x_val[i] = (x_val[i] >> 4);
      y_val[i] = (y_val[i] >> 4);
      z_val[i] = (z_val[i] >> 4);
      break;
    }
  }

  // averaging the data along each axis.
  x_avg = 0;
  y_avg = 0;
  z_avg = 0;
  for (i = 0; i < 32; i++)
  {
    x_avg += x_val[i];
    y_avg += y_val[i];
    z_avg += z_val[i];
  }
  x_avg /= 32;
  y_avg /= 32;
  z_avg /= 32;

  *x_fifo = x_avg;
  *y_fifo = y_avg;
  *z_fifo = z_avg;
}

/*
 * function to configure STREAM mode and get data.
*/
void LIS2DH12_STREAM_mode_data(int16_t *x_value, int16_t *y_value, int16_t *z_value)
{
  ret_code_t err_code;
  int16_t x_data, y_data, z_data;
  uint8_t tx_data[2];
  uint8_t fifo_src_status = 0;

  // enable FIFO by setting FIFO_EN bit to 1 in CTRL_REG5
  //uint8_t tx_data[2] = {CTRL_REG5, 0x40};
  tx_data[0] = CTRL_REG5;
  tx_data[1] = 0x40;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // Activate FIFO mode
  LIS2DH12_set_STREAM_mode();

  // check for OVRN_FIFO
  do
  {
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, FIFO_SRC_REG, &fifo_src_status, sizeof(fifo_src_status));
    APP_ERROR_CHECK(err_code);
  } while (!(fifo_src_status && 0b01000000));

  // read data from output registers.
  read_fifo_data(&x_data, &y_data, &z_data);
  *x_value = x_data;
  *y_value = y_data;
  *z_value = z_data;

  // enable BYPASS mode to reset FIFO buffer
  LIS2DH12_set_BYPASS_mode();
}

/*
 * function to configure inertial wake-up detection.
*/
void LIS2DH12_inertial_wake_config(void)
{
  ret_code_t err_code;
  uint8_t tx_data[2];

  // disable High-Pass filter
  tx_data[0] = CTRL_REG2;
  tx_data[1] = 0x00;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // drive interrupt activity 1 to INT1 Pin
  tx_data[0] = CTRL_REG3;
  tx_data[1] = 0x40;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // latch INT1 Pin
  tx_data[0] = CTRL_REG5;
  tx_data[1] = 0x08;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // set INT1_THS register with a threshold value of 250mg
  tx_data[0] = INT1_THS;
  tx_data[1] = 0x10; // 0x14 for 250mg
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // set INT1_DURATION to 30ms i.e. ignore events shorter than 30ms.
  tx_data[0] = INT1_DURATION;
  tx_data[1] = 0x00;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // configure interrupt on X, Y axis
  tx_data[0] = INT1_CFG;
  tx_data[1] = 0x0A;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);
}

/*
 * function to check for inertial wake-up
*/
bool LIS2DH12_inertial_wake_detect(void)
{
  ret_code_t err_code;

  uint8_t rx_data;
  static bool inertial_wake_config_status = false;

  nrf_gpio_cfg_sense_input(INT1, NRF_GPIO_PIN_PULLDOWN, NRF_GPIO_PIN_SENSE_HIGH);

  if (inertial_wake_config_status == false)
  {
    LIS2DH12_inertial_wake_config();
    inertial_wake_config_status = true;
  }


  if (nrf_gpio_pin_read(INT1))
  {
    // Read INT1_SRC register to determine the source of interrupt.
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, INT1_SRC, &rx_data, sizeof(rx_data));
    APP_ERROR_CHECK(err_code);

#ifdef ENABLE_RTT_LOGGING
    NRF_LOG_RAW_INFO("INT1_SRC: %x\n", rx_data);
#endif

    return true;
  }
  return false;
}

/*
 *  Read (to clear) interrupt status register.
 */
uint8_t LIS2DH12_read_int_status()
{
  uint8_t status;
  uint32_t err_code;

  err_code = LIS2DH12_read_register(LIS2DH12_ADDR, INT1_SRC, &status, 
    sizeof(status));
  APP_ERROR_CHECK(err_code);

  return status;
}

/*
 * function to configure free-fall detection.
*/
void LIS2DH12_free_fall_config(void)
{
  ret_code_t err_code;
  uint8_t tx_data[2];

  // set LIS2DH12 in normal mode
  tx_data[0] = CTRL_REG1;
  tx_data[1] = 0x57;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // disable High-Pass filter
  tx_data[0] = CTRL_REG2;
  tx_data[1] = 0x00;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // drive interrupt activity 1 to INT1 Pin
  tx_data[0] = CTRL_REG3;
  tx_data[1] = 0x40;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // set measurement range as -2g to +2g
  tx_data[0] = CTRL_REG4;
  tx_data[1] = 0x00;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // latch INT1 Pin
  tx_data[0] = CTRL_REG5;
  tx_data[1] = 0x08;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // set INT1_THS register with a threshold value of 350mg
  tx_data[0] = INT1_THS;
  tx_data[1] = 0x16;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // set INT1_DURATION to 30ms i.e. ignore events shorter than 30ms.
  tx_data[0] = INT1_DURATION;
  tx_data[1] = 0x03;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // configure interrupt on X, Y and Z axis
  tx_data[0] = INT1_CFG;
  tx_data[1] = 0x95;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);
}

/*
 * function to enable 6D orientation detect functionality.
*/
void LIS2DH12_6D_config(void)
{
  ret_code_t err_code;
  uint8_t tx_data[2];

  // set LIS2DH12 in normal mode
  tx_data[0] = CTRL_REG1;
  tx_data[1] = 0x57;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // disable High-Pass filter
  tx_data[0] = CTRL_REG2;
  tx_data[1] = 0x00;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // drive interrupt activity 1 to INT1 Pin
  tx_data[0] = CTRL_REG3;
  tx_data[1] = 0x40;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // set measurement range as -2g to +2g
  tx_data[0] = CTRL_REG4;
  tx_data[1] = 0x00;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // latch INT1 Pin
  tx_data[0] = CTRL_REG5;
  tx_data[1] = 0x08;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // set INT1_THS register with a threshold value of 350mg
  tx_data[0] = INT1_THS;
  tx_data[1] = 0x20;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // set INT1_DURATION to 30ms i.e. ignore events shorter than 30ms.
  tx_data[0] = INT1_DURATION;
  tx_data[1] = 0x03;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);

  // configure interrupt on X, Y and Z axis
  tx_data[0] = INT1_CFG;
  tx_data[1] = 0xEA;
  err_code = nrf_drv_twi_tx(&m_twi_master, LIS2DH12_ADDR, tx_data, sizeof(tx_data), false);
  APP_ERROR_CHECK(err_code);
}

/*
 * function to read available accelerometer data
*/
void LIS2DH12_read_acc_data(int16_t *x_value, int16_t *y_value, int16_t *z_value)
{
  ret_code_t err_code;
  uint8_t xL, xH, yL, yH, zL, zH;
  int16_t x_val, y_val, z_val;
  uint8_t status = 0;

  // check if bit 3 in STATUS_REG is set. If true, new data available.
  do
  {
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, STATUS_REG, &status, sizeof(status));
    APP_ERROR_CHECK(err_code);
  } while (!(status && 0b00001000));

  // check if bit 7 in STATUS_REG is set. If true, read the latest data.
  if (status && 0b10000000)
  {
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_X_L, &xL, 1);
    APP_ERROR_CHECK(err_code);
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_X_H, &xH, 1);
    APP_ERROR_CHECK(err_code);
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_Y_L, &yL, 1);
    APP_ERROR_CHECK(err_code);
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_Y_H, &yH, 1);
    APP_ERROR_CHECK(err_code);
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_Z_L, &zL, 1);
    APP_ERROR_CHECK(err_code);
    err_code = LIS2DH12_read_register(LIS2DH12_ADDR, OUT_Z_H, &zH, 1);
    APP_ERROR_CHECK(err_code);
  }

  // combining OUT_X_L and OUT_X_H data in a single variable.
  x_val = (xH << 8) | xL;
  y_val = (yH << 8) | yL;
  z_val = (zH << 8) | zL;

  // data from accelerometer is left justified by default. Bit manipulation for valid data.
  switch (settings.curr_mode)
  {
  case LIS2DH12_CURR_OP_MODE_LP: // 8-bit data
    *x_value = (x_val >> 8);
    *y_value = (y_val >> 8);
    *z_value = (z_val >> 8);
    break;

  case LIS2DH12_CURR_OP_MODE_NRML: // 10-bit data
    *x_value = (x_val >> 6);
    *y_value = (y_val >> 6);
    *z_value = (z_val >> 6);
    break;

  case LIS2DH12_CURR_OP_MODE_HR: // 12-bit data
    *x_value = (x_val >> 4);
    *y_value = (y_val >> 4);
    *z_value = (z_val >> 4);
    break;
  }
}

/**
 * @brief function to convert ADC data to acceleromenter data in g.
 */
float get_accel_data_in_g(int16_t val)
{
  float factor_mg = 0.0f;

  switch (settings.full_scale)
  {
  case LIS2DH12_FS_2G: // Full scale = 2.0g
    switch (settings.curr_mode)
    {
    case LIS2DH12_CURR_OP_MODE_LP: // 8-bit
      factor_mg = 16;
      break;

    case LIS2DH12_CURR_OP_MODE_NRML: // 10-bit
      factor_mg = 4;
      break;

    case LIS2DH12_CURR_OP_MODE_HR: // 12-bit
      factor_mg = 1;
      break;
    }
    break;

  case LIS2DH12_FS_4G: // Full scale = 4.0g
    switch (settings.curr_mode)
    {
    case LIS2DH12_CURR_OP_MODE_LP: // 8-bit
      factor_mg = 32;
      break;

    case LIS2DH12_CURR_OP_MODE_NRML: // 10-bit
      factor_mg = 8;
      break;

    case LIS2DH12_CURR_OP_MODE_HR: // 12-bit
      factor_mg = 2;
      break;
    }
    break;

  case LIS2DH12_FS_8G: // Full scale = 8.0g
    switch (settings.curr_mode)
    {
    case LIS2DH12_CURR_OP_MODE_LP: // 8-bit
      factor_mg = 64;
      break;

    case LIS2DH12_CURR_OP_MODE_NRML: // 10-bit
      factor_mg = 16;
      break;

    case LIS2DH12_CURR_OP_MODE_HR: // 12-bit
      factor_mg = 4;
      break;
    }
    break;

  case LIS2DH12_FS_16G: // Full scale = 16.0g
    switch (settings.curr_mode)
    {
    case LIS2DH12_CURR_OP_MODE_LP: // 8-bit
      factor_mg = 192;
      break;

    case LIS2DH12_CURR_OP_MODE_NRML: // 10-bit
      factor_mg = 48;
      break;

    case LIS2DH12_CURR_OP_MODE_HR: // 12-bit
      factor_mg = 12;
      break;
    }
    break;
  }
#ifdef ENABLE_RTT_LOGGING
  NRF_LOG_RAW_INFO("Factor: %d\n", factor_mg);
#endif

  return (val * (factor_mg / 1000.0f)); // convert factor in mg to g and multiply by data.
}
