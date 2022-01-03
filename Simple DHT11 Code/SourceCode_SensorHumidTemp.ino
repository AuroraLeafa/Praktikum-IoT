#include <SoftwareSerial.h>
#include<DHT.h>
#define DHTPIN 11
#define DHTTYPE DHT11
DHT dht (DHTPIN,DHTTYPE);

/*
 * Nama : Refansyach .S 
 * NPM  : 065119226
 * Kelas : Gab. A
 */

//Insialisasi Variabel
float h,t;
int Green0 = 2;
int Yellow0 = 3;
int Red0 = 4;
int Green1 = 5;
int Yellow1 = 6;
int Red1 = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(Green0, OUTPUT);
  pinMode(Yellow0, OUTPUT);
  pinMode(Red0, OUTPUT);
  pinMode(Green1, OUTPUT);
  pinMode(Yellow1, OUTPUT);
  pinMode(Red1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  h = dht.readHumidity();
  t = dht.readTemperature();

//Kondisian LED untuk Humidity/Kelembapan
if(h>=46 && h < 64){
    digitalWrite(Green0, HIGH);
    digitalWrite(Yellow0, LOW);
    digitalWrite(Red0, LOW);
  } 
  else if(h <= 45 && h > 42 || h >= 64 && h < 68){
    digitalWrite(Green0, LOW);
    digitalWrite(Yellow0, HIGH);
    digitalWrite(Red0, LOW);
  } 
  else if(h >= 68 || h <= 42){
    digitalWrite(Green0, LOW);
    digitalWrite(Yellow0, LOW);
    digitalWrite(Red0, HIGH);  
  } 

//Kondisian LED untuk Temperature/Suhu
if(t >= 21 && t < 26){
    digitalWrite(Green1, HIGH);
    digitalWrite(Yellow1, LOW);
    digitalWrite(Red1, LOW);
  } 
  else if(t >= 26 && t < 28 || t >= 11 && t <= 19){
    digitalWrite(Green1, LOW);
    digitalWrite(Yellow1, HIGH);
    digitalWrite(Red1, LOW);
  } 
  else if(t >= 28 || t <= 10){
    digitalWrite(Green1, LOW);
    digitalWrite(Yellow1, LOW);
    digitalWrite(Red1, HIGH);  
  } 


  
  Serial.write(254);
  Serial.write(1);
  Serial.write(254);
  Serial.write(128);
  Serial.print("Temp: ");
  Serial.write(134);
  Serial.print(t);
  Serial.write(135);
  Serial.print("C");
  Serial.write(254);
  Serial.write(192);
  Serial.print("Humi: ");
  Serial.write(197);
  Serial.print(h);
  Serial.write(198);
  Serial.print("% ");
  delay(100);
}
