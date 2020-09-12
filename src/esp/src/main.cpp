#include <Arduino.h>
#include <AutoConnect.h>
#include <WebServer.h>  // Replace with WebServer.h for ESP32
#include <WiFi.h>       // Replace with WiFi.h for ESP32

WebServer Server;  // Replace with WebServer for ESP32
AutoConnect Portal(Server);

void rootPage() {
    char content[] = "Hello, world";
    Server.send(200, "text/plain", content);
}

// Set up the builtin LED
const int ledPin = LED_BUILTIN;  // the number of the LED pin


void setup() {
    // wdt_disable();
    delay(1000);
    Serial.begin(115200);
    Server.on("/", rootPage);
    if (Portal.begin()) {
        Serial.println("WiFi connected: " + WiFi.localIP().toString());
    }
}


void loop() {
    Portal.handleClient();
}