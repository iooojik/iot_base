#include <srv.h>

void setupWifiMode(const char *ssid, const char *password)
{
    Serial.begin(115200);
    delay(1000);
    Serial.println();
    String storedSsid = readFromEeprom(SSID_NAME);
    String storedPass = readFromEeprom(SSID_PASS);
    Serial.println(storedSsid + " " + storedPass);
    if (storedSsid == "" || storedPass == "")
    {
        setupAP(ssid, password);
        return;
    }
    runHandler(storedSsid.c_str(), storedPass.c_str());
}