int redLedPin = 7;
int orangeLedPin = 8;
int greenLedPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLedPin, OUTPUT);
  pinMode(orangeLedPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLedPin, HIGH);
  delay(5000);
  digitalWrite(redLedPin, LOW);

  digitalWrite(orangeLedPin, HIGH); 
  delay(1000);
  digitalWrite(orangeLedPin, LOW);
  
  digitalWrite(greenLedPin, HIGH);
  delay(5000); 
  digitalWrite(greenLedPin, LOW);
}
