// library
#include <Arduino.h>
#include <Servo.h>
// servo setup
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int servo1pin = 4;
int servo2pin = 5;
int servo3pin = 6;
int servo4pin = 7;
// joystick setup
const int joystick1_Xpin = A0;
const int joystick1_Ypin = A1;
const int joystick2_Xpin = A2;
const int joystick2_Ypin = A3;
// time
unsigned long StartTime = 0;

void setup()
{
  Serial.begin(9600);
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
  servo3.attach(servo3pin);
  servo4.attach(servo4pin);
  // rotate all servos to 90 degree
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
}

void loop()
{
  if (millis() - StartTime >= 50)
  {
    // reading value from joystick
    int joy1X = analogRead(joystick1_Xpin);
    int joy1Y = analogRead(joystick1_Ypin);
    int joy2X = analogRead(joystick2_Xpin);
    int joy2Y = analogRead(joystick2_Ypin);
    // mapping joystick value to servo angle
    int servo1_angle = map(joy1X, 0, 1023, 0, 180);
    int servo2_angle = map(joy1Y, 0, 1023, 0, 180);
    int servo3_angle = map(joy2X, 0, 1023, 0, 180);
    int servo4_angle = map(joy2Y, 0, 1023, 0, 180);
    // control servo
    servo1.write(servo1_angle);
    servo2.write(servo2_angle);
    servo3.write(servo3_angle);
    servo4.write(servo4_angle);

    StartTime = millis();
  }
}