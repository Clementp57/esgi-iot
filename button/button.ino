int buttonPin = 3;
int ledPin = 4;
bool button = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(buttonPin, interrupt, CHANGE);
}

void loop() {
  button = digitalRead(buttonPin);
  //Serial.println(button);
  digitalWrite(ledPin, button);
}

void interrupt() {
  Serial.println("interrupting !");
  state = !state;
}

