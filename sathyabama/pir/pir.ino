int out_p = 7;
int out;

void setup() {
  Serial.begin(9600);
  pinMode(out_p,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  out = digitalRead(out_p);
  Serial.println(out);
  delay(100);
  // put your main code here, to run repeatedly:

}
