int en_L1 = 6;
int en_L2 = 5;



void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(en_L1,OUTPUT);
 pinMode(en_L2,OUTPUT);
}

void loop() {
  analogWrite(en_L1,200);
  digitalWrite(en_L2,LOW);
  delay(1000);
   analogWrite(en_L1,LOW);
  digitalWrite(en_L2,200);
  delay(1000);
  // put your main code here, to run repeatedly:

}
