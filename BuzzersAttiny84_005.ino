const int buzzerA = 10; // PB0
const int buzzerB = 9;  // PB1

const int ledA = 0; // PA0
const int ledB = 1; // PA1

// Séquences rythmiques
int seqA[] = {200, 100, 150, 50};
int seqB[] = {100, 50, 100, 150, 200};
int lenA = 4;
int lenB = 5;

int idxA = 0;
int idxB = 0;
unsigned long prevA = 0;
unsigned long prevB = 50; // décalage initial
bool stateA = LOW;
bool stateB = LOW;

void setup() {
  pinMode(buzzerA, OUTPUT);
  pinMode(buzzerB, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  // Buzzer A + LED A
  if (now - prevA >= seqA[idxA]) {
    stateA = !stateA;
    digitalWrite(buzzerA, stateA);
    digitalWrite(ledA, stateA);
    prevA = now;
    idxA = (idxA + 1) % lenA;
  }

  // Buzzer B + LED B
  if (now - prevB >= seqB[idxB]) {
    stateB = !stateB;
    digitalWrite(buzzerB, stateB);
    digitalWrite(ledB, stateB);
    prevB = now;
    idxB = (idxB + 1) % lenB;
  }
}