#include <handler.h>

ESP8266WiFiMulti WiFiMulti;

void runHandler(const char *ssid, const char *password)
{
    Serial.println();
    Serial.print("Running in wifi client mode...");
    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(ssid, password);
    delay(1000);
    if ((WiFiMulti.run() == WL_CONNECTED))
    {
        Serial.println("Connected");
    }
    else
    {
        Serial.println("Unable to connect");
    }
}