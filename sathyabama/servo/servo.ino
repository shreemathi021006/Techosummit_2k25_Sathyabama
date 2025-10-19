#include <Servo.h>   // include Servo library

Servo myServo;       // create servo object

void setup() {
  myServo.attach(8); // attach servo signal wire to pin 9
}

void loop() {
  // Sweep from 0° to 180°
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);   // move servo to 'angle'
    delay(15);              // wait for movement
  }

  // Sweep from 180° back to 0°
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);
  }
}
