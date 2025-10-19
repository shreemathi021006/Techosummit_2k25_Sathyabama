int echo_1 = 2;
int trig_1 = 3;
long dis_f;

void setup() {
  Serial.begin(9600);
  pinMode(echo_1, INPUT);
  pinMode(trig_1, OUTPUT);
}

void loop() {
  // Trigger pulse
  digitalWrite(trig_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_1, LOW);

  // Measure echo
  long dur = pulseIn(echo_1, HIGH, 30000); // timeout = 30 ms
    dis_f = (0.034 * dur) / 2;
   
    Serial.println(dis_f);

  delay(100);
}
