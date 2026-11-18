#include <Arduino.h>

#include "pitches.h"

#define BTN_PIN 2
#define BZR_PIN 8

#define SCALE_SIZE 8

int notes[SCALE_SIZE] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5,
                         NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
char note_chars[SCALE_SIZE] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C'};
int duration = 500;  // 500 miliseconds

void setup() {
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(BZR_PIN, OUTPUT);

    Serial.begin(9600);
}

int i = 0;
bool pressed = false;

void loop() {
    tone(BZR_PIN, notes[i]);

    // block on button push
    while (digitalRead(BTN_PIN) == HIGH) {
        pressed = false;
    }

    // only count each press once
    if (pressed) {
        return;
    }

    pressed = true;

    // advance note
    i++;
    i %= SCALE_SIZE;
    Serial.println(note_chars[i]);
}
