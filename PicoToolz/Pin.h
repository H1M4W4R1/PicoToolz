//
// Created by nov11 on 2/6/2021.
//

#ifndef PIN_H
#define PIN_H


class Pin {
    int id;

public:
    Pin* digitalWrite(int value);
    bool digitalRead();

    Pin* analogWrite(float value);
    int analogRead();
    float analogReadVoltage(float vref = 3.3f);

    Pin* delay_ms(int value);
    Pin* delay_us(int value);
    Pin* pull_up();
    Pin* pull_down();

    explicit Pin(int number);
    ~Pin();
};


#endif //BLINKY_PIN_H
