#include <Arduino.h>

#include "setup.h"
#include "state.h"
#include "led.h"
#include "buzzer.h"

void setup() {
    Serial.begin(9600);
    initializePins();
    initializeLEDs();

    // initialize to idle 
    ledState(STATE_IDLE);
    buzzerStartup();
}

void loop() {
    checkTimeouts();
    
    // Only update LED when the state changes
    if (currentState != lastState) {
        ledState(currentState);  // Update LED when state changes
        lastState = currentState;  // Save the new state
        if (currentState == STATE_FAULT) {
            buzzerError();
        } else if (currentState == STATE_RUNNING) {
            buzzerPass(); // temp
        }
    }

    switch (getCurrentState()) {

        case STATE_IDLE:
            handleIdleState();
            break;

        case STATE_RUNNING:
            handleRunningState();
            break;

        case STATE_PAUSED:
            handlePausedState();
            break;

        case STATE_FAULT:
            handleFaultState();
            break;
    }
}