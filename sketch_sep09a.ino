#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>
#include <Robojax_AllegroACS_Current_Sensor.h>
#include <Filters.h>

float testFrequncy = 50;
float windowLength = 40/testFrequncy;
int sensor = 2;
float intercept = -0.04;
float slope = 0.0405;
float current_volts;

unsigned long printPeriod = 1000;
unsigned long previsousMillis = 0;
const char* ssid = "ESP36-Access-Point";
const char* password = "123456789";
AsyncWebServer server(80);

String getcurrent() {
  int adc = analogRead(36) / 2;
  float voltage = adc*5/1023.0;
  float current = (voltage-2.5)/0.185;
  return String(current);
}

String getvoltage() {
  RunningStatistics inputStats;
  inputStats.setWindowSecs(windowLength);
  sensor = analogRead(sensor);
  inputStats.input(sensor);
  previsousMillis = millis();
  current_volts = intercept + slope * inputStats.sigma();
  current_volts = current_volts * (40.3231);
  return String(current_volts);
}


void setup() {
  // Serial port for debugging purposes
  Serial.begin(9600);
  Serial.println();
  //  pinMode(36, INPUT);
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/current", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", getcurrent().c_str());
  });

  server.on("/voltage", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", getvoltage().c_str());
  });

  server.begin();

  delay(2000);
}

void loop() {
}
