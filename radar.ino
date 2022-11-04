#include <Adafruit_NeoPixel.h>
//First Ultrasonic
#define trigPin D1
#define echoPin D2 
//Second Ultrasonic
#define trigPin2 D7
#define echoPin2 D8
//LED Strip
#define pixelCount 24 //Number of lights
#define pixelPin D1

long duration;
long duration2;
float distance; //In centimeters
float distance2;
bool contact;
int pos;

Adafruit_NeoPixel ring(pixelCount, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Second Ultrasonic Sensor
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  ring.begin();
  ring.setBrightness(25);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Tell the ultrasonic sensor to fire
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Duration in milliseconds
  distance = duration * 0.0343 / 2; //Distance in centimeters

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  //Second Ultrasonic
  digitalWrite(trigPin2, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.0343 /2;

  //Serial.println("Sensor 1 = " + String(distance));
  //Serial.println("Sensor 2 = " + String(distance2));

  if (distance <= 40) {
    Serial.println("Contact!");
    Serial.println(distance);
    delay(500);
  } else {
    Serial.println("No Contact!");
    Serial.println(distance);
    delay(500);
  }
  
}
