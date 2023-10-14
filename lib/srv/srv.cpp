#include <srv.h>

int updateMode()
{
    int mode = 0;
    String storedSsid = readFromEeprom(SSID_NAME);
    String storedPass = readFromEeprom(storedSsid.length());
    if (storedSsid == "" || storedPass == "")
    {
        mode = 1;
    }
    return mode;
}

int setupWifiMode(const char *ssid, const char *password)
{
    Serial.begin(115200);
    delay(1000);
    Serial.println();
    int mode = updateMode();
    String storedSsid = readFromEeprom(SSID_NAME);
    String storedPass = readFromEeprom(storedSsid.length());
    if (storedSsid == "" || storedPass == "")
    {
        mode = 1;
        setupAP(ssid, password);
        return mode;
    }
    runHandler(storedSsid.c_str(), storedPass.c_str());
    return mode;
}