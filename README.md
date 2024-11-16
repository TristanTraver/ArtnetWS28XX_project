////////////////////////////////////////////////////////////////////////////////  
Author: Tristan Traver  
Date: 2024-11-11  
Version: 1.0  
////////////////////////////////////////////////////////////////////////////////  

Project Description  
This program was designed and tested using Arduino IDE for the ESP32C6 and works with LEDfx (https://docs.ledfx.app/en/latest/index.html), an open-source project for controlling LED strips via Art-Net and other protocols.  

Installation Requirements:  
Install the ESP32 board package from the Arduino IDE Boards Manager.  
Install the required libraries from the Library Manager:  
- Adafruit NeoPixel  
- ArtnetWifi

Default Configuration:  
- Universe: 1  
- Data Pin: GPIO 8  
- LED Strip: 8 LEDs  

Modifications:  
To add additional universes, change the data pin, or modify the number of LEDs on the strip, edit the files:  
- led_control.h  
- led_control.cpp  

Connection Procedure:  
At startup, the program will attempt to connect to the last saved Wi-Fi network. If the connection fails, it will create an Access Point. To configure it:  
- Connect to the ESP32_AP network.  
- Go to the page 192.168.4.1.  
- Enter your Wi-Fi credentials and submit the form.  

Static IP:  
The default configured static IP is 192.168.4.245. This IP is often outside the range of IP addresses assigned by most routers, so it is likely available.
For safety, it's recommended to check your router settings and configure the static IP there. If you need to change it, modify the wifi_manager.cpp file.  

Serial Output:  
During execution, debug messages are available and can be viewed in the Serial Monitor of Arduino IDE.
