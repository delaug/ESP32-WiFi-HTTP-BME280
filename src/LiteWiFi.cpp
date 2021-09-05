#include "LiteWiFi.h"

void LiteWiFi::init(char* ssid, char* password) {
    // We start by connecting to a WiFi network
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
};

bool LiteWiFi::checkConnection() {
    return (WiFi.status() == WL_CONNECTED);
}