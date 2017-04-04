void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available()) {
    // Si le Serial est dispo on lit une valeur rentrée par l'utilisateur
    // Puis on la print
    int lu = Serial.read();
    Serial.println(lu):
  } else {
    Serial.println("Rien");
  }
  
  delay(2000);
}
