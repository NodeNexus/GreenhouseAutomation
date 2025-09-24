#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <DHT.h>

#define DHTPIN 34
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_SENSOR_PIN 35
#define FAN_PIN 19
#define WATER_PUMP_PIN 18
#define LIGHT_PIN 5

const char* ssid = "ESP32-AP";
const char* password = "12345678";

AsyncWebServer server(80);

bool fanState = false;
bool pumpState = false;
bool lightState = false;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(FAN_PIN, OUTPUT);
  pinMode(WATER_PUMP_PIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);

  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");
  Serial.println(WiFi.softAPIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", webpage);
  });

  server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request){
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    int soil = analogRead(SOIL_SENSOR_PIN);

    StaticJsonDocument<200> doc;
    doc["temperature"] = temp;
    doc["humidity"] = hum;
    doc["soil"] = soil;
    doc["fan"] = fanState;
    doc["pump"] = pumpState;
    doc["light"] = lightState;

    String json;
    serializeJson(doc, json);
    request->send(200, "application/json", json);
  });

  server.on("/toggle", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("device")) {
      String device = request->getParam("device")->value();
      if (device =
