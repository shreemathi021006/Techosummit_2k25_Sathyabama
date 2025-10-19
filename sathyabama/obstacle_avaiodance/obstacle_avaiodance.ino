int en_L1 = 6;
int en_L2 = 5;
int en_R1= 11;
int en_R2= 10;
int trig_f = 12;
int echo_f = 13;
int trig_l = 9;
int echo_l = 8;
long dis_f ;
long dis_l;

void setup(){
  Serial.begin(9600);
  pinMode(en_L1,OUTPUT);
  pinMode(en_L2,OUTPUT);
  pinMode(en_R1,OUTPUT);
  pinMode(en_R2,OUTPUT);
  pinMode(trig_f,OUTPUT);
  pinMode(trig_l,OUTPUT);
  pinMode(echo_f,INPUT);
  pinMode(echo_l,INPUT);
}

void get_dis_f(){
  digitalWrite(trig_f,LOW);
  delay(2);
  digitalWrite(trig_f,HIGH);
  delay(10);
  digitalWrite(trig_f,LOW);

  long dur = pulseIn(echo_f,HIGH);
  dis_f =  (0.034*dur)/2;
}

void get_dis_l(){
  digitalWrite(trig_l,LOW);
  delay(2);
  digitalWrite(trig_l,HIGH);
  delay(10);
  digitalWrite(trig_l,LOW);

  long dur = pulseIn(echo_l,HIGH);
  dis_l =  (0.034*dur)/2; 
}

void forward(){
  analogWrite(en_L1,200);
  digitalWrite(en_L2,LOW);
  analogWrite(en_R1,200);
  digitalWrite(en_R2,LOW);
  
}

void left(){
  analogWrite(en_L1,0);
  digitalWrite(en_L2,LOW);
  analogWrite(en_R1,200);
  digitalWrite(en_R2,LOW);
  delay(2000);
}

void right(){
  analogWrite(en_L1,200);
  digitalWrite(en_L2,LOW);
  analogWrite(en_R1,0);
  digitalWrite(en_R2,LOW);
  delay(2000);
}

void stop_bot (){
  analogWrite(en_L1,0);
  digitalWrite(en_L2,LOW);
  analogWrite(en_R1,0);
  digitalWrite(en_R2,LOW);
}

void loop(){
get_dis_l();
get_dis_f();
if (dis_f<12){
  stop_bot();
  right();
  //Serial.print("dis_f:");
  //Serial.println(dis_f);
  //if(dis_l<12){
    //right();
    //Serial.print("dis_l:");
  Serial.println(dis_l);
  forward();
  }
  else {
    forward();
  }
delay(200);
}
