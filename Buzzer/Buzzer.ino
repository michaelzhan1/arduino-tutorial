#define BTN_PIN 2
#define BZR_PIN 8

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(BZR_PIN, OUTPUT);
}

void loop() {
  uint8_t reading = digitalRead(BTN_PIN);

  // while button is pressed, play noise
  if (reading == LOW) {
    digitalWrite(BZR_PIN, HIGH);
  } else {
    digitalWrite(BZR_PIN, LOW);
  }
}
