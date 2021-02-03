//
// Created by Patryk Pastuszka on 2/3/2021.
//


#ifndef ARDUINO_H
#define ARDUINO_H

#include <inttypes.h>

#define HIGH 1
#define LOW 0

#define INPUT 0
#define OUTPUT 1
#define INPUT_PULL_UP 2
#define INPUT_PULL_DOWN 3
#define OUTPUT_PULL_UP 4
#define OUTPUT_PULL_DOWN 5
#define LED_BUILTIN 25
#define true 1
#define false 0
#define byte uint8_t
#define word uint16_t

#define MSB_FIRST 0
#define LSB_FIRST 1

#define SHIFT_DELAY_US 25

// Digital
int digitalRead(int pin);
void digitalWrite(int pin, int value);
void pinMode(int pin, int mode);

// Analog
void analogSetResolution(int pin, int resolution);
void analogWrite(int pin, int value);
int analogRead(int pin);

void delay(int time);
void delayMicroseconds(int time);

int bit(int n);
int bitSet(int x, int n);
int bitClear(int x, int n);
int bitRead(int x, int n);
int bitWrite(int x, int n, int v);
byte highByte(word w);
byte lowByte(word w);

// Math
int constrain(int x, int a, int b);
int map(int value, int fromLow, int fromHigh, int toLow, int toHigh);
int sq(int a);

// Tools
void shiftOut(int dataPin, int clockPin, int bitOrder , int value);

// Not supported - to be implemented shortly
int shiftIn(int dataPin, int clockPin, int bitOrder);
void pulseIn(int pin, int value);
void pulseInLong(int pin, int value);
void pulseInTimeout(int pin, int value, int timeout);
void pulseInLongTimeout(int pin, int value, int timeout);

// Not supported (yet)
void noTone(int pin);
void tone(int pin, int freq);
void toneWithDuration(int pin, int freq, int duration);

int micros();
int millis();

//int random();
//int random(int max);
//int random(int min, int max);
void randomSeed(int seed);

// Implemented in <cmath>
//int max(int a, int b);
//int min(int a, int b);
//int pow(int a, int p);
//int sqrt(int a);
//float cos(float a);
//float sin(float a);
//float tan(float a);

int isAlpha(char c);
int isAlphaNumeric(char c);
int isAscii(char c);
int isControl(char c);
int isDigit(char c);
int isGraph(char c);
int isHexadecimalDigit(char c);
int isLowerCase(char c);
int isPrintable(char c);
int isPunct(char c);
int isSpace(char c);
int isUpperCase(char c);
int isWhitespace(char c);

// Complex to implement
// attachInterrupt()
// detachInterrupt()
// interrupts()
// noInterrupts()

// SPI
// UART
// I2C

#endif