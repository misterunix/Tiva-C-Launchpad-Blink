#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

int incomingByte = 0; // for incoming serial data
volatile byte state = LOW;

const byte interruptPin = PUSH1;

volatile unsigned long oldmillis = 0;

void blink() {
  int t = millis();
  if (t - oldmillis > 50) {
    oldmillis = t;
    state = !state;
  }
  // state = !state;
}

void watchForSerialIn() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if (incomingByte == '1') {
      Serial.print("red\n");
      digitalWrite(PF_1, HIGH);
      digitalWrite(PF_2, LOW);
      digitalWrite(PF_3, LOW);
    }
    if (incomingByte == '2') {
      Serial.print("blue\n");
      digitalWrite(PF_1, LOW);
      digitalWrite(PF_2, HIGH);
      digitalWrite(PF_3, LOW);
    }
    if (incomingByte == '3') {
      Serial.print("green\n");
      digitalWrite(PF_1, LOW);
      digitalWrite(PF_2, LOW);
      digitalWrite(PF_3, HIGH);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PF_1, OUTPUT); // Red LED
  pinMode(PF_2, OUTPUT); // Blue LED
  pinMode(PF_3, OUTPUT); // Green LED

  pinMode(PUSH1, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // digitalWrite(PF_1, state);

  watchForSerialIn();

  long r = random(0,4);
  if (r == 0) {
    //Serial.print("red\n");
    digitalWrite(PF_1, HIGH);
    digitalWrite(PF_2, LOW);
    digitalWrite(PF_3, LOW);
  }
  if (r == 1) {
    //Serial.print("blue\n");
    digitalWrite(PF_1, LOW);
    digitalWrite(PF_2, HIGH);
    digitalWrite(PF_3, LOW);
  }
  if (r == 2) {
    //Serial.print("green\n");
    digitalWrite(PF_1, LOW);
    digitalWrite(PF_2, LOW);
    digitalWrite(PF_3, HIGH);
  }
  if (r == 3) {
    //Serial.print("off\n");
    digitalWrite(PF_1, LOW);
    digitalWrite(PF_2, LOW);
    digitalWrite(PF_3, LOW);
  }

  delay(500);


}
