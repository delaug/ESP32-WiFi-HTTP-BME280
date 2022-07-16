#ifndef Battery_h
#define Battery_h

#include <Arduino.h>

class Battery
{
    public:
        void init(int analogPin, float calibration);
        void read();
        float getPercent();
        float getVoltage();

    private:    
        int _analogPin;
        float _percent;
        float _voltage;
        float _calibration;

        float _mapFloat(float v, float inMin, float inMax, float outMin, float outMax);
};

#endif 