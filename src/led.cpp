#include <Arduino.h>
#include <FastLED.h>
#include "PortMap.h"
#include "state.h"
#include "setup.h"

extern CRGB leds[1];

void ledChange(CRGB color, CRGB& led) {
    for (int i = 0; i < 2; i++) {
        led = color;
        FastLED.show();
        delay(200);
        
        led = CRGB::Black;
        FastLED.show();
        delay(200);
    }

    led = color; 
    FastLED.show();
}

void ledState(SystemState state) {
    switch (state) {
        case STATE_IDLE:
            ledChange(CRGB::Blue, leds[0]);
            break;

        case STATE_RUNNING:
            ledChange(CRGB::Green, leds[0]);
            break;

        case STATE_PAUSED:
            ledChange(CRGB::Yellow, leds[0]);   
            break;

        case STATE_FAULT:
            ledChange(CRGB::Red, leds[0]);   
            break;
    }
}
