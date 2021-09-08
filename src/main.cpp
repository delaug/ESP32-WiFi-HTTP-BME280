#include <Arduino.h>
#include "LiteWiFi.h"
#include "LiteHTTPClient.h"
#include "LiteBME280.h"

#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP  60

RTC_DATA_ATTR int bootCount = 0;

LiteWiFi wifi = LiteWiFi();
LiteHTTPClient client = LiteHTTPClient();
LiteBME280 bme = LiteBME280();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);

  //Increment boot number and print it every reboot
	++bootCount;
	Serial.println("Boot number: " + String(bootCount));

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");

  Serial.println("Run ESP32...\n");
  wifi.init("SSID", "PASS");

  // BME280 sensor  
  bme.init();
    
  // send data on server
  client.send("http://192.168.100.100/sensor/","token=TOKEN&"+bme.getHTTPData());    
 
  // deep sleep    
  esp_deep_sleep_start();
}

void loop() {}