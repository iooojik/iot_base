
void runWifiClient(const char *ssid, const char *password)
{
    Serial.println();
    Serial.print("Running in wifi client mode...");
    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(ssid, password);
    delay(1000);
    if ((WiFiMulti.run() == WL_CONNECTED))
    {
        Serial.println("Connected");
    }
    else
    {
        Serial.println("Unable to connect");
    }
}

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
        runAp(ssid, password);
        return;
    }
    runWifiClient(storedSsid.c_str(), storedPass.c_str());
}