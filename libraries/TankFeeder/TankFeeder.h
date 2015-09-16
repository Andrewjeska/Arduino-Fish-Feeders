#ifndef TankFeeder_h
#define TankFeeder_h
#include <Arduino.h>
#include <Servo.h>

class TankFeeder{
    private:
	
  
    public:
	Servo servo_top;
	int ini_angle_top;
	int fin_angle_top;
        int delay_top;
	
	Servo servo_bottom;
	int ini_angle_bottom;
	int fin_angle_bottom;
	int delay_bottom;

	int count;
	int angle;

	int relay_pin;
	
    	TankFeeder();
    	
    	void setFeederServo(char T_or_B, int pin, int ini_angle, int fin_angle, int delay);	

	void feedFish(int repeat, int relay_pin);

};
  
#endif
