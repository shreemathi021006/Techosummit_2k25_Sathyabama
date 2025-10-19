#include <Wire.h>                // For I2C
#include <SoftwareSerial.h>

char c;
SoftwareSerial BT (12,13);
#include <Adafruit_GFX.h>        // Graphics library
#include <Adafruit_SSD1306.h>    // OLED driver

#define SCREEN_WIDTH 128 // OLED width
#define SCREEN_HEIGHT 64 // OLED height

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Create display object
int enb = 9;
int en_l1 = 11;
int en_l2= 10;
int en_r1 = 5;
int en_r2 = 6;
int echo_1 = 2;
int trig_1 = 3;
long dis_f;

int dis;
  
void setup(){
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(enb,OUTPUT);
  pinMode(en_l1,OUTPUT);
  pinMode(en_l2,OUTPUT);
  pinMode(en_r1,OUTPUT);
  pinMode(en_r2,OUTPUT);
   pinMode(echo_1, INPUT);
  pinMode(trig_1, OUTPUT);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.begin(9600);
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Stop here if OLED not found
  }
}
void print_p(){
  if(dis<10){
     display.clearDisplay();              // Clear screen
  display.setTextSize(2);              // Text size
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 20);
  // Start at top-left
  
  display.println("box taken");
  display.display();   
  }
}
void get_dis(){
  digitalWrite(trig_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_1, LOW);

  // Measure echo
  long dur = pulseIn(echo_1, HIGH, 30000); // timeout = 30 ms
    dis = (0.034 * dur) / 2;
   
    Serial.println(dis);
}
void forward(){
  analogWrite(enb,220);
  digitalWrite(en_l1,HIGH);
  digitalWrite(en_l2,LOW);
  analogWrite(en_r1,200);
  digitalWrite(en_r2, LOW);
 
  
}

void left(){
  analogWrite(enb,0);
  digitalWrite(en_l1,HIGH);
  digitalWrite(en_l2,LOW);
  analogWrite( en_r1,220);
  digitalWrite(en_r2,LOW);
  
}
void right(){
  analogWrite(enb,220);
  digitalWrite(en_l1,HIGH);
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

void loop(){
  get_dis();
  print_p();
  if(BT.available()){
  c = BT.read();
  Serial.println(c);
  if (c == 'F')
  {
  forward();
   display.clearDisplay();              // Clear screen
  display.setTextSize(2);              // Text size
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 0);
  
  display.println("forward");
  display.display(); }
  else if (c == 'L'){
  left();
  display.clearDisplay();              // Clear screen
  display.setTextSize(2);              // Text size
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 0);
  
  display.println("left");
  display.display();}
  else if (c == 'R'){
  right();
  display.clearDisplay();              // Clear screen
  display.setTextSize(2);              // Text size
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 0);
  
  display.println("right");
  display.display();   }
  else if (c == 'S'){
  stop_m();
  display.clearDisplay();              // Clear screen
  display.setTextSize(2);              // Text size
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 0);
  
  display.println("stop");
  display.display();   }
  //if ((digitalRead(l_ir) == 0) && digitalRead(c_ir) == 1 && digitalRead(r_ir) == 0){
    //forward();
    //display.clearDisplay();            display.setTextSize(1);              display.setTextColor(SSD1306_WHITE); display.setCursor(0, 10);            display.println("forward"); display.display();}
  //else if (digitalRead(l_ir )== 1 && digitalRead(c_ir) == 1 && digitalRead(r_ir) == 0) {
   // slow();
    //left();
  
 // else if (digitalRead(l_ir) == 1 && digitalRead(c_ir) == 0 && digitalRead(r_ir) == 0){
    //slow();
    //left();
 
 // else if (digitalRead(l_ir) == 0 && digitalRead(c_ir) == 1 && digitalRead(r_ir) == 1){
   // slow();
   // right();
   // display.clearDisplay();              // Clear screen
 
  //}
  //else if (digitalRead(l_ir) == 0 && digitalRead(c_ir) == 0 && digitalRead(r_ir) == 1){
    //slow();
   // right();
    
  //}
 // else if (digitalRead(l_ir) == 1 && digitalRead(c_ir) == 1 && digitalRead(r_ir) == 1){
    //top_m();
 
    //Serial.println(dis);
   // if (dis<10 ){
      //if (C == 1){
      
    
    
 // else if (digitalRead(l_ir) == 0 && digitalRead(c_ir) == 0 && digitalRead(r_ir) == 0){
   // forward();
  }
  }
