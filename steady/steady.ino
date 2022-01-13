#define FASTLED_HAS_CLOCKLESS 1
#include <FastLED.h>

#define NUM_LEDS_A 250
#define NUM_LEDS_B 50
#define NUM_LEDS_C 100

#define DATA_PIN_A 6
#define DATA_PIN_B 8
#define DATA_PIN_C 10

CRGB ledsA[NUM_LEDS_A];
// CRGB ledsB[NUM_LEDS_B];
// CRGB ledsC[NUM_LEDS_C];

uint8_t hue = 30;

void setup() {
    FastLED.addLeds<WS2812, DATA_PIN_A>(ledsA, NUM_LEDS_A);
    // FastLED.addLeds<WS2811, DATA_PIN_B>(ledsB, NUM_LEDS_B);
    // FastLED.addLeds<WS2811, DATA_PIN_C>(ledsC, NUM_LEDS_C);
    // FastLED.showColor(CHSV(hue, 255, 255));
}

void loop() {
    hue = (hue += 1) % 256;
    FastLED.showColor(CHSV(hue, 255, 255));
    // FastLED.showColor(CRGB::Purple);
    delay(500);
}
