#define FASTLED_HAS_CLOCKLESS 1
#include <FastLED.h>

#define NUM_LEDS 250
#define DATA_PIN 6

#define HUE 180
#define DELAY_MS 20

CRGB leds[NUM_LEDS];
uint8_t saturations[NUM_LEDS];
uint8_t ds[NUM_LEDS];
uint8_t new_saturation;

void setup() {
    FastLED.addLeds<WS2812, DATA_PIN>(leds, NUM_LEDS);
    for (int i = 0; i < NUM_LEDS; i++) {
        // saturations[i] = random(256);
        saturations[i] = 100;
        ds[i] = random(-3, 4);
        // ds[i] = -3;
    }
}

void loop() {
    for (int i = 0; i < NUM_LEDS; i++) {
        new_saturation = saturations[i] + ds[i];
        // if (saturations[i] > 254 || saturations[i] < 1) ds[i] *= -1;
        if (new_saturation > 240) {
            new_saturation = 240;
            ds[i] *= -1;
        }
        else if (new_saturation < 20) {
            new_saturation = 20;
            ds[i] *= -1;
        }
        saturations[i] = new_saturation;
        leds[i] = CHSV(HUE, new_saturation, 255);
    }
    FastLED.show();
    delay(DELAY_MS);
}
