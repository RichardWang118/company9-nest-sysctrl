#ifndef LED_H
#define LED_H

#include <FastLED.h>
#include "state.h"

void ledState(SystemState state);
void ledChange(CRGB color, CRGB led);

#endif