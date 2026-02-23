const int buttonPin = 17;
const int relayPin = 16;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(relayPin, HIGH);  // activa relé
  } else {
    digitalWrite(relayPin, LOW);   // desactiva relé
  }
}
