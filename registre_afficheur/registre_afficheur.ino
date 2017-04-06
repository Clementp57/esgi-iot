int SER_Pin = 8;
int RCLK_Pin = 9;
int SRCLK_Pin = 10;
int buttonPin = 2;

#define number_of_74hc595 1
#define numOfRegisterPins 8

boolean registers[numOfRegisterPins];

boolean dice[16][7] = {
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW},//0
  {LOW,HIGH,HIGH,LOW,LOW,LOW,LOW},//1
  {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH},//2
  {HIGH,HIGH,HIGH,HIGH,LOW,LOW,HIGH},//3
  {LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH},//4
  {HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH},//5
  {HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH},//6
  {HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW},//7
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},//8
  {HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH},//9
  {HIGH,HIGH,HIGH,LOW,HIGH,HIGH,HIGH},//A
  {LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH},//B
  {HIGH,LOW,LOW,HIGH,HIGH,HIGH,LOW},//C
  {LOW,HIGH,HIGH,HIGH,HIGH,LOW,HIGH},//D
  {HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH},//E
  {HIGH,LOW,LOW,LOW,HIGH,HIGH,HIGH},//F
  };

void setup() {
  Serial.begin(9600);
  
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  
  // reset all 74hc595 pins
  clearRegisters();
  writeRegisters();

  attachInterrupt(buttonPin, randomDice, FALLING);
  
}

void loop() {
}

void randomDice() {
  int diceNum = random(0,16);
  for(int i = 1;i<=7;i++) {
    setRegisterPin(i, dice[diceNum][i-1]);
  }
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

