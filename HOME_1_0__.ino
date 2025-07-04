#define BLYNK_TEMPLATE_ID "TMPXXXXXXXX" // replace your template id
#define BLYNK_TEMPLATE_NAME "Smart Home"
#define BLYNK_AUTH_TOKEN "bAiJXXXXXXXXXXXXXXXXXXXXXXXX" // repalce your token

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Ved";     // Replace
char pass[] = "pass1235";     // Replace


// Relay pins
#define RELAY1 D1
#define RELAY2 D2
#define RELAY3 D3
#define RELAY4 D4

String inputString = "";

void setup() {
  Serial.begin(9600);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // Set relays OFF (HIGH = off for active LOW relay)
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);

  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("You can now control from Serial Monitor and Blynk app.");
  Serial.println("Example: on1, off2, on3...");
}

void loop() {
  Blynk.run();

  // Serial Monitor Control
  if (Serial.available()) {
    inputString = Serial.readStringUntil('\n');
    inputString.trim();

    if (inputString == "on1") digitalWrite(RELAY1, LOW);
    else if (inputString == "off1") digitalWrite(RELAY1, HIGH);

    else if (inputString == "on2") digitalWrite(RELAY2, LOW);
    else if (inputString == "off2") digitalWrite(RELAY2, HIGH);

    else if (inputString == "on3") digitalWrite(RELAY3, LOW);
    else if (inputString == "off3") digitalWrite(RELAY3, HIGH);

    else if (inputString == "on4") digitalWrite(RELAY4, LOW);
    else if (inputString == "off4") digitalWrite(RELAY4, HIGH);

    else Serial.println("Invalid command.");
  }
}

// Blynk Virtual Pin Handlers
BLYNK_WRITE(V1) {
  digitalWrite(RELAY1, param.asInt() == 1 ? LOW : HIGH);
}

BLYNK_WRITE(V2) {
  digitalWrite(RELAY2, param.asInt() == 1 ? LOW : HIGH);
}

BLYNK_WRITE(V3) {
  digitalWrite(RELAY3, param.asInt() == 1 ? LOW : HIGH);
}

BLYNK_WRITE(V4) {
  digitalWrite(RELAY4, param.asInt() == 1 ? LOW : HIGH);
}