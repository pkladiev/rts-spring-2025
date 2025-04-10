const int pins[] = {3, 5, 6, 9, 10};
const unsigned long intervals[] = {10000, 1000, 500, 100, 50};
volatile bool states[] = {LOW, LOW, LOW, LOW, LOW};
unsigned long prevMicros0;
unsigned long prevMicros1;
unsigned long prevMicros2;
unsigned long prevMicros3;
unsigned long prevMicros4;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(pins[i], OUTPUT);
  }
  unsigned long curMicros = micros();
  prevMicros0 = curMicros;
  prevMicros1 = curMicros;
  prevMicros2 = curMicros;
  prevMicros3 = curMicros;
  prevMicros4 = curMicros;
}

void loop() {
  unsigned long curMicros = micros();
  if(curMicros - prevMicros4 >= intervals[4]){
    PORTB = PORTB ^ B00000100;
    prevMicros4 = curMicros;
  }
  if(curMicros - prevMicros3 >= intervals[3]){
    PORTB = PORTB ^ B00000010;
    prevMicros3 = curMicros;
  }
  if(curMicros - prevMicros2 >= intervals[2]){
    PORTD = PORTD ^ B01000000;
    prevMicros2 = curMicros;
  }
  if(curMicros - prevMicros1 >= intervals[1]){
    PORTD = PORTD ^ B00100000;
    prevMicros1 = curMicros;
  }
  if(curMicros - prevMicros0 >= intervals[0]){
    PORTD = PORTD ^ B00001000;
    prevMicros0 = curMicros;
  }
}
