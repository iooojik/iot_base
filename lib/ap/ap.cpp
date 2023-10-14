#define SSID_NAME 0
#define SSID_PASS 128

ESP8266WebServer server(80);
ESP8266WiFiMulti WiFiMulti;


void handleWifiSettings()
{
    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, server.arg("plain"));
    if (error)
    {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
    }
    const char *ssid = doc["ssid"];
    bool result = write2Eeprom(SSID_NAME, ssid);
    if (result)
    {
        const char *pass = doc["pass"];
        result = write2Eeprom(SSID_PASS, pass);
        Serial.println("saved new ssid and pass");
    }

    const int capacity = JSON_OBJECT_SIZE(1);
    StaticJsonDocument<capacity> respDoc;
    if (result)
    {
        respDoc["status"] = "saved";
    }
    else
    {
        respDoc["status"] = "error";
    }
    int len1 = measureJson(respDoc);
    char output[len1];
    serializeJson(respDoc, output, sizeof(output));
    server.send(200, "application/json", output);
}

void handleInfoPath()
{
    const int capacity = JSON_OBJECT_SIZE(2);
    StaticJsonDocument<capacity> doc;
    doc["device"] = "humidity_sensor_v1";
    doc["key"] = "123456";
    int len1 = measureJson(doc);
    char output[len1];
    serializeJson(doc, output, sizeof(output));
    server.send(200, "application/json", output);
}


void runAp(const char *ssid, const char *password)
{
    Serial.println("Running in access point mode...");
    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.println("AP IP address: ");
    Serial.println(myIP);
    server.on("/", handleInfoPath);
    server.on("/set", handleWifiSettings);
    server.begin();
    Serial.println("Server listening");
}

void setupAP(const char *ssid, const char *password)
{
    EEPROM.begin(256);
    setupWifiMode(ssid, password);
}


void startHttpServer()
{
    server.handleClient();
}