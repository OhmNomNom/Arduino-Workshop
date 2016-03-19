void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  static int V = 255;
  analogWrite(3, V);
  V -= 1;
  if(V < 0) V = 255;
  delay(20);
  
}
