#include <TankFeeder.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <Servo.h> 


TankFeeder Tank_1; 


void callfeedFish(){
  feedFish(Tank_1);
}

void setup() {
  Tank_1.setFeeder(1,2,180,150,2,20,50);
  // pin top, pin b, angle t, angle b, repeat, delay t, delay b
  setTime(21,21,20,5,19,2015);
  //Alarm.timerRepeat(30,callfeedFish);
  Alarm.alarmRepeat(7,00,00,callfeedFish);
 
}  
  
 
void loop() {
  
  Alarm.delay(1000);
   
}
 
 
 
 void feedFish(TankFeeder Tank) {
  
   Servo servo_top = Tank.getServo('T');
   Servo servo_bottom = Tank.getServo('B');
  
   int angle_top = servo_top.read() ;
   int angle_bottom = servo_bottom.read();
   
   int Delay_top = Tank.delay_top;
   int Delay_bottom = Tank.delay_bottom;
  
for(int count = 0 ; count < Tank.cups; count++)
  {
    
  
      for(int angle = angle_top ; angle > 140; angle--)  
    {                                  
      servo_top.write(angle);
      delay(Delay_top);                   
    } 
  
   
     for(int angle = 140; angle < angle_top; angle++)  
    {                                  
      servo_top.write(angle);
      delay(Delay_top);                    
    } 
  
  
     delay(2000);
  
  
     for(int angle = angle_bottom; angle > 40; angle--)  
     {                                  
      servo_bottom.write(angle);
      delay(Delay_bottom);                   
     } 


    for(int angle = 40; angle < angle_bottom; angle++)  
    {                                  
      servo_bottom.write(angle);
      delay(Delay_bottom);                   
    }
  }
 }
