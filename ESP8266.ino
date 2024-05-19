#define BLYNK_TEMPLATE_ID "______________"
#define BLYNK_TEMPLATE_NAME "__________"
#define BLYNK_AUTH_TOKEN "__________"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword"; 
// Your Blynk Auth Token
char auth[] = BLYNK_AUTH_TOKEN;

// Initialize a timer
BlynkTimer timer;

// Function to send data to Arduino
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  Serial.print("V1: ");
  Serial.println(pinValue);
  
  if (pinValue == 1) {
    Serial.println("Turning Relay ON");
    Serial.write('1'); // Send '1' to Arduino
  } else {
    Serial.println("Turning Relay OFF");
    Serial.write('0'); // Send '0' to Arduino
  }
}

void setup() {
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  timer.run();
}
