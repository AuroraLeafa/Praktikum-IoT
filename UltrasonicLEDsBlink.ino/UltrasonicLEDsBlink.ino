#include <SoftwareSerial.h>

//Declare Trigger and Echo pin
int echo = 2;
int trig = 3;
int led1 = 11;
int led2 = 12;
int led3 = 13;

//Declare for Echo and Distance
int duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delay(100);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.write(254);
  Serial.write(1);
  Serial.write(254);
  Serial.write(128);
  Serial.print(distance);
  delay(100);

  if(distance>350){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  } 
  else if(distance > 250){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } 
  else if(distance > 0){
    digitalWrite(led1, HIGH);    
    delay(100);                       
    digitalWrite(led1, LOW);   
    delayMicroseconds(100);    
    digitalWrite(led2, HIGH);   
    delay(100);                       
    digitalWrite(led2, LOW);   
    delayMicroseconds(100);                       
    digitalWrite(led3, HIGH);    
    delay(100);                       
    digitalWrite(led3, LOW);    
    delayMicroseconds(100);    
    
  }
}
