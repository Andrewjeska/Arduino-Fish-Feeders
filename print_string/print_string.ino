#include <TimeAlarms.h>

#include <Time.h>



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  
  setTime(8,57,10,4,3,2015);
  adjustTime(1);
  
  String hour = (String) hour();
  String minute = (String) minute();
  String second = (String) second();
  
  Serial.println( hour + minute + second);
  Alarm.alarmRepeat(8,15,00,Serial.println("words'));
  delay(1000);
}
