void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(5, 300);
  delay(1000);
  noTone(5);
  delay(1000);
}
