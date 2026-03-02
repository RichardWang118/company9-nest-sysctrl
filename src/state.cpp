#include <Arduino.h>
#include "PortMap.h"
#include "setup.h"
#include "buzzer.h"
#include "led.h"
#include "state.h" 

const unsigned long FEEDER_TIMEOUT_MS = 5000;
const unsigned long QCM_TIMEOUT_MS    = 10000;
unsigned long feederCommandTime = 0;
unsigned long qcmCommandTime = 0;

SystemState currentState = STATE_IDLE;
SystemState lastState = STATE_IDLE;
FaultCode currentFault = FAULT_NONE;

SystemState getCurrentState() {
    return currentState;
}

void enterFault(FaultCode fault) {
    currentFault = fault;
    currentState = STATE_FAULT;

    digitalWrite(SYSTEM_ENABLE_PIN, LOW);
    digitalWrite(FEEDER_FEED_PIN, LOW);       
    digitalWrite(QCM_START_PIN, LOW);         
    digitalWrite(STACKER_PASS_FAIL_PIN, LOW); 

    Serial.print("FAULT ENTERED: ");
    Serial.println(fault);
}

void clearFault() {
    currentFault = FAULT_NONE;
    currentState = STATE_IDLE;
}

void commandFeeder() {
    digitalWrite(FEEDER_FEED_PIN, HIGH);
    feederCommandTime = millis();
}

void commandQCM() {
    digitalWrite(QCM_START_PIN, HIGH);
    qcmCommandTime = millis();
}

// void routeBirdie(bool pass) {
//     if (pass)
// }

void checkTimeouts() {
    if (digitalRead(FEEDER_FEED_PIN) == HIGH &&
        millis() - feederCommandTime > FEEDER_TIMEOUT_MS) {
        enterFault(FAULT_FEEDER_TIMEOUT);
    }

    if (digitalRead(QCM_START_PIN) == HIGH &&
        millis() - qcmCommandTime > QCM_TIMEOUT_MS) {
        enterFault(FAULT_QCM_TIMEOUT);
    }
}

void handleIdleState() {
    if (!digitalRead(START_BUTTON_PIN)) {
        digitalWrite(SYSTEM_ENABLE_PIN, HIGH);
        currentState = STATE_RUNNING;
    }
}

void handleRunningState() {
    if (!digitalRead(START_BUTTON_PIN)) {
        digitalWrite(FEEDER_FEED_PIN, LOW);
    }

    if (!digitalRead(FEEDER_ISOLATED_PIN) && !digitalRead(QCM_READY_PIN)) {
        commandFeeder();
        commandQCM();
    }

    // if (digitalRead(STACKER_DONE_PIN)) {
    //     bool pass = digitalRead();
    //     routeBirdie(pass);
    // }

    if (!digitalRead(PAUSE_BUTTON_PIN)) {
        currentState = STATE_PAUSED;
    }

    if (!digitalRead(HOPPER_JAM_PIN) || !digitalRead(FEEDER_JAM_PIN) || !digitalRead(STACKER_JAM_PIN)) {
        enterFault(FAULT_SUBSYSTEM_JAM);
    }
}

void handlePausedState() {
    if (!digitalRead(PAUSE_BUTTON_PIN)) {
        currentState = STATE_RUNNING;
    }
}

void handleFaultState() {
    if (!digitalRead(START_BUTTON_PIN)) {
        clearFault();
    }
}