int pinInterup = 2;

int pinSegmentA = 4;
int pinSegmentB = 5;
int pinSegmentC = 6;
int pinSegmentD = 7;
int pinSegmentE = 8;
int pinSegmentF = 9;
int pinSegmentG = 10;
int pinSegmentDP = 11;

int valueStart = 9;

void setup() {

  pinMode(pinSegmentA, OUTPUT);
  pinMode(pinSegmentB, OUTPUT);
  pinMode(pinSegmentC, OUTPUT);
  pinMode(pinSegmentD, OUTPUT);
  pinMode(pinSegmentE, OUTPUT);
  pinMode(pinSegmentF, OUTPUT);
  pinMode(pinSegmentG, OUTPUT);
  pinMode(pinSegmentDP, OUTPUT);
  attachInterrupt(pinInterup, number, FALLING);


}

void loop() {
  
}

void number(){

  switch(valueStart){

    case 9:
      digitalWrite(pinSegmentA, HIGH);
      digitalWrite(pinSegmentB, HIGH);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, HIGH);
      digitalWrite(pinSegmentE, LOW);
      digitalWrite(pinSegmentF, HIGH);
      digitalWrite(pinSegmentG, HIGH);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    case 8:
      digitalWrite(pinSegmentA, HIGH);
      digitalWrite(pinSegmentB, HIGH);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, HIGH);
      digitalWrite(pinSegmentE, HIGH);
      digitalWrite(pinSegmentF, HIGH);
      digitalWrite(pinSegmentG, HIGH);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    case 7:
      digitalWrite(pinSegmentA, HIGH);
      digitalWrite(pinSegmentB, HIGH);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, LOW);
      digitalWrite(pinSegmentE, LOW);
      digitalWrite(pinSegmentF, LOW);
      digitalWrite(pinSegmentG, LOW);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    case 6:
      digitalWrite(pinSegmentA, HIGH);
      digitalWrite(pinSegmentB, LOW);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, HIGH);
      digitalWrite(pinSegmentE, HIGH);
      digitalWrite(pinSegmentF, HIGH);
      digitalWrite(pinSegmentG, HIGH);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    case 5:
      digitalWrite(pinSegmentA, HIGH);
      digitalWrite(pinSegmentB, LOW);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, HIGH);
      digitalWrite(pinSegmentE, LOW);
      digitalWrite(pinSegmentF, HIGH);
      digitalWrite(pinSegmentG, HIGH);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    case 4:
      digitalWrite(pinSegmentA, LOW);
      digitalWrite(pinSegmentB, HIGH);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, LOW);
      digitalWrite(pinSegmentE, LOW);
      digitalWrite(pinSegmentF, HIGH);
      digitalWrite(pinSegmentG, HIGH);
      digitalWrite(pinSegmentDP, HIGH);
      delay(500);
    case 3:
      digitalWrite(pinSegmentA, HIGH);
      digitalWrite(pinSegmentB, HIGH);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, HIGH);
      digitalWrite(pinSegmentE, LOW);
      digitalWrite(pinSegmentF, LOW);
      digitalWrite(pinSegmentG, HIGH);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    case 2:
      digitalWrite(pinSegmentA, HIGH);
      digitalWrite(pinSegmentB, HIGH);
      digitalWrite(pinSegmentC, LOW);  
      digitalWrite(pinSegmentD, HIGH);
      digitalWrite(pinSegmentE, HIGH);
      digitalWrite(pinSegmentF, LOW);
      digitalWrite(pinSegmentG, HIGH);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    case 1:
      digitalWrite(pinSegmentA, LOW);
      digitalWrite(pinSegmentB, HIGH);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, LOW);
      digitalWrite(pinSegmentE, LOW);
      digitalWrite(pinSegmentF, LOW);
      digitalWrite(pinSegmentG, LOW);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    case 0:
      digitalWrite(pinSegmentA, HIGH);
      digitalWrite(pinSegmentB, HIGH);
      digitalWrite(pinSegmentC, HIGH);  
      digitalWrite(pinSegmentD, HIGH);
      digitalWrite(pinSegmentE, HIGH);
      digitalWrite(pinSegmentF, HIGH);
      digitalWrite(pinSegmentG, LOW);
      digitalWrite(pinSegmentDP, LOW);
      delay(500);
    
  }
  
  
  
}

