#ifndef LiteWiFi_h
#define LiteWiFi_h

#include <WiFi.h>

class LiteWiFi {
    public:
        void init(char* ssid, char* password);
        bool checkConnection();
        bool disconnect();
    private:

};

#endif 