#include <Arduino.h>
#include <eprom.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <json.h>

#define SOURCE "E4A4DCBD-F50F-4BDD-B4D9-3F7A4A5A86F3"

void runHandler(const char *ssid, const char *password);

void handle_command();