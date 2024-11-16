/**
 * @file artnet_handler.h
 * @author Tristan Traver
 * @date 2024-11-11
 */

// Include guards
#ifndef ARTNET_HANDLER_H
#define ARTNET_HANDLER_H

////////////////////////////////////////////////////////////////////////////////
// Application includes
#include <ArtnetWifi.h>

////////////////////////////////////////////////////////////////////////////////
// Public functions
void startArtnet();
void processArtnetData();
void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data);

#endif // ARTNET_HANDLER_H