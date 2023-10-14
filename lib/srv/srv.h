#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <json.h>



using namespace std;

void setupAP(const char *ssid, const char *password);

void startHttpServer();