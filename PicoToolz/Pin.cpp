//
// Created by nov11 on 2/6/2021.
//

#include "Pin.h"
#include <cstdint>
#include <cstdio>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/adc.h";

Pin::Pin(int number) {
    id = number;
    gpio_init(id);
}

Pin *Pin::delay_us(int value) {
    sleep_us(value);
    return this;
}

Pin *Pin::delay_ms(int value) {
    sleep_ms(value);
    return this;
}

Pin *Pin::digitalWrite(int value) {
    gpio_set_function(id, GPIO_FUNC_SIO);
    gpio_set_dir(id, GPIO_OUT);
    gpio_put(id, value);
    return this;
}

Pin *Pin::pull_down() {
    gpio_pull_down(id);
    return this;
}

Pin *Pin::pull_up() {
    gpio_pull_up(id);
    return this;
}

bool Pin::digitalRead() {
    gpio_set_function(id, GPIO_FUNC_SIO);
    gpio_set_dir(id, GPIO_IN);
    return (bool) gpio_get(id);
}

Pin *Pin::analogWrite(float value) {
    gpio_set_function(id, GPIO_FUNC_PWM);
    int ch = pwm_gpio_to_channel(id);
    int slice = pwm_gpio_to_slice_num(id);

    pwm_set_wrap(slice, 65535);
    pwm_set_chan_level(slice, ch, 65535*value);
    pwm_set_enabled(slice, true);
    return this;
}

Pin::~Pin() {
    // Destructor - do nothing
}

int Pin::analogRead() {
    if(id < 26 || id > 28) return -1;

    adc_init();
    adc_gpio_init(id);
    adc_select_input(id - 26);
    return adc_read();
}

float Pin::analogReadVoltage(float vref) {
    const float conversion_factor = vref / (1 << 12);
    return conversion_factor * (float) analogRead();
}
