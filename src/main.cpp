#include <server.h>

/* Set these to your desired credentials. */
const char *ssid = "top_secret";
const char *password = "toppppecret";

[[maybe_unused]] void setup()
{
  setupAP(ssid, password);
}

void loop()
{
  startHttpServer();
}
