#include <SoftwareSerial.h>
int irPin=2; 
int ledPin=3;
int rx=10;
int tx=11;

int count=0;
int isPresent=0;

char test;

SoftwareSerial BTserial(rx, tx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  BTserial.begin(38400); 
  
  pinMode(ledPin, OUTPUT);
  pinMode(irPin, INPUT);  
  //pinMode(tx, INPUT);
  //pinMode(rx, OUTPUT);
  BTserial.println('serial bluetooth begin!');
}

void loop() {
  // passage via infrarouge
  /*int irValue = digitalRead(irPin);
  if(irValue == 0 && isPresent == 0) {
    count++;
    isPresent = 1;
    Serial.println(count);
  } 
  if(irValue == 1 && isPresent == 1) {
    isPresent = 0;
  }*/

  // bluetooth
  if (BTserial.available()) {
    test = BTserial.read();
    Serial.println(BTserial.read());
    Serial.write(test);
    //BTserial.write(Serial.write(Serial.read()));
  }
 
  if (Serial.available()) {
    BTserial.write(Serial.read());
  }
  
  //delay(150);
}


