#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "nothing phone 2a";
const char* password = "idontknow";

WiFiClient client;
unsigned long channelID = 1234567;
const char* writeAPIKey = "ABCD1234EFGH5678";

int mq135Pin = A0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  ThingSpeak.begin(client);
}

void loop() {
  int airValue = analogRead(mq135Pin);
  ThingSpeak.writeField(channelID, 1, airValue, writeAPIKey);
  Serial.println("Air Quality Value: " + String(airValue));
  delay(30000);
}
