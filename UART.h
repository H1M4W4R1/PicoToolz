//
// Created by nov11 on 2/3/2021.
//

#ifndef UART_H
#define UART_H

#include <cstdint>
#include "hardware/uart.h"

#define CRLF "\r\n"
#define LF "\n"
#define EOL CRLF

#define DATA_BITS_5 5
#define DATA_BITS_6 6
#define DATA_BITS_7 7
#define DATA_BITS_8 8
#define DATA_BITS_16 16

#define STOP_BITS_1 1
#define STOP_BITS_2 2

#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16

#define DEFAULT_BAUD_RATE 115200

class UART {
public:
    bool initialized = false;
    uint8_t txPin;
    uint8_t rxPin;
    uart_inst_t* interface;
    UART begin(uint32_t baudRate = DEFAULT_BAUD_RATE, uint8_t dataBits = DATA_BITS_8, uint8_t stopBits = STOP_BITS_1,
               uart_parity_t parity = UART_PARITY_NONE);
    UART end();
    uint32_t available();
    bool availableToWrite();

    uint8_t read();
    UART read(uint8_t* buffer, uint length);
    UART write(uint8_t* bytes);
    UART write(char* text);
    UART write(long num, uint8_t base);
    UART write(double num);
    UART write(float num);
    UART eol();
    UART crlf();
    UART lf();
    bool setPins(uint8_t rx, uint8_t tx);


    explicit UART(uart_inst_t* iface, int tx, int rx);
};

extern UART Serial1;
extern UART Serial2;

#endif
