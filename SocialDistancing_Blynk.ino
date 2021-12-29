//Library yang dibutuhkan
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Inisialisasi WiFi dan aplikasi blynk
char auth[] = "4g8I7_GuSRZ0HqSavUJ24exh_Kd49vT5";
char ssid[] = "Reff~";
char pass[] = "1sampai10";

//Deklarasi pin
//Ultrasonic
int trigPin = D3;
int echoPin = D4;
//buzzer
int buzz = D5;

//Deklarasi Jarak dan Durasi
float distance, duration;

void setup()
{
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(buzz, OUTPUT);
  Serial.begin(9600); 
  
  Blynk.begin(auth, ssid, pass);
    Serial.println("\nWiFi tersambung!");
    Serial.println("Server aktif!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
  Blynk.run();
  digitalWrite(buzz, LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  Serial.print("Distance : ");
  Serial.println(distance);
  delay(200);

  if(distance <= 180){
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(buzz, LOW);
    Blynk.notify("PERHATIKAN JARAK! JARAK ANDA TERLALU DEKAT!");
  }
  Blynk.virtualWrite(V1, distance);

  delay(100);
}
