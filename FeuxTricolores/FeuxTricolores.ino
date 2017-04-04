int redLedPin1 = 7;
int orangeLedPin1 = 8;
int greenLedPin1 = 9;

int redLedPin2 = 4;
int orangeLedPin2 = 5;
int greenLedPin2 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLedPin1, OUTPUT);
  pinMode(orangeLedPin1, OUTPUT);
  pinMode(greenLedPin1, OUTPUT);
  pinMode(redLedPin2, OUTPUT);
  pinMode(orangeLedPin2, OUTPUT);
  pinMode(greenLedPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLedPin1, HIGH);
  digitalWrite(greenLedPin2, HIGH);
  delay(3000);
  digitalWrite(greenLedPin2, LOW);
  digitalWrite(orangeLedPin2, HIGH);
  delay(1000);
  digitalWrite(orangeLedPin2, LOW);
  digitalWrite(redLedPin2, HIGH);
  digitalWrite(redLedPin1, LOW);
  digitalWrite(greenLedPin1, HIGH);
  delay(3000);
  digitalWrite(greenLedPin1, LOW);
  digitalWrite(orangeLedPin1, HIGH);
  delay(1000);
  digitalWrite(orangeLedPin1, LOW);
  digitalWrite(redLedPin2, LOW);

}
