// library
#include <Arduino.h>
#include <Servo.h>
// servo setup
Servo servo1;
Servo servo2;
int servo1pin = 5;
int servo2pin = 6;
// joystick1 setup
const int joystick1_Xpin = A0;
const int joystick1_Ypin = A1;
const int joystick1_buttonPin = 3;
// time
unsigned long StartTime = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(joystick1_buttonPin, INPUT_PULLUP);
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
}

void loop()
{
  int joyX = analogRead(joystick1_Xpin);
  int joyY = analogRead(joystick1_Ypin);
  if (millis() - StartTime >= 15)
  {
    int servo1_X_angle = map(joyX, 0, 1023, 0, 180);
    servo1.write(servo1_X_angle);
    Serial.println(servo1_X_angle);
    int servo2_Y_angle = map(joyY, 0, 1023, 0, 180);
    servo2.write(servo2_Y_angle);
  }
}
