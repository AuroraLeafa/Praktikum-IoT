#define WIFI_NAME "Reff~"
#define WIFI_PASSWORD "1sampai10"
#define DEVICE_ID 2
#define DEVICE_NAME "ESP8266"
#define TOKEN "~1136722_rYdSoBJwZu29fsMUIjAD3iIj"

#include <RemoteMe.h>
#include <RemoteMeSocketConnector.h>
#include <ESP8266WiFi.h>


RemoteMe& remoteMe = RemoteMe::getInstance(TOKEN, DEVICE_ID);

//*************** CODE FOR COMFORTABLE VARIABLE SET *********************

inline void setBuzzer(boolean b) {remoteMe.getVariables()->setBoolean("Buzzer", b); }
//Declare Trigger and Echo pin
int TRIG = D3;
int ECHO = D4;
int BUZZ = D5;

//Declare for Echo and Distance
float distance, duration;

//*************** IMPLEMENT FUNCTIONS BELOW *********************

void onBuzzerChange(boolean b) {
	Serial.printf("onBuzzerChange: b: %d\n",b);
	digitalWrite(BUZZ, b?HIGH:LOW);
}


void setup() {
	pinMode(ECHO, INPUT);
	pinMode(TRIG, OUTPUT);
	pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
	WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
	}

    Serial.println("\nWiFi tersambung!");
    Serial.println("Server aktif!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  
	remoteMe.getVariables()->observeBoolean("Buzzer" ,onBuzzerChange);
	remoteMe.setConnector(new RemoteMeSocketConnector());
	remoteMe.sendRegisterDeviceMessage(DEVICE_NAME);
}

void loop() {
	digitalWrite(BUZZ, LOW);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(10);
	digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
	duration = pulseIn(ECHO, HIGH);
	distance = (duration / 2) / 29.1;
  //distance = (duration * .0343)/2; 
  
  Serial.print("Distance : ");
  Serial.println(distance);
  delay(100);
  
  remoteMe.loop();
  if(distance <= 150){
    digitalWrite(BUZZ, HIGH);
    delay(1000);
    digitalWrite(BUZZ, LOW);
    remoteMe.sendPushNotificationMessage(1,"Social Distancing App","PERHATIKAN JARAK! JARAK ANDA TERLALU DEKAT!","","","");
  } 
  delay(100);
}
