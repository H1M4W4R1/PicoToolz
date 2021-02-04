# PicoToolz
PicoToolz is a package of C++ classes that makes life easier - it consists of
- UART class to manage Serial connections
- I2C class to manage I2C connections

Planned:
- SPI class to manage SPI connections
- GPIO class to manage GPIO

# UART
Supported methods:
- `UART begin(uint32_t baudRate = DEFAULT_BAUD_RATE, uint8_t dataBits = DATA_BITS_8, uint8_t stopBits = STOP_BITS_1, uart_parity_t parity = UART_PARITY_NONE)` - begins UART communication over specified UART definition
- `UART end()` - ends UART communication
- `bool available()` - checks if data is available
- `bool availableToWrite()` - checks if can write UART data
- `uint8_t read()` - reads byte
- `UART read(uint8_t* buffer, uint length)` - reads specified amount of data to buffer
- `UART write(uint8_t* bytes)` - writes binary data to UART
- `UART write(char* text)` - writes string data to UART
- `UART write(long num, uint8_t base)` - writes integer to UART at specified base (BIN, OCT, DEC, HEX)
- `UART write(double num)` - writes double to UART
- `UART write(float num)` - writes float to UART
- `UART eol()` - writes EOL to UART (default CRLF)
- `UART crlf()` - writes CR LF to UART
- `UART lf()` writes LF to UART
- `bool setPins(uint8_t rx, uint8_t tx)` - sets UART pins. Needs to be used before begin()  
By default Serial1 uses 0/1 pins and Serial2 uses 6/7 pins

# I2C
Supported methods:
- `I2C begin(uint32_t baudRate = I2C_DEFAULT_BAUD_RATE)` - begins I2C communication at specified BaudRate
- `I2C end()` - ends I2C communication
- `I2C write(uint8_t* data, size_t len)` - writes binary data to I2C
- `I2C write(uint8_t* data, size_t len, uint8_t addr)` - writes binary data to I2C at specified address
- `int read(uint8_t* data, size_t len)` - reads data from I2C
- `int read(uint8_t* data, size_t len, uint8_t addr)` - reads data from I2C at specified address
- `I2C enslave(uint8_t addr)` - switches I2C port to Slave mode
- `I2C free()` - switches I2C port to Master mode
- `I2C setBaudRate(uint32_t newBaudRate)` - changes I2C Baud Rate
- `I2C setPins(uint8_t sda, uint8_t scl)` - sets I2C pins. Needs to be used before begin() 
- `I2C setAddresS(uint8_t addr)` - sets address inside class to be used with read and write commands.  
By default I2C1 uses 9/10 pins and I2C2 uses 11/12 pins.

# Why it returns I2C / UART objects?
It's due to fluent design of classes. It allows you to create code like this:
```cpp
Serial.write((char*) "Hello world!").crlf().write((char*) "It's a great feature").crlf();
```
       
