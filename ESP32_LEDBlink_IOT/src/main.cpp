#define BLYNK_TEMPLATE_ID "TMPL4vV0gEzw5"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "bcvfWaGfd05yBOvkHBrN3H37W7prVLSr"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Liwest_58bc";
char pass[] = "15112020";

void setup() {
  
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud",80);
  

}

void loop() {
  Blynk.run();

}
