int trig = 12;
int echo = 11;
long lecture_echo;
long cm;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo, HIGH);
  cm = lecture_echo / 58;
  //Serial.print("Distance m : ");
  Serial.println(cm);
  if(cm < 30) {
    Serial.println("PASSAGE");
  }
  delay(900);
}
