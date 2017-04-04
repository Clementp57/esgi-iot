int ledPin = 3;
int ledPinInvert = 5;
int potentiometerAnalogPin = 0;
int val = 0;
int output = 0;
int outputInvert = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinInvert, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potentiometerAnalogPin);
  output = val*254/1024;
  outputInvert = 255-val*254/1024;
  Serial.print(output);
  Serial.print("\n");
  Serial.print(outputInvert);
  Serial.print("\n");
  analogWrite(ledPin, output);
  analogWrite(ledPinInvert, outputInvert);
}
