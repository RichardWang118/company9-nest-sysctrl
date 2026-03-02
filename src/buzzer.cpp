#include <Arduino.h>
#include "PortMap.h"

void buzzerError() {
    for (int i = 0; i < 3; i++) {
        tone(BUZZER_PIN, 2000);
        delay(50);

        noTone(BUZZER_PIN);
        delay(100);
    }

    for (int i = 0; i < 3; i++) {
        tone(BUZZER_PIN, 1000);
        delay(200);

        noTone(BUZZER_PIN);
        delay(200);
    }

    for (int i = 0; i < 3; i++) {
        tone(BUZZER_PIN, 2000);
        delay(50);
        
        noTone(BUZZER_PIN);
        delay(100);
    }

    noTone(BUZZER_PIN);
}

void buzzerStartup() {
    tone(BUZZER_PIN, 500);
    delay(200);

    tone(BUZZER_PIN, 1000);
    delay(200);

    noTone(BUZZER_PIN);
}

void buzzerPass() {
    tone(BUZZER_PIN, 1500);
    delay(200);

    noTone(BUZZER_PIN);
}

void buzzerFail() {
    tone(BUZZER_PIN, 500);
    delay(200);

    noTone(BUZZER_PIN);
    delay(50);
        
    tone(BUZZER_PIN, 500);
    delay(200);

    noTone(BUZZER_PIN);
}