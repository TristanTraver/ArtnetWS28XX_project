/**
 * @file ArtnetWS2811.ino
 * @author Tristan Traver
 * @brief The code controls a WS28XX LED strip over WiFi using the Art-Net protocol for DMX colors.
 * @version 1.0
 * @date 2024-11-11
 */

////////////////////////////////////////////////////////////////////////////////
// Application includes
#include "src/wifi_manager.h"
#include "src/artnet_handler.h"
#include "src/led_control.h"

////////////////////////////////////////////////////////////////////////////////
// Private functions
//------------------------------------------------------------------------------
void setup()
//------------------------------------------------------------------------------
{
    Serial.begin(115200);

    // Initialize LED
    initLEDs();

    // Start wifi management
    if (!setupWiFi()) {
        startAccessPoint();
    } else {
        startArtnet();
    }
}

// Main loop
//------------------------------------------------------------------------------
void loop()
//------------------------------------------------------------------------------
{
    handleWiFiOrServer();  // Manages WiFi or server based on connection
    processArtnetData();   // Process Art-Net data
}