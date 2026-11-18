#define LED_PIN 8
#define BTN_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

bool on = false;
uint8_t last = HIGH;

void loop() {
  uint8_t reading = digitalRead(BTN_PIN);

  // button click
  if (reading == LOW && last == HIGH) {
    on = !on;
  }

  digitalWrite(LED_PIN, on ? HIGH : LOW);

  last = reading;

  delay(10);
}
