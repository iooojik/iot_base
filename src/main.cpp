#include <srv.h>

/* Креды от wifi точки */
const char *ssid = "top_secret";
const char *password = "toppppecret";

int mode = 0;

void setup()
{
  Serial.begin(115200);
  delay(1000);
  EEPROM.begin(MAX_BUFF_SIZE);
  flushall();
  mode = setupWifiMode(ssid, password);
}

void loop()
{
  int m = updateMode();
  if (m != mode)
  {
    mode = m;
    mode = setupWifiMode(ssid, password);
  }
  if (mode == 1)
  {
    startHttpServer();
  }
  else if (mode == 0)
  {
    handle_command();
  }
  delay(1000);
}
