const int pins[] = {3, 5, 6, 9, 10};
const unsigned long intervals[] = {10000, 1000, 500, 100, 50};
bool states[] = {LOW, LOW, LOW, LOW, LOW};
unsigned long lastToggle[] = {0, 0, 0, 0, 0};
const int pinCount = 5;

void setup() {
  for (int i = 0; i < pinCount; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  unsigned long now = micros();
  
  for (int i = 0; i < pinCount; i++) {
    if (now - lastToggle[i] >= intervals[i]) {
      lastToggle[i] = now;
      states[i] = !states[i];
      digitalWrite(pins[i], states[i]);
    }
  }
}
