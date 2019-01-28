#define ser_pin 9
#define JSX A0
#define JSY A1

#include <Servo.h>

Servo my_servo;

int servoPosition = 90;

int acc = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  my_servo.attach(ser_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  acc = (analogRead(JSX) - 512)/50;

  servoPosition = constrain((servoPosition + acc), 1, 180);
  Serial.println(analogRead(JSX));
  my_servo.write(servoPosition);

  delay(50);
  
}
