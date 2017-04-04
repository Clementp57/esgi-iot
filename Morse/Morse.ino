String text;
int ledPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  while (Serial.available()==0) {             //Wait for user input
    
  }
  text =Serial.readString();   
  for(i=0;i<text.length();i++){
  switch(text.charAt(i)) {
    case 'a':
      point();
      tiret();
    break;
    case 'b':
      tiret();
      point();
      point();
      point();
    break;
    case 'c':
      tiret();
      point();
      tiret();
      point();
    break;
    case 'd':
      tiret();
      point();
      point();
    break;
    case 'e':
      point();
    break;
    case 'f':
      point();
      point();
      tiret();
      point();
    break;
    case 'g':
      tiret();
      tiret();
      point();
    break;
    case 'h':
      point();
      point();
      point();
      point();
    break;
    case 'i':
      point();
      point();
    break;
    case 'j':
      point();
      tiret();
      tiret();
      tiret();
    break;
    case 'k':
      tiret();
      point();
      tiret();
    break;
    case 'l':
      point();
      tiret();
      point();
      point();
    break;
    case 'm':
      tiret();
      tiret();
    break;
    case 'n':
      tiret();
      point();
    break;
    case 'o':
      tiret();
      tiret();
      tiret();
    break;
    case 'p':
      point();
      tiret();
      tiret();
      point();
    break;
    case 'q':
      tiret();
      tiret();
      point();
      tiret();
    break;
    case 'r':
      point();
      tiret();
      point();
    break;
    case 's':
      point();
      point();
      point();
    break;
    case 't':
      tiret();
     break;
    case 'u':
      point();
      point();
      tiret();
     break;
    case 'v':
      point();
      point();
      point();
      tiret();
    break;
    case 'w':
      point();
      tiret();
      tiret();
     break;
    case 'x':
      tiret();
      point();
      point();
      tiret();
    break;
    case 'y':
      tiret();
      point();
      tiret();
      tiret();
    break;
    case 'z':
      tiret();
      tiret();
      point();
      point();
    break;
    
  }
  }
}

void point() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(100);
}

void tiret() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(100);
}

