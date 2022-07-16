#include "Battery.h"

void Battery::init(int analogPin, float calibration)
{
    this->_analogPin = analogPin;
    this->_calibration = calibration;
}

void Battery::read()
{
    int value = analogRead(this->_analogPin);

    // multiply by two as voltage divider network is 100K & 100K Resistor
    this->_voltage = (((value * 3.3) / 4096) * 2 + this->_calibration); 
    // 2.8V as Battery Cut off Voltage & 4.2V as Maximum Voltage
    this->_percent = this->_mapFloat(this->_voltage , 2.8, 4.2, 0, 100);

    if (this->_percent >= 100)
    {
        this->_percent = 100;
    }
    if (this->_percent <= 0)
    {
        this->_percent = 1;
    }
}

float Battery::getVoltage()
{
    return this->_voltage;
}

float Battery::getPercent()
{
    return this->_percent;
}

float Battery::_mapFloat(float v, float inMin, float inMax, float outMin, float outMax)
{
    return (v - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}