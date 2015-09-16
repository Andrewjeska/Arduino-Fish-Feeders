#ifndef Morse_h
#define Morse_h
#include "Arduino.h"

class TankFeeder{
  
  private:
    Servo Top;
    Servo Bottom;
  public:
    int cups;
    TankFeeder();
    Servo getServo(char T_or_B);
    void setFeeder(int T_pin, int B_pin, int T_angle, int B_angle, int repeat);
};
  
#endif
