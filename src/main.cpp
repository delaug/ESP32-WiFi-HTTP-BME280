#include <Arduino.h>
#include "LiteWiFi.h"
#include "LiteHTTPClient.h"
#include "LiteBME280.h"

#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP  120

LiteWiFi wifi = LiteWiFi();
LiteHTTPClient client = LiteHTTPClient();
LiteBME280 bme = LiteBME280();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");

  Serial.println("Run ESP32...\n");
  wifi.init("SSID", "PASS");

  // BME280 sensor  
  bme.init();

  if(wifi.checkConnection()) {
    // send data on server
    client.send("http://192.168.100.100/sensor/","token=TOKEN&"+bme.getHTTPData());      

    // deep sleep
    Serial.println("Going to sleep now");
    delay(1000);
    esp_deep_sleep_start();
  }  
}

void loop() {
  // put your main code here, to run repeatedly:  
}