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
int echo = D2;
int trig = D3;
int buzz = D5;

//Declare for Echo and Distance
int duration, distance;


//*************** IMPLEMENT FUNCTIONS BELOW *********************

void onBuzzerChange(boolean b) {
	Serial.printf("onBuzzerChange: b: %d\n",b);
	digitalWrite(buzz, b?HIGH:LOW);
}




void setup() {
	Serial.begin(9600);
	pinMode(echo, INPUT);
	pinMode(trig, OUTPUT);
	pinMode(buzz, OUTPUT);
	WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
	}

	remoteMe.getVariables()->observeBoolean("Buzzer" ,onBuzzerChange);

	remoteMe.setConnector(new RemoteMeSocketConnector());
	remoteMe.sendRegisterDeviceMessage(DEVICE_NAME);
}


void loop() {
	remoteMe.loop();
	
	duration = pulseIn(echo, HIGH);
	distance = (duration / 2) / 29.1;
}
