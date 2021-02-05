//
// Created by nov11 on 2/3/2021.
//

#include <hardware/gpio.h>
#include <cstdlib>
#include <cstdio>
#include "UART.h"
#include "hardware/uart.h"


UART::UART(uart_inst_t *iface, int tx, int rx) {
    interface = iface;
    txPin = tx;
    rxPin = rx;
}

UART* UART::begin(uint32_t baudRate, uint8_t dataBits, uint8_t stopBits, uart_parity_t parity) {
    // Initialize UART
    gpio_set_dir(txPin, GPIO_OUT);
    gpio_set_dir(rxPin, GPIO_IN);
    gpio_set_function(txPin, GPIO_FUNC_UART);
    gpio_set_function(rxPin, GPIO_FUNC_UART);
    uart_set_format(interface, dataBits, stopBits, parity);

    // Init UART
    uart_init(interface, baudRate);
    return this;
}

UART* UART::end() {
    uart_deinit(interface);
    return this;
}

uint32_t UART::available() {
    return uart_is_readable(interface);
}

bool UART::availableToWrite() {
    return uart_is_writable(interface);
}

UART* UART::write(char *text) {
    uart_puts(interface, text);
    return this;
}


UART* UART::write(long num, uint8_t base) {
    char tab[16];
    itoa(num, tab, base);
    write(tab);
    return this;
}


UART* UART::write(double num) {
    char tab[16];
    sprintf(tab, "%f", num);
    write(tab);
    return this;
}

UART* UART::write(float num) {
    char tab[16];
    sprintf(tab, "%f", num);
    write(tab);
    return this;
}

UART* UART::eol() {
    write((char*)EOL);
    return this;
}

UART* UART::crlf() {
    write((char*) CRLF);
    return this;
}

UART* UART::lf() {
    write((char*) LF);
    return this;
}

bool UART::setPins(uint8_t rx, uint8_t tx) {
    if(initialized)
        return false;

    rxPin = rx;
    txPin = tx;
    return true;
}

uint8_t singleReadBuffer[1];
uint8_t UART::read() {
    uart_read_blocking(interface, singleReadBuffer, 1);
    return singleReadBuffer[0];
}

UART* UART::read(uint8_t *buffer, uint length) {
    uart_read_blocking(interface, buffer, length);
    return this;
}

UART* UART::write(uint8_t* bytes) {
    write((char*) bytes);
    return this;
}

UART Serial1(uart0, 0, 1);
UART Serial2(uart1, 6, 7);



