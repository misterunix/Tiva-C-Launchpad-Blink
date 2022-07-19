#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(PF_1, OUTPUT); // Red LED
  pinMode(PF_2, OUTPUT); // Blue LED
  pinMode(PF_3, OUTPUT); // Green LED
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PF_1, HIGH);
  delay(100);
  digitalWrite(PF_1, LOW);
  delay(100);
  digitalWrite(PF_2, HIGH);
  delay(100);
  digitalWrite(PF_2, LOW);
  delay(100);
  digitalWrite(PF_3, HIGH);
  delay(100);
  digitalWrite(PF_3, LOW);
  delay(100);
}