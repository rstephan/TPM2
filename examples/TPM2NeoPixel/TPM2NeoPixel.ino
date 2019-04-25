/**
 * TPM2 Example
 * with Adafruits NeoPixel library
 *
 * Copyright (c) 2019 Stephan Ruloff
 * https://github.com/rstephan/TPM2
 * 
 * GPL v2 only
 */
#include <Adafruit_NeoPixel.h>

#include "TPM2.h"

#define PIN 6
#define NO_OF_LEDS 8

uint8_t buffer[NO_OF_LEDS * 3];
TPM2 tpm2Driver(&Serial, buffer, sizeof(buffer));
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NO_OF_LEDS, PIN, NEO_GRB + NEO_KHZ800);


void CallbackRx(uint8_t* data, uint16_t len)
{
  uint16_t i, led;
  uint32_t c;

  for (i = 0, led = 0; i < len; i += 3, led++) {
    c = Adafruit_NeoPixel::Color(data[i], data[i + 1], data[i + 2]);
    strip.setPixelColor(led, c);
  }
  strip.show();
}

void setup()
{
  Serial.begin(115200);
  tpm2Driver.registerRxData(CallbackRx);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  tpm2Driver.update();
}
