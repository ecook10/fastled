#define FASTLED_HAS_CLOCKLESS 1
#include <FastLED.h>

#define NUM_LEDS 250
#define DATA_OUT_PIN 8
#define ANALOG_IN_PIN 0

#define MIN_HUE 160
#define MAX_HUE 220

#define MIN_INPUT 1024
#define MAX_INPUT 1024

CRGB leds[NUM_LEDS];

int inputValue;
int currHue = 0;
int newHue;
int hueDelta;
char buffer[30];

void setup() {
    Serial.begin(9600);
    Serial.println("Hello");
    FastLED.addLeds<WS2811, DATA_OUT_PIN>(leds, NUM_LEDS);
}

void loop() {
    inputValue = analogRead(ANALOG_IN_PIN);
    newHue = inputValue / 4 % 256;

    // a bit of extra logic to prevent input "wiggles" causing the hue to flicker

    // if the last loop and this one both change the hue, update the hue
    if (hueDelta > 0 && newHue != currHue) {
        currHue = newHue;
    }
    // else if the last loop did _not_ change the hue but this one only changes it by one,
    //  do not change the hue
    hueDelta = abs(currHue - newHue);
    if (hueDelta <= 1) {
        hueDelta = 0;
    } else {
        currHue = newHue;
    }

    sprintf(buffer, "Input: %u - Transformed: %u", inputValue, currHue);
    Serial.println(buffer);

    FastLED.showColor(CHSV(currHue, 255, 255));

    // delay(1000);
}