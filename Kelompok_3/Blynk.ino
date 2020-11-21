
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "cA2hxTJh-kg1O0YVYDMdi8K3IzAuZlW8";

char ssid[] = "Dewansyah";
char pass[] = "monaco2tc1";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
