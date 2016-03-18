void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.read() == 'o') {
    digitalWrite(3, HIGH);
    Serial.println("LED On");
  } else if (Serial.read() == 'f'){
    digitalWrite(3, LOW);
    Serial.println("LED Off");
  }
  delay(1000);
}
