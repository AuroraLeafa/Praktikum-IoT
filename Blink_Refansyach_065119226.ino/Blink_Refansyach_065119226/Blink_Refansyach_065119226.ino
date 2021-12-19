/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
int led0 = 4; int led5 = 9;
int led1 = 5; int led6 = 10;
int led2 = 6; int led7 = 11;
int led3 = 7; int led8 = 12;
int led4 = 8; int led9 = 13;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode (led0, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  pinMode (led5, OUTPUT);
  pinMode (led6, OUTPUT);
  pinMode (led7, OUTPUT);
  pinMode (led8, OUTPUT);
  pinMode (led9, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led0, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(led0, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(led1, HIGH);    // turn the LED off by making the voltage LOW
  delay(200);                       // wait for a second
  digitalWrite(led1, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);    
  
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(led2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(led3, HIGH);    // turn the LED off by making the voltage LOW
  delay(200);                       // wait for a second
  digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
  delay(50);    
  
  digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(led4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(led5, HIGH);    // turn the LED off by making the voltage LOW
  delay(200);                       // wait for a second
  digitalWrite(led5, LOW);    // turn the LED off by making the voltage LOW
  delay(50);   
   
  digitalWrite(led6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(led6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(led7, HIGH);    // turn the LED off by making the voltage LOW
  delay(200);                       // wait for a second
  digitalWrite(led7, LOW);    // turn the LED off by making the voltage LOW
  delay(50);    
  
  digitalWrite(led8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(led8, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(led9, HIGH);    // turn the LED off by making the voltage LOW
  delay(200);                       // wait for a second
  digitalWrite(led9, LOW);    // turn the LED off by making the voltage LOW
  delay(50);    
}
