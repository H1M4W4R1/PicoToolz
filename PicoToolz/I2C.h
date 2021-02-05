//
// Created by nov11 on 2/3/2021.
//

#ifndef I2C_H
#define I2C_H

#define I2C_DEFAULT_BAUD_RATE 100000

#include <cstdint>
#include <cstdio>
#include "hardware/i2c.h"

class I2C {
    int sdaPin;
    int sclPin;
    i2c_inst_t *interface;
    uint8_t address;
    uint32_t baudRate = I2C_DEFAULT_BAUD_RATE;
public:
    bool noStop = false;

    I2C(i2c_inst_t *iface, int sda, int scl);

    I2C *begin(uint32_t baudRate = I2C_DEFAULT_BAUD_RATE);

    I2C *end();

    I2C *write(uint8_t *data, size_t len);

    I2C *write(uint8_t *data, size_t len, uint8_t addr);

    int read(uint8_t *data, size_t len);

    int read(uint8_t *data, size_t len, uint8_t addr);

    I2C *enslave(uint8_t addr);

    I2C *free();

    I2C *setBaudRate(uint32_t newBaudRate);

    I2C *setAddress(uint8_t addr);

    I2C *setPins(uint8_t sda, uint8_t scl);
};


#endif
