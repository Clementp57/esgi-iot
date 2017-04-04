int buttonPin = 3;
int ledPin = 4;
bool button = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  button = digitalRead(buttonPin);
  Serial.println(button);
  digitalWrite(ledPin, button);
}
