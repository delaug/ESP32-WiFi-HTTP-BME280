#ifndef LiteBME280_h
#define LiteBME280_h

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

class LiteBME280 {
    public:
        LiteBME280();
        void init();
        void read();
        String getHTTPData();
    private:
        Adafruit_BME280 _bme; // use I2C interface
        Adafruit_Sensor *_bme_temp = nullptr;
        Adafruit_Sensor *_bme_pressure = nullptr;
        Adafruit_Sensor *_bme_humidity = nullptr;

        sensors_event_t _temp_event, _pressure_event, _humidity_event;

        void _readSensors();
};

#endif 