#include <srv.h>

/* Креды от wifi точки */
const char *ssid = "top_secret";
const char *password = "toppppecret";

void setup()
{
  setupWifiMode(ssid, password);
}

void loop()
{
  startHttpServer();
}
