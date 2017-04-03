int ledPin = 3;
int potentiometerAnalogPin = 0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potentiometerAnalogPin);
  Serial.print(val*254/1024);
  Serial.print("\n");
  analogWrite(ledPin, val*254/1024);
}
