#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* contentfulURL = "https://cdn.contentful.com/spaces/rfmnqwpl5khc/environments/master/entries";
const char* accessToken = "Bearer X7OyNytTJLky2loTcuvVisNUAqyk9Ql6ZoDH9Tozwxc";

unsigned long timerScan = 0;
 #define SCAN_DELAY 3000
 
 
 void setup()
 {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.println("Starting Wifi Connection...");
    while(WiFi.status() != WL_CONNECTED){
        delay(100);
        Serial.print("*");
     }   
    Serial.println("\n Successfully Connected with: ");
    Serial.println(ssid);
 }
 
 void loop()
 {    
     if( (millis() - timerScan) >= SCAN_DELAY){
         Serial.println("\n **** SCAN START **** \n");
         scanRoutine();
         timerScan = millis();
         Serial.println("\n **** SCAN END **** \n");
     }
 }
 
 
 void scanRoutine(){
     
     HTTPClient http;
     http.begin(contentfulURL);
     http.addHeader("Authorization", accessToken);
 
     int httpResponseStatus = http.GET();
 
     if(httpResponseStatus > 0){
         String response = http.getString();
 
         const int responseSize = response.length() * 1.1;
         DynamicJsonDocument json(responseSize);
         deserializeJson(json, response);
 
         JsonArray items = json["items"];
 
         for(JsonObject item : items){
             int pin = item["fields"]["pin"] | -1;
             bool state = item["fields"]["state"] | false;
 
             if(pin >= 0){
                 pinMode(pin, OUTPUT);
                 digitalWrite(pin, state);
                 Serial.printf("PIN: %d, STATE: %s \n", pin, state ? "ON": "OFF");
             }
         }
     }
     else{
         Serial.printf("\n Error when calling backend: %d \n", httpResponseStatus);
     }
 
     http.end();
 }
 