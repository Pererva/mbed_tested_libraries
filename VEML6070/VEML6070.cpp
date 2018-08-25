/***************************************************
  This is a library for the VEML6070 UV-A Sensor

  Works with the VEML6070 sensor from Adafruit
  ----> https://www.adafruit.com/products/2899
  Or knock-off sensors from aliexpress

  These sensors use I2C to communicate, 2 pins are required to
  interface

  06/09/2017 - Initial mbed driver by Scott Roberts
 ****************************************************/

#include "VEML6070.h"
VEML6070::VEML6070 (I2C& p_i2c) : _i2c(p_i2c)
{

}

void VEML6070::begin(veml6070_integrationtime_t itime)
{
    _i2c.read((int)0x18,dt,1,false);
    dt[0]=((itime << 2) | 0x02);
    _i2c.write((int)VEML6070_ADDR_L,dt,2,false);
    wait(0.500);
}

uint16_t VEML6070::readUV()
{
    uint16_t uvi;
    _i2c.read(VEML6070_ADDR_H, dt,1);
    uvi = dt[0]<<8;
    _i2c.read(VEML6070_ADDR_L, dt,1,false);
    uvi |= dt[0];

    return uvi;
}

