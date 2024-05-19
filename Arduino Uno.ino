void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  // Set the relay pin as an output
  pinMode(7, OUTPUT); // Assuming the relay is connected to pin 7
  digitalWrite(7, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming byte
    char incomingByte = Serial.read();
    
    // Control the relay based on the received byte
    if (incomingByte == '1') {
      Serial.println("high");
      digitalWrite(7, HIGH); // Turn relay ON
    } else if (incomingByte == '0') {
      Serial.println("low");
      digitalWrite(7, LOW); // Turn relay OFF
    }
  }
}
