#include "LiteHTTPClient.h"

void LiteHTTPClient::send(String url, String data, String method) {    
    HTTPClient http;                     
    int httpCode = 0;

    if(method == "GET" && data != "") {            
        url = url + "?" + data;
    }
    Serial.print("URL: ");
    Serial.println(url);

    http.begin(url); //Specify the URL

    //Make the request
    if(method == "GET") {
        httpCode = http.GET();  
    } else if(method == "POST") {
        httpCode = http.POST(data);
    }
        
    if (httpCode > 0) {         //Check for the returning code 
        String payload = http.getString();
        Serial.print("Code: ");
        Serial.println(httpCode);
        Serial.print("Payload: ");
        Serial.println(payload);
    } 
    else {
        Serial.println("Error on HTTP request");
    } 
    http.end(); //Free the resources    
};