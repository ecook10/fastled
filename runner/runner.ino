#include <FastLED.h>

#define NUM_LEDS 200
#define DATA_PIN 8

#define HUE 220
#define RUNNER_LENGTH 10

CRGB leds[NUM_LEDS];
uint8_t runner_start = 0;

CRGB color = CHSV(HUE, 255, 255);

void setup() {
    FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
    for (uint8_t i = 0; i < RUNNER_LENGTH; i++) {
        leds[i] = color;
    }
}

void loop() {
    FastLED.show();

    runner_start = (runner_start += 1) % NUM_LEDS;
    uint8_t runner_end = (runner_start + RUNNER_LENGTH - 1) % NUM_LEDS;

    leds[runner_start] = CRGB::Black;
    leds[runner_end] = color;

    // delay(100);
}
