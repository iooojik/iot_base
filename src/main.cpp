#include <srv.h>

/* Set these to your desired credentials. */
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
