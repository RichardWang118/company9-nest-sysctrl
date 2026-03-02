#ifndef PORT_MAP_H
#define PORT_MAP_H

// INTERNAL
#define LED_ESP32_IO2           2
#define LED_ESP32_16            16

// INPUTS
#define START_BUTTON_PIN        13
#define PAUSE_BUTTON_PIN        14

#define HOPPER_JAM_PIN          27
#define FEEDER_JAM_PIN          26    
#define STACKER_JAM_PIN         25

#define QCM_READY_PIN           33
#define QCM_MODE_CYCLE          32
#define QCM_SELECT_MODE         35
#define FEEDER_ISOLATED_PIN     34 

#define STACKER_DONE_PIN        39

// OUTPUTS
#define BUZZER_PIN              12
#define SYSTEM_ENABLE_PIN       15  // Note that this will be replaced for individual subsystem enables
#define FEEDER_FEED_PIN         4
#define QCM_START_PIN           17
#define STACKER_PASS_FAIL_PIN   5
#define QCM_MODE_SELECT_0       18
#define QCM_MODE_SELECT_1       19

// // UART based
// #define QCM_JAM_PIN             
// #define QCM_READY_PIN           
// #define QCM_DONE_PIN            
// #define QCM_PASS_FAIL_PIN             
#endif