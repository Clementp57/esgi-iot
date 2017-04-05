unsigned long myTime;
String text;

void setup() {
  Serial.begin(9600);
  while(!Serial) {
    // blocks program until serial ready  
  }
  Serial.println("Finish Serial initialization");
}

void loop() {
  text = Serial.readString();
  if(text == "printTime") {
    myTime = millis();

    // Prints time since program started
    //Serial.print("Time elapsed since program startup : ");
    Serial.print(" $$> ");
    Serial.print(myTime);
    //Serial.print("ms");
    delay(500); 
  }
}
