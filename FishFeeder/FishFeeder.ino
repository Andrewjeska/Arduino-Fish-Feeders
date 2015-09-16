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
  
TankFeeder::TankFeeder()
{
  
}
 
Servo TankFeeder::getServo(char T_or_B)
  {
    if (T_or_B == 'T') {
        return Top;
    } else {
        return Bottom;
    }
  }
  
 void TankFeeder::setFeeder(int T_pin, int B_pin, int T_angle, int B_angle, int repeat)
  {
    Top.attach(T_pin);
    Bottom.attach(B_pin);
    Top.write(T_angle);
    Bottom.write(B_angle);
    this->cups = repeat;
  } 
