// library
#include <Arduino.h>
#include <Servo.h>
#include <EasyJoystick.h>
// servo setup
Servo servo1;
Servo servo2;
int servo1pin = 5;
int servo2pin = 6;
// joystick setup
EasyJoystick joystick1;
EasyJoystick joystick2;
const int joystick1_buttonPin = 3;
const int joystick2_buttonPin = 4;

void setup()
{
  joystick1.begin(A0, A1, true, true); // joystick.begin(xPin, yPin, flipX, flipY)
  joystick2.begin(A2, A3, true, true);
  Serial.begin(115200);
  pinMode(joystick1_buttonPin, INPUT_PULLUP);
  pinMode(joystick2_buttonPin, INPUT_PULLUP);
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
  servo1.write(65);
  servo2.write(65);
}

void loop()
{
  // joystick1 and servo1 control
  joystick1.loop();
  if (joystick1.isUp())
  {
    servo1.write(115);
  }
  else if (joystick1.isDown())
  {
    servo1.write(65);
  }
  else if (joystick1.isLeft())
  {
    servo1.write(50);
  }
  else if (joystick1.isRight())
  {
    servo1.write(170);
  }
  else if (digitalRead(joystick1_buttonPin) == LOW)
  {
    servo1.write(65);
  }
  // joystick2 and servo2 setup
  joystick2.loop();
  if (joystick2.isUp())
  {
    servo2.write(115);
  }
  else if (joystick2.isDown())
  {
    servo2.write(65);
  }
  else if (joystick2.isLeft())
  {
    servo2.write(50);
  }
  else if (joystick2.isRight())
  {
    servo2.write(170);
  }
  else if (digitalRead(joystick2_buttonPin) == LOW)
  {
    servo2.write(65);
  }
}
