#define DELAY 10

#define MAX_VAL 120

#define RED 2
#define GREEN 4
#define BLUE 6

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(9600);
}

int color[3] = { 0, 0, 0 };
int i = 0;
bool inc = true;

void printColor(int i) {
  switch(i) {
  case 0:
    Serial.println("red");
    break;
  case 1:
    Serial.println("green");
    break;
  case 2:
    Serial.println("blue");
    break;
  }
}

void loop() {
  // cycle through red, then green, then blue
  if (color[i] > 0 && !inc) {
    color[i]--;
  } else if (color[i] <= MAX_VAL && inc) {
    color[i]++;
  }

  if (color[i] == MAX_VAL) {
    inc = false;
  } else if (color[i] == 0) {
    i++;
    i %= 3;
    inc = true;
    printColor(i);
  }

  analogWrite(RED, color[0]);
  analogWrite(GREEN, color[1]);
  analogWrite(BLUE, color[2]);
  delay(DELAY);
}
