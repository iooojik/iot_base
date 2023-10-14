#include <srv.h>

int updateMode()
{
    int mode = 0;
    String storedSsid = readFromEeprom(SSID_NAME);
    String storedPass = readFromEeprom(storedSsid.length()+1+SSID_NAME);
    if (storedSsid == "" || storedPass == "")
    {
        mode = 1;
    }
    return mode;
}

int setupWifiMode(const char *ssid, const char *password)
{
    Serial.println();
    int mode = updateMode();
    String storedSsid = readFromEeprom(SSID_NAME);
    String storedPass = readFromEeprom(storedSsid.length()+1+SSID_NAME);
    if (storedSsid == "" || storedPass == "")
    {
        mode = 1;
        setupAP(ssid, password);
        return mode;
    }
    runHandler(storedSsid.c_str(), storedPass.c_str());
    return mode;
}