#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL381WNwJoH"
#define BLYNK_TEMPLATE_NAME "Voice Switch"
#define BLYNK_AUTH_TOKEN "lVHl5ZuZD_7PlzUhvFUh3cOIblFHk2KY"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "RailWire_Broadband_Subodh";
char pass[] = "Pranav@1234";

// Relay pins
int relay1Pin = 5;   // First relay
int relay2Pin = 18;  // Second relay

void setup()
{
  Serial.begin(9600);

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);

  digitalWrite(relay1Pin, LOW); // Start OFF
  digitalWrite(relay2Pin, LOW); // Start OFF

  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Virtual pin handler for Relay 1
BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(relay1Pin, value);
  Serial.print("Relay 1 switched: ");
  Serial.println(value ? "ON" : "OFF");
}

// Virtual pin handler for Relay 2
BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(relay2Pin, value);
  Serial.print("Relay 2 switched: ");
  Serial.println(value ? "ON" : "OFF");
}

void loop()
{
  Blynk.run();
}
