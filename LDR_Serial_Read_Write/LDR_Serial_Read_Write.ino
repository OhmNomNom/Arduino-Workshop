void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  character = Serial.read();
  if(character == 'o') {
    digitalWrite(3, HIGH);
    Serial.println("LED On");
  } else if (character == 'f'){
    digitalWrite(3, LOW);
    Serial.println("LED Off");
  }
  delay(1000);
}
