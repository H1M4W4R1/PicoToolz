//
// Created by Patryk Pastuszka on 2/3/2021.
//
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "arduino.h"

int isAdcInitialized = 0;

int digitalRead(int pin)
{
    return gpio_get(pin);
}

void digitalWrite(int pin, int value)
{
    gpio_put(pin, value);
}

void pinMode(int pin, int mode)
{
    gpio_init(pin);
    gpio_set_dir(pin, mode);
    if(mode == 2 || mode == 4)
        gpio_pull_up(pin);
    if(mode == 3 || mode == 5)
        gpio_pull_down(pin);
}

// Value: [0, 4096]
void analogWrite(int pin, int value)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    uint channel = pwm_gpio_to_channel(pin);

    pwm_set_chan_level(slice_num, channel, value);
    pwm_set_enabled(slice_num, true);
}

void analogSetResolution(int pin, int resolution)
{
    uint slice_num = pwm_gpio_to_slice_num(pin);
    uint channel = pwm_gpio_to_channel(pin);

    pwm_set_wrap(slice_num, resolution);
}

int analogRead(int pin)
{
    if(!isAdcInitialized) {
        adc_init();
        isAdcInitialized = true;
    }

    int adc_pin = -1;
    switch(pin)
    {
        case 26:
            adc_pin = 0;
            break;
        case 27:
            adc_pin = 1;
            break;
        case 29:
            adc_pin = 2;
            break;
    }

   adc_gpio_init(pin);
   adc_select_input(adc_pin);

   return adc_read();
}

// Utility

void delay(int time)
{
    sleep_ms(time);
}

void delayMicroseconds(int time)
{
    sleep_us(time);
}

int bit(int n)
{
    int val = 1;
    for(int a = 0; a < n; a++){
        val *= 2;
    }
    return val;
}

int bitSet(int x, int n)
{
    return x | 1 << n;
}

int bitClear(int x, int n)
{
    return x & ~(1 << n);
}

int bitRead(int x, int n)
{
    return x & 1 << n;
}

int bitWrite(int x, int n, int v)
{
    switch(v){
        case 0:
            bitClear(x, n);
            break;
        case 1:
            bitSet(x, n);
            break;
    }
}

byte highByte(word w)
{
    return (byte)(w >> 8);
}

byte lowByte(word w)
{
    return (byte)(w & 255);
}

int constrain(int x, int a, int b)
{
    if(x < a) return a;
    if(x > b) return b;
    return x;
}

int map(int value, int fromLow, int fromHigh, int toLow, int toHigh)
{
    float reference = (float)(value - fromLow) / (float)(fromHigh - fromLow);
    float offset = reference * ((float)toHigh - (float)toLow);
    return toLow + (int)offset;
}

int sq(int a)
{
    return a*a;
}

void shiftOut(int dataPin, int clockPin, int bitOrder, int value)
{
    digitalWrite(clockPin, 0);
    delayMicroseconds(SHIFT_DELAY_US);
    for (int q = 0; q < 8; q++) {
        if(bitOrder == MSB_FIRST) {
            digitalWrite(dataPin, value & 1 << (7-q));
        }
        else
        {
            // LSB FIRST
            digitalWrite(dataPin, value && 1 << q);
        }

        // Send CLK signal
        digitalWrite(clockPin, 1);
        delayMicroseconds(SHIFT_DELAY_US);
        digitalWrite(clockPin, 0);
        delayMicroseconds(SHIFT_DELAY_US);
    }
}