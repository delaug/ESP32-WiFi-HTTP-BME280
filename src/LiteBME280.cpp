#include "LiteBME280.h"

LiteBME280::LiteBME280() {
    this->_bme_temp = this->_bme.getTemperatureSensor();
    this->_bme_pressure = this->_bme.getPressureSensor();
    this->_bme_humidity = this->_bme.getHumiditySensor();
}

void LiteBME280::init() {
    if (!this->_bme.begin(0x76)) {
        Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
        while (1) delay(10);
    }
  
    this->_bme_temp->printSensorDetails();
    this->_bme_pressure->printSensorDetails();
    this->_bme_humidity->printSensorDetails();
}

void LiteBME280::read() {  
    this->_readSensors(); 

    Serial.print(F("Temperature = "));
    Serial.print(this->_temp_event.temperature);
    Serial.println(" *C");

    Serial.print(F("Humidity = "));
    Serial.print(this->_humidity_event.relative_humidity);
    Serial.println(" %");

    Serial.print(F("Pressure = "));
    Serial.print(this->_pressure_event.pressure / 1.333F);
    Serial.println(" mm Hg");

    Serial.print(F("Approx altitude = "));
    Serial.print(this->_bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.println();
}

String LiteBME280::getHTTPData() { 
    this->_readSensors();

    return "temperature="+String(this->_temp_event.temperature)+"&humidity="+String(this->_humidity_event.relative_humidity)+"&pressure="+String(this->_pressure_event.pressure)+"&altitude="+String(this->_bme.readAltitude(SEALEVELPRESSURE_HPA));
}

void LiteBME280::_readSensors() {
    this->_bme_temp->getEvent(&this->_temp_event);
    this->_bme_pressure->getEvent(&this->_pressure_event);
    this->_bme_humidity->getEvent(&this->_humidity_event);
}