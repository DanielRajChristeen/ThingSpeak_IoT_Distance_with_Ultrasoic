#include <WiFi.h>
#include <HTTPClient.h>

#define TRIG_PIN 5
#define ECHO_PIN 18

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

String writeAPIKey = "YOUR_WRITE_API_KEY";
String channelID = "YOUR_CHANNEL_ID";

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Connected!");
}

float getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distanceCM = (duration * 0.0343) / 2;
  return distanceCM;
}

void sendToThingSpeak(float distance) {
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;

    String url = "https://api.thingspeak.com/update?api_key=" + writeAPIKey +
                 "&field1=" + String(distance);

    http.begin(url);
    int code = http.GET();

    if(code > 0){
      Serial.print("Uploaded Distance: ");
      Serial.println(distance);
    } else {
      Serial.println("Upload Failed!");
    }

    http.end();
  }
}

void loop() {
  float distance = getDistanceCM();
  Serial.print("Distance: ");
  Serial.println(distance);

  sendToThingSpeak(distance);
  delay(15000);
}
