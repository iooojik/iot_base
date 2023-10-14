#include <srv.h>

/* Креды от wifi точки */
const char *ssid = "top_secret";
const char *password = "toppppecret";

void setup()
{
  setupAP(ssid, password);
}

void loop()
{
  startHttpServer();
}
