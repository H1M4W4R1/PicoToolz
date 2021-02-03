//
// Created by nov11 on 2/3/2021.
//

#include <hardware/gpio.h>
#include "I2C.h"
I2C I2C::write(uint8_t *data, size_t len, uint8_t addr) {
    i2c_write_blocking(interface, addr, data, len, noStop);
    return *this;
}

int I2C::read(uint8_t *data, size_t len) {
    return read(data, len, address);
}

I2C I2C::write(uint8_t *data, size_t len) {
    return write(data, len, address);
}

int I2C::read(uint8_t *data, size_t len, uint8_t addr) {
    return i2c_read_blocking(interface, addr, data, len, noStop);
}

I2C I2C::free() {
    i2c_set_slave_mode(interface, false, 0x0);
    return *this;
}

I2C I2C::enslave(uint8_t addr) {
    this->address = addr;
    i2c_set_slave_mode(interface, true, addr);
    return *this;
}

I2C I2C::setBaudRate(uint32_t newBaudRate) {
    baudRate = newBaudRate;
    return *this;
}

I2C I2C::begin(uint32_t baudRate) {
    gpio_set_function(sdaPin, GPIO_FUNC_I2C);
    gpio_set_function(sclPin, GPIO_FUNC_I2C);
    gpio_pull_up(sdaPin);
    gpio_pull_up(sclPin);

    i2c_init(interface, baudRate);
    return *this;
}

I2C I2C::end() {
    i2c_deinit(interface);
    gpio_disable_pulls(sdaPin);
    gpio_disable_pulls(sclPin);
    return *this;
}

I2C::I2C(i2c_inst_t *iface, int sda, int scl) {
    interface = iface;
    sdaPin = sda;
    sclPin = scl;
}

I2C I2C::setPins(uint8_t sda, uint8_t scl) {
    sdaPin = sda;
    sclPin = scl;
    return *this;
}

I2C I2C1(i2c1, 9, 10);
I2C I2C2(i2c0, 11, 12);

