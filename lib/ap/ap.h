#include <Arduino.h>
#include <eprom.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFiMulti.h>
#include <json.h>

#define SSID_NAME 0

void startHttpServer();

void setupAP(const char *ssid, const char *password);
