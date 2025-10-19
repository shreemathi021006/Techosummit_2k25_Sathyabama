int en_l1 = 5;
int en_l2= 6;
int en_r1 = 9;
int en_r2 = 10;


void setup() {
  Serial.begin(9600);
  pinMode(en_l1,OUTPUT);
  pinMode(en_l2,OUTPUT);
  pinMode(en_r1,OUTPUT);
  pinMode(en_r2,OUTPUT);
  // put your setup code here, to run once:

}
void forward(){
  analogWrite (en_l1,200);
  digitalWrite(en_l2,LOW);
  analogWrite( en_r1,200);
  digitalWrite(en_r2,LOW);
  
}
void left(){
  analogWrite (en_l1,0);
  digitalWrite(en_l2,LOW);
  analogWrite( en_r1,200);
  digitalWrite(en_r2,LOW);
  
}
void right(){
  analogWrite (en_l1,200);
  digitalWrite(en_l2,LOW);
  analogWrite( en_r1,0);
  digitalWrite(en_r2,LOW);
 
  
}
void stop_m(){
  analogWrite (en_l1,0);
  digitalWrite(en_l2,LOW);
  analogWrite( en_r1,0);
  digitalWrite(en_r2,LOW);
  
}

void loop() {
  forward();
  delay(1000);
  left();
  delay(1000);
  right();
  delay(1000);
  // put your main code here, to run repeatedly:

}
