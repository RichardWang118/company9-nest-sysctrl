#include <Arduino.h>
#include <FastLED.h>

#include "PortMap.h"

CRGB leds[1];

void initializePins() {
    // initialize inputs
    pinMode(START_BUTTON_PIN, INPUT_PULLUP);
    pinMode(PAUSE_BUTTON_PIN, INPUT_PULLUP);

    pinMode(HOPPER_JAM_PIN, INPUT_PULLUP);
    pinMode(FEEDER_JAM_PIN, INPUT_PULLUP);
    pinMode(STACKER_JAM_PIN, INPUT_PULLUP);

    pinMode(QCM_READY_PIN, INPUT_PULLUP);      
    pinMode(QCM_MODE_CYCLE, INPUT_PULLUP);       
    pinMode(QCM_SELECT_MODE, INPUT);            // input only gpio lmao    
    pinMode(FEEDER_ISOLATED_PIN, INPUT);        // input only gpio lmao    

    pinMode(STACKER_DONE_PIN, INPUT);           // input only gpio lmao   

    // initialize outputs
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SYSTEM_ENABLE_PIN, OUTPUT);
    pinMode(FEEDER_FEED_PIN, OUTPUT);
    pinMode(QCM_START_PIN, OUTPUT);
    pinMode(STACKER_PASS_FAIL_PIN, OUTPUT);
    pinMode(QCM_MODE_SELECT_0, OUTPUT);
    pinMode(QCM_MODE_SELECT_1, OUTPUT);

    // initialize output state to prevent undefined states
    noTone(BUZZER_PIN);
    digitalWrite(SYSTEM_ENABLE_PIN, LOW);
    digitalWrite(FEEDER_FEED_PIN, LOW);       
    digitalWrite(QCM_START_PIN, LOW);         
    digitalWrite(STACKER_PASS_FAIL_PIN, LOW); 
    digitalWrite(QCM_MODE_SELECT_0, LOW);     
    digitalWrite(QCM_MODE_SELECT_1, LOW); 
}

void initializeLEDs() {
    FastLED.addLeds<WS2812, LED_ESP32_16, GRB>(leds, 1);
    FastLED.setBrightness(35);
    leds[0] = CRGB::Black;
    FastLED.show();

    digitalWrite(LED_ESP32_IO2, LOW);
}