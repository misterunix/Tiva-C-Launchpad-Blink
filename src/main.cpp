#include <Arduino.h>

int incomingByte = 0; // for incoming serial data
volatile byte state = LOW;
const byte interruptPin = PUSH1;

void blink()
{
  state = !state;
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(PF_1, OUTPUT); // Red LED
  pinMode(PF_2, OUTPUT); // Blue LED
  pinMode(PF_3, OUTPUT); // Green LED

  pinMode(interruptPin, INPUT_PULLUP);

  attachInterrupt(interruptPin, blink, CHANGE);

  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:

  digitalWrite(PF_1, state);

  if (Serial.available() > 0)
  {
    // read the incoming byte:
    incomingByte = Serial.read();

    if (incomingByte == '1')
    {
      Serial.print("red\n");
      digitalWrite(PF_1, HIGH);
      digitalWrite(PF_2, LOW);
      digitalWrite(PF_3, LOW);
    }
    if (incomingByte == '2')
    {
      Serial.print("blue\n");
      digitalWrite(PF_1, LOW);
      digitalWrite(PF_2, HIGH);
      digitalWrite(PF_3, LOW);
    }
    if (incomingByte == '3')
    {
      Serial.print("green\n");
      digitalWrite(PF_1, LOW);
      digitalWrite(PF_2, LOW);
      digitalWrite(PF_3, HIGH);
    }

    /*
  Serial.print("red\n");
  digitalWrite(PF_1, HIGH);
  delay(1000);
  digitalWrite(PF_1, LOW);
  delay(1000);
  Serial.print("blue\n");
  digitalWrite(PF_2, HIGH);
  delay(1000);
  digitalWrite(PF_2, LOW);
  delay(1000);
  Serial.print("green\n");
  digitalWrite(PF_3, HIGH);
  delay(1000);
  digitalWrite(PF_3, LOW);
  delay(1000);
*/
  }
}
