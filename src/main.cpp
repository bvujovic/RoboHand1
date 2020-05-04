#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "RoboHand.h"

const int pinLed = LED_BUILTIN;
const int pinBtn = D5;

RoboHand rh(D1, D2);
bool btnDown = false;
int i = 0;

void setup(void)
{
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, true);
  pinMode(pinBtn, INPUT_PULLUP);

  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);
}

void loop()
{
  bool btnDownNew = !digitalRead(pinBtn);
  if (btnDownNew != btnDown)
  {
    digitalWrite(pinLed, !btnDownNew);
    if (btnDownNew)
      rh.Catch();
    else
      rh.Release();
    btnDown = btnDownNew;
    delay(20);
  }
}