//Library yang dibutuhkan
#include <ESP8266WiFi.h> //Agar NodeMCU dapat tersambung ke WiFi
#include <BlynkSimpleEsp8266.h> //Agar dapat tersambung ke aplikasi Blynk

//Inisialisasi WiFi dan aplikasi blynk
char auth[] = "4g8I7_GuSRZ0HqSavUJ24exh_Kd49vT5"; //Kode Autentikasi agar tersambung dengan project di aplikasi Blynk
char ssid[] = "Reff~"; //Username WiFi
char pass[] = "1sampai10"; //Password WiFi

//Deklarasi pin
//Ultrasonic
int trigPin = D3; //Trigger Pin dimasukkan ke Pin D3 di NodeMCU
int echoPin = D4; //Echo Pin dimasukkan ke Pin D4 di NodeMCU
//buzzer
int buzz = D5; //Buzzer Pin dimasukkan ke Pin D5 di NodeMCU

//Deklarasi Jarak dan Durasi
float distance, duration;

void setup()
{
  pinMode(echoPin, INPUT); //Echo sebagai input  
  pinMode(trigPin, OUTPUT); //Trigger sebagai Output
  pinMode(buzz, OUTPUT); //Buzzer sebagai output
  Serial.begin(9600); //Serial begin agar tampil pada serial monitor
  
  Blynk.begin(auth, ssid, pass); //Inisialisasi Blynk agar terhubung ke WiFi dan Project
    Serial.println("\nWiFi tersambung!");
    Serial.println("Server aktif!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP()); //Menampilkan alamat IP dari device tersambung 
}

void loop()
{
  Blynk.run(); //Menghubungkan ke Blynk
  digitalWrite(buzz, LOW); //Inisialisasi keadaan awal buzzer
  digitalWrite(trigPin, LOW); //Inisialisasi keadaan awal Trigger
  delayMicroseconds(10); //Delay 10 ms
  digitalWrite(trigPin, HIGH); //Trigger pin menembakan sinyal
  delayMicroseconds(10); //delay 10ms
  digitalWrite(trigPin, LOW); //trigger pin berhenti menembakkan sinyal
  
  duration = pulseIn(echoPin, HIGH); //Menghitung durasi dengan cara, echopin menyala untuk menerima sinyal yang ditembakkan trigger
  distance = (duration / 2) / 29.1; //menghitung Jarak dengan cara, Durasi dibagi 2 lalu dibagi 29.1
  
  Serial.print("Distance : ");
  Serial.println(distance); //menampilkan jarak yang didapat
  delay(200);

  if(distance <= 180){ //pengkondisian jika jarak kurang atau sama dengan 180 maka
    digitalWrite(buzz, HIGH); //buzzer menyala
    delay(1000); //selama 1 detik
    digitalWrite(buzz, LOW); //lalu buzzer mati
    Blynk.notify("PERHATIKAN JARAK! JARAK ANDA TERLALU DEKAT!"); //selanjutnya akan memberikan notifikasi ke blynk bahwa jarak terlalu dekat
  }
  Blynk.virtualWrite(V1, distance); //mengirimkan jarak sekarang ke aplikasi blynk

  delay(100);
}
