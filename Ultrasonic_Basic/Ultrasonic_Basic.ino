/* 
 *  AUB Robotics Club
 *  Ultrasonic sensor sample code
 *  
 *  Prints the current distance every second
 *  
 *  by Samer Abuthaher
 *  sma90@mail.aub.edu
 *  Modified from 
 *  http://www.arduino.cc/en/Tutorial/Ping   
 *  by Tom Igoe
 *  
 *  Code is released under The MIT License, check LICENSE.txt
 *  Copyright (c) 2016 Samer Abuthaher
 */

const int trigPin = 6;
const int echoPin = 7;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  //Setup pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  long distance = getDistanceCM();
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();

  delay(1000);
    
}

long getDistanceCM() {
  //Copy-pasted from the PING))) sensor code sample with minor changes
  
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  return cm;

}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
