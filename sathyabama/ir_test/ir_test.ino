#include <Servo.h>
int servo = 5;
Servo servo_1;
void setup(){
  Serial.begin(9600);
  
  servo_1.attach(servo);
}

void loop(){
  servo_1.write(0);
  delay(1000);
  servo_1.write(90);
  delay(1000);
  servo_1.write(180);
  delay(1000);
  
}
