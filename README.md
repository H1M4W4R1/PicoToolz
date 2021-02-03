# PicoDuino
Arduino-style API for Raspberry Pi Pico

# What is supported?
- Digital IO
- Analog IO (not tested)
- Bit API
- Partial Math API (excluding API that is implemented in cmath)
- Delay API (us, ms)

# To Be Implemented
- SPI
- UART
- I2C
- Character API
- Random Generator API
- Tone API
- Interrupt API
- Shift / Pulse API

# How to use?
1. Create new Raspberry Pi Pico Project
2. Paste arduino.c and arduino.h into your project (or link as library)
3. In your project add those code
```c
#include "pico/stdlib.h"
#include "sketch.h"

int main() {
    stdio_init_all();
    setup();


    while(true)
    {
        loop();
    }
}
```
4. Create sketch.h and paste:
```c
#ifndef SKETCH_H
#define SKETCH_H

void setup();
void loop();

#endif
```
5. Create sketch.c and paste:
```c
#include "arduino.h"

void setup()
{
}

void loop()
{
}
```
6. Don't forget to fix CMake files :)
