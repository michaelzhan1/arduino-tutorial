#define LED_PIN 8
#define ON_BTN_PIN 2
#define OFF_BTN_PIN 4

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(ON_BTN_PIN, INPUT_PULLUP);
  pinMode(OFF_BTN_PIN, INPUT_PULLUP);
}

void loop() {
  // signal goes low when we connect to ground
  if (digitalRead(ON_BTN_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);
  }
  if (digitalRead(OFF_BTN_PIN) == LOW) {
    digitalWrite(LED_PIN, LOW);
  }
}
