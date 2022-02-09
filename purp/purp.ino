#define FASTLED_HAS_CLOCKLESS 1
#include <FastLED.h>

#define NUM_LEDS 250
#define DATA_PIN 8

#define MIN_HUE 160
#define MAX_HUE 220

CRGB leds[NUM_LEDS];
uint8_t hue = MIN_HUE;
uint8_t dh = 1;

void setup() {
    FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
    FastLED.showColor(CHSV(hue+=dh, 255, 255));
    if (hue > MAX_HUE) dh = -1;
    if (hue < MIN_HUE) dh = 1;
    delay(1000);
}
