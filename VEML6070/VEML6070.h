/***************************************************
  This is a library for the VEML6070 UV-A Sensor

  Works with the VEML6070 sensor from Adafruit
  ----> https://www.adafruit.com/products/2899
  Or knock-off sensors from aliexpress

  These sensors use I2C to communicate, 2 pins are required to
  interface

  The VEML6070 is capable of alerting when UV levels rise past a pre-set level.
  It uses a "ACK" pin, and the SMBus Alert Response Address must be read to 
  clear the alert.
  If alert is turned on, you must clear the alert bit before you read/write the
  sensor.

  06/09/2017 - Initial mbed driver by Scott Roberts
 ****************************************************/


#ifndef VEML6070_H
#define VEML6070_H

#include "mbed.h"

// To get data, you read from two different addresses!
#define VEML6070_ADDR_H     (0x39) // < High address
#define VEML6070_ADDR_L     (0x38) // < Low address
#define VEML6070_ADDR_ARA   (0x0C) // < Alert Response Address (read to clear condition)


// Four different integration times
typedef enum veml6070_integrationtime {
    VEML6070_HALF_T,    // ~ 62.5 ms
    VEML6070_1_T,       // ~ 125  ms
    VEML6070_2_T,       // ~ 250  ms
    VEML6070_4_T,       // ~ 500  ms
} veml6070_integrationtime_t;


class VEML6070 {
    public:
        VEML6070(I2C& p_i2c);
        void begin(veml6070_integrationtime_t itime);
        uint16_t readUV(void);
    protected:
        I2C  _i2c;
    private:
        char dt[2];
};
#endif
