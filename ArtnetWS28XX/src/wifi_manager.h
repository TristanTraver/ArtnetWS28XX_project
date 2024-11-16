/**
 * @file wifi_manager.h
 * @author Tristan Traver
 * @date 2024-11-11
 */

// Include guards
#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

////////////////////////////////////////////////////////////////////////////////
// System includes
#include <WiFi.h>
#include <WebServer.h>
#include <Preferences.h>

////////////////////////////////////////////////////////////////////////////////
// Global objects
extern WebServer server;
extern Preferences preferences;

////////////////////////////////////////////////////////////////////////////////
// Gublic functions
bool setupWiFi();
void startAccessPoint();
void handleWiFiOrServer();

#endif // WIFI_MANAGER_H