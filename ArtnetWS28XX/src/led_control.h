/**
 * @file led_control.h
 * @author Tristan Traver
 * @date 2024-11-11
 */

// Include guards
#ifndef LED_CONTROL_H
#define LED_CONTROL_H

////////////////////////////////////////////////////////////////////////////////
// Application includes
#include <Adafruit_NeoPixel.h>

////////////////////////////////////////////////////////////////////////////////
// Constants
#define LEDS_STRIP1 8 // Number of leds per strip
#define DATA_PIN1 8 // GPIO 8 on ESP32C6

////////////////////////////////////////////////////////////////////////////////
// Public functions
void initLEDs();
void updateLEDsFromDMX(uint8_t* data, uint16_t length);

#endif // LED_CONTROL_H