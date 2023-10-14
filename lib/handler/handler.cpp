#include <handler.h>

#define SOURCE "E4A4DCBD-F50F-4BDD-B4D9-3F7A4A5A86F3"

ESP8266WiFiMulti WiFiMulti;

void runHandler(const char *ssid, const char *password)
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

void saveData(int temperature, int humidity) {
  WiFiClient client;
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  if (http.begin(client, "http://api.brightbyte.ru:444/api/set/humidity")) {
    http.addHeader("Content-Type", "application/json");
    Serial.print("[HTTP] POST...\n");
    // start connection and send HTTP header
    const int capacity = JSON_OBJECT_SIZE(3);
    StaticJsonDocument<capacity> doc;
    doc["temperature"] = temperature;
    doc["humidity"] = humidity;
    doc["sourceId"] = SOURCE;
    int len1 = measureJson(doc);
    char output[len1];
    serializeJson(doc, output, sizeof(output));
    Serial.println(String(output));
    int httpCode = http.POST(String(output));
    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
      Serial.printf("[HTTP] POST... failed, error: %s %d\n", http.errorToString(httpCode).c_str(), httpCode);
    }

    http.end();
  }
}

void(* resetFunc) (void) = 0;

void parse_command(String inBuffer){
    // 3 - temperature 50 - humidity
    // expect something like 'send 3 50'
    String command = inBuffer.substring(0, inBuffer.indexOf(' '));
    String parameters = inBuffer.substring(inBuffer.indexOf(' ') + 1);
    Serial.println("handle command " + String(inBuffer));
    if (command == "send")
    {
        int temperature = parameters.substring(0, parameters.indexOf(' ')).toInt();
        int humidity = parameters.substring(parameters.indexOf(' ') + 1).toInt();
        Serial.println(command + " temperature " + String(temperature) + " humidity " + String(humidity));
        Serial.flush();
        saveData(temperature, humidity);
    }
    else if (command == "reset")
    {
      flushall();
      resetFunc();
    }
}

void handle_command()
{
    if ((WiFiMulti.run() == WL_CONNECTED))
    {
        if (Serial.available() <= 0)
        {
            return;
        }
        String inBuffer = Serial.readStringUntil('\n');
        inBuffer.trim();
        parse_command(inBuffer);
    }
    else
    {
        Serial.println("[HTTP] Unable to connect");
    }
    delay(1000);
}
