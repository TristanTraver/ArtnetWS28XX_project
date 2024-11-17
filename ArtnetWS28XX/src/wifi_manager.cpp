/**
 * @file wifi_manager.cpp
 * @author Tristan Traver
 * @date 2024-11-11
 */

////////////////////////////////////////////////////////////////////////////////
// System includes
#include "wifi_manager.h"

////////////////////////////////////////////////////////////////////////////////
// Server port configuration
WebServer server(80);

////////////////////////////////////////////////////////////////////////////////
// Global objects
Preferences preferences;
String ssid, password;

////////////////////////////////////////////////////////////////////////////////
// Private functions
//------------------------------------------------------------------------------
bool setupWiFi()
//------------------------------------------------------------------------------
{
    preferences.begin("wifi", false);
    ssid = preferences.getString("ssid", "");
    password = preferences.getString("password", "");

    if (ssid == "") return false;

    WiFi.begin(ssid.c_str(), password.c_str());
    WiFi.setSleep(false);

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
        delay(500);
        Serial.print(".");
    }
    return WiFi.status() == WL_CONNECTED;
}

//------------------------------------------------------------------------------
void startAccessPoint()
//------------------------------------------------------------------------------
{
    WiFi.softAP("ESP32_AP", ""); // Leave empty if you don't want to set a password
    delay(100);  // Wait AP start

    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);

    // Wifi configuration page
    server.on("/", HTTP_GET, []() {
    Serial.println("WiFi setup page required.");
    server.send(200, "text/html", "<form action='/save' method='POST'><input name='ssid' placeholder='SSID'><br><input name='pass' type='password' placeholder='Password'><br><input type='submit'></form>");
    });

    // Handles receiving and saving the credentials
    server.on("/save", HTTP_POST, []() {
    ssid = server.arg("ssid");
    password = server.arg("pass");

    // Save credentials in preferences
    preferences.putString("ssid", ssid);
    preferences.putString("password", password);

    // Debug to verify the saved credentials
    Serial.print("SSID saved: ");
    Serial.println(ssid);
    Serial.print("Password saved: ");
    Serial.println(password);

    // Sends a response to the user
    server.send(200, "text/html", "<h1>saved, restart...</h1>");
    delay(1000);
    ESP.restart();
    });

    server.begin();
    Serial.println("Web server started for configuration.");
}

//------------------------------------------------------------------------------
void handleWiFiOrServer()
//------------------------------------------------------------------------------
{
    if (WiFi.status() != WL_CONNECTED) {
        server.handleClient();
    }
}
