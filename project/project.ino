#include <SoftwareSerial.h>
int irPin=2; 
int ledPin=3;
int rx=10;
int tx=11;

int count=0;
int isPresent=0;

SoftwareSerial BTserial(rx, tx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTserial.begin(9600); 
  
  pinMode(ledPin, OUTPUT);
  pinMode(irPin, INPUT);  
}
void loop() {
  int irValue = digitalRead(irPin);

  if(irValue == 0 && isPresent == 0) {
    count++;
    isPresent = 1;
    Serial.println(count);
  } 

  if(irValue == 1 && isPresent == 1) {
    isPresent = 0;
  }
  
  if (BTserial.available())
    Serial.write(BTserial.read());
 
  if (Serial.available())
    BTserial.write(Serial.read());
  
  delay(150);
}


