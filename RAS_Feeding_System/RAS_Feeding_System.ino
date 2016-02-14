#include <TankFeeder.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <Servo.h> 

//Instructions on adding new fish tanks/changing settings

TankFeeder Feeder_1;
TankFeeder Feeder_2;
TankFeeder Feeder_3;
TankFeeder Feeder_4;

/*All Tanks should be declared here. Should follow this format:
ex.

TankFeeder feederName;

*/

void callfeedFish(){
  //This part just turns on an LED showing that the process is about to begin
  digitalWrite(13, HIGH);
  delay(1000);
  
  Feeder_1.feedFish(1,9);
  delay(5000);
  Feeder_2.feedFish(1,10);
  delay(5000);
  Feeder_3.feedFish(1,11);
  delay(5000);
  Feeder_4.feedFish(1,12);
  delay(1000);
  digitalWrite(13, LOW);
}
  /*
  
  All feeders should go under callfeedfish(). The format is as follows:
  
  feederName.feedfish(repeat, relay_pin)
  
  "repeat' tells the arduino how many cups you want to drop per feeding. So if you need one cup per feeding,
  you would put a "1" in the spot for repeat. If you needed two, you would put "2" and so on. Don't forget that raising
  the repeat value will result in the need for more frequent refillings
  
  relay_pin denotes which port on the arduino that the relay is controlled from.
  The number corresponding to the port where the white wire from the
  little blue box goes to on the arduino board.
  
  Please put a "delay(5000);" between each call to feedFish. This ensures that the whole system doesn't overload. 
  IT IS VERY IMPORTANT THAT YOU PUT IN DELAYS.
  
  */
  
void setup() {
  
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  /*
  
  Make sure your relays are initiazlied like so
  
  pinMode( relay_pin, OUTPUT);
  
  */
  
  
  Feeder_1.setFeederServo('T',0,180,95, 60);
  Feeder_1.setFeederServo('B',1,140,40,10);
  
  
  Feeder_2.setFeederServo('T',2,140,70,50);
  Feeder_2.setFeederServo('B',3,150,50,10);
  
  Feeder_3.setFeederServo('T',4,155,70,150);
  Feeder_3.setFeederServo('B',5,140,40,10);
  
  Feeder_4.setFeederServo('T',6,150,90,50);
  Feeder_4.setFeederServo('B',7,150,45,50);
  
  
  
  /*
  
  This is the primary mode of changing feeder settings. Format is as follows:
  
  feederName.setFeederServo( Top or Bottom, Pin, initial angle, end angle, delay);
  
  Top or Bottom: The "Top" servo is the servo that drops food from the the milk jug into the dixie cup. 
  If you are setting this servo, you would put a 'T' (in apostrophes) for the first argument. 
  If you were setting for the other servo, the one opening the dixie cup to allow the food to drop,
  you would put a 'B' (in apostrophes) instead.
  
  Pin: This indicates the PWM port on the arduino that the servo is plugged into (where the white wire ultimately goes into).
  Make sure that you only use the digital port side (ports labeled 0 through 13).
  
  initial angle: This is where the servo should be set when to keep the feeder closed. For a given feeder there shouldn't
  be a need to change this, but if you find that the servo is "wandering" then you should change this value
  
  end angle: This controls how far the servo opens to let the food go through.  This is one way in which you could change the amount of food dropped each time, 
  but the "repeat" option earlier is far more accurate and effective
  
  delay: This controls how long it takes for the servo to move. A higher number means that the servo will stay open longer,
  allowing more food to drop. This is another way in which you could change the food drop amount.
  
  Please refer to the "Reccomended Settings" label or document for optimal feeder performance
  
  */
  
  setTime(14,48,30,6,2,2015);
  
  /* 
  
  The arduino should be plugged in at the time set above. This starts the timer. This is done in military time (24hr format). So..
  
  setTime(Hour, Minute, Second, Day, Month (1-12), Year);
  
  Pretty self-explanatory
  
  */
  
  //Alarm.timerRepeat(30,callfeedFish);
  Alarm.alarmRepeat(14,49,00,callfeedFish);
  
  /*
  
  This sets the time each day that the feeders should dispense food. As it stands it will dispense once each day at the set time.
  If you need multiple there is a function for that. A reference can be found at:
  
  https://www.pjrc.com/teensy/td_libs_TimeAlarms.html
  
  This link works as of May 20, 2015
  
  Alarm.alarmRepeat(Hour, Minute, Second, Function);

 Self-explanatory, but DO NOT CHANGE the 'Function' argument. 
 
 timerRepeat simply runs the feeder after a few seconds. Writing "60" would run the feeder every 60 seconds. This
 function is used typically when debugging, when you need to see what the feeder does for multiple feedings.
 
 */
 
}  
  
void loop() {
  
  Alarm.delay(1000);
  //Nothing to change here 
}
 
 
 
 

