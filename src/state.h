#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include "PortMap.h"

// System states
enum SystemState {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_PAUSED,
    STATE_FAULT
};

// Fault codes
enum FaultCode {
    FAULT_NONE,
    FAULT_FEEDER_TIMEOUT,
    FAULT_QCM_TIMEOUT,
    FAULT_SUBSYSTEM_JAM
};

// Function prototypes
SystemState getCurrentState();
void enterFault(FaultCode fault);
void clearFault();
void commandFeeder();
void commandQCM();
void routeBirdie(bool pass);
void checkTimeouts();
void handleIdleState();
void handleRunningState();
void handlePausedState();
void handleFaultState();

// External variables
extern SystemState currentState;
extern SystemState lastState;
extern FaultCode currentFault;

#endif