void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(A0) < 512) {
    digitalWrite(3, HIGH);
    Serial.println("LED On");
  } else {
    digitalWrite(3, LOW);
    Serial.println("LED Off");
  }
  delay(1000);
}
