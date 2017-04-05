int SER_Pin = 8;
int RCLK_Pin = 9;
int SRCLK_Pin = 10;

#define number_of_74hc595 1
#define numOfRegisterPins 8

boolean registers[numOfRegisterPins];

void setup() {
  Serial.begin(9600);
  
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  pinMode(15, INPUT);
  
  // reset all 74hc595 pins
  clearRegisters();
  writeRegisters();
}

void loop() {
  //test
  int test = digitalRead(15);
  Serial.println(test);
  
  setRegisterPin(1, LOW);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, LOW);
  setRegisterPin(4, HIGH);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
  writeRegisters();
}

void clearRegisters() {
  for(int i=numOfRegisterPins-1;i>=0;i--) {
    registers[i] = LOW;
  }
}

void writeRegisters() {
  digitalWrite(RCLK_Pin, LOW);
  for(int i=numOfRegisterPins-1;i>=0;i--) {
    digitalWrite(SRCLK_Pin, LOW);
    int val = registers[i];
    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);
  }
  digitalWrite(RCLK_Pin, HIGH);
}

void setRegisterPin(int index, int value) {
  registers[index] = value;
}

