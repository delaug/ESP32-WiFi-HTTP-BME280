#include <Arduino.h>
#include "LiteWiFi.h"
#include "LiteHTTPClient.h"
#include "LiteBME280.h"

LiteWiFi wifi = LiteWiFi();
LiteHTTPClient client = LiteHTTPClient();
LiteBME280 bme = LiteBME280();

int dt = 0;             // delta time
int sendInterval = 120; // seconds

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("Run ESP32...\n");
  wifi.init("SSID", "PASS");

  // BME280 sensor  
  bme.init();
}

void loop() {
  // put your main code here, to run repeatedly:  
  if(wifi.checkConnection()) {
    // send data on server
    if(dt >= sendInterval) {
      client.send("http://192.168.100.100/sensor/","token=TOKEN&"+bme.getHTTPData());

      dt = 0; // clear dt
    }
  }

  dt++;
  delay(1000);
}