#include <Servo.h>

#define SERVO_PINOUT 8
#define ANGLE_CHANGE 180

Servo myServo;

int pos;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(SERVO_PINOUT, OUTPUT);
  int origPos = 0;
  Serial.println("begin");
  myServo.write(0);
  delay(5000);
  Serial.println("forward");
  myServo.attach(SERVO_PINOUT);
  for (int pos = origPos; pos <= origPos + ANGLE_CHANGE; pos++) {
    myServo.write(pos);
    delay(10);
  }
  
  delay(1000);
  Serial.println("backward");
  for (int pos = origPos + ANGLE_CHANGE; pos >= 0; pos--) {
    myServo.write(pos);
    delay(10);
  }
  Serial.println("done!");
  exit(0);
  
}

void loop() {}

void moveServo(int angle) {
  myServo.write(angle);
  delay(50);
}
