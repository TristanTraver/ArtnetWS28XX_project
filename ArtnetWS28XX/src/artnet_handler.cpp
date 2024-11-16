/**
 * @file artnet_handler.cpp
 * @author Tristan Traver
 * @date 2024-11-11
 */

////////////////////////////////////////////////////////////////////////////////
// Application includes
#include "artnet_handler.h"
#include "led_control.h"

////////////////////////////////////////////////////////////////////////////////
// Global objects
ArtnetWifi artnet;

////////////////////////////////////////////////////////////////////////////////
// Private functions
//------------------------------------------------------------------------------
void startArtnet()
//------------------------------------------------------------------------------
{
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    artnet.begin();
    artnet.setArtDmxCallback(onDmxFrame);
}

//------------------------------------------------------------------------------
void processArtnetData()
//------------------------------------------------------------------------------
{
    artnet.read();
}

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data) {
    if (universe != 1) return;
    updateLEDsFromDMX(data, length);
}