#include <Arduino.h>
#include "LiteWiFi.h"
#include "LiteHTTPClient.h"
#include "LiteBME280.h"

LiteWiFi wifi = LiteWiFi();
LiteHTTPClient client = LiteHTTPClient();
LiteBME280 bme = LiteBME280();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("Run ESP32...\n");
  wifi.init("SSID", "PASSWORD");

  // BME280 sensor  
  bme.init();
}

void loop() {
  // put your main code here, to run repeatedly:  
  if(wifi.checkConnection()) {
    Serial.println("Connetcion = ok");
  
    // send data on server
    //client.send("http://api.devserver.ru/",bme.getHTTPData(),"POST");
  }
  
  // just read and print data
  bme.read();

  delay(1000);
}