/**
 * @file led_control.cpp
 * @author Tristan Traver
 * @date 2024-11-11
 */

////////////////////////////////////////////////////////////////////////////////
// System includes
#include "led_control.h"

////////////////////////////////////////////////////////////////////////////////
// Public functions
Adafruit_NeoPixel strip1(LEDS_STRIP1, DATA_PIN1, NEO_GRB + NEO_KHZ800);

////////////////////////////////////////////////////////////////////////////////
// Private functions
//------------------------------------------------------------------------------
void initLEDs()
//------------------------------------------------------------------------------
{
    strip1.begin();
    strip1.show();
}

//------------------------------------------------------------------------------
void updateLEDsFromDMX(uint8_t* data, uint16_t length)
//------------------------------------------------------------------------------
{
    for (int i = 0; i < LEDS_STRIP1; i++) {
        int ledIndex = i * 3;
        if (ledIndex + 2 < length) {
            uint8_t r = data[ledIndex];
            uint8_t g = data[ledIndex + 1];
            uint8_t b = data[ledIndex + 2];
            strip1.setPixelColor(i, strip1.Color(r, g, b));
        }
    }
    strip1.show();
}