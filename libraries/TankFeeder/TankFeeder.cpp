
#include<TankFeeder.h>
#include<Servo.h>

TankFeeder::TankFeeder()
{
  
}
 
  
 void TankFeeder::setFeederServo(char T_or_B, int pin, int ini_angle, int fin_angle, int delay)
  {

   

   if( T_or_B == 'T'){

    	servo_top.attach(pin);
        servo_top.write(ini_angle);
        
	this->ini_angle_top = ini_angle;
	this->fin_angle_top = fin_angle; 
        this->delay_top = delay;
	
	}else{

	servo_bottom.attach(pin);
        servo_bottom.write(ini_angle);
        
	ini_angle_bottom = ini_angle;
	fin_angle_bottom = fin_angle; 
        delay_bottom = delay;

  } 
}

void TankFeeder::feedFish(int repeat, int relay_pin)
	{
 
digitalWrite(relay_pin, HIGH); 


delay(40000);
 
for(int count = 0 ; count < repeat; count++)
  {
    
  
      for(int angle = ini_angle_top ; angle > fin_angle_top; angle--)  
        {                             
      servo_top.write(angle);
      delay(delay_top);                   
    
  }
   
     for(int angle = fin_angle_top; angle < ini_angle_top; angle++)  
    {                                  
      servo_top.write(angle);
      delay(delay_top);                    
    } 
  
  
     delay(2000);
  
  
   for(int angle = ini_angle_bottom ; angle > fin_angle_bottom; angle--)  
    {                                  
      servo_bottom.write(angle);
      delay(delay_bottom);                   
    } 
  
   
     for(int angle = fin_angle_bottom; angle < ini_angle_bottom; angle++)  
    {                                  
      servo_bottom.write(angle);
      delay(delay_bottom);                    
    } 
	
     
     digitalWrite(relay_pin, LOW);

   

  }
 }

