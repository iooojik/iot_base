#include <Arduino.h>
#include <eprom.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFiMulti.h>
#include <json.h>

#define MAX_BUFF_SIZE 256
#define SSID_NAME 0
#define SSID_PASS MAX_BUFF_SIZE

void startHttpServer();

void setupAP(const char *ssid, const char *password);
