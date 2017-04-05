int buttonPin = 2;
int ledPin = 4;
int state = LOW;

void setup() {
  //pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(buttonPin, interrupt, RISING);
}

void loop() {
  //int test = digitalRead(buttonPin);
  //digitalWrite(ledPin, test);
  //Serial.println(test);
}

void interrupt() {
  Serial.println("interrupting !");
  state = !state;
  digitalWrite(ledPin, state);
}

