//PRESS RESET ON THE ARDUINO

//power from digital pin
//MUST CONNECT THE ARDUINO'S GROUND TO THE SNAP CIRCUITS GROUND


#define CUSTOM_SETTINGS
#define INCLUDE_CLOCK_SHIELD
#define INCLUDE_PROXIMITY_SENSOR_SHIELD

#include <OneSheeld.h>


int totalPullUps = 0;

int hour, minute, second, day, month, year;

int alarmPin = 13;

boolean startTime = true;
  
void setup() { 

  OneSheeld.begin();
  
  Clock.queryDateAndTime();

  pinMode(alarmPin, OUTPUT);

  Serial.begin(115200);
  
}

void loop() {
  
    
  hour = Clock.getHours();
  minute = Clock.getMinutes();
  second = Clock.getSeconds();
  day = Clock.getDay();
  month = Clock.getMonth();
  year = Clock.getYear();


  if(hour == 12 && minute == 15) {


          if(startTime == true) {
  
               Serial.print("boolean is true");
               digitalWrite(alarmPin, HIGH);
                   } //boolean close
                
                startTime = false;
        

 
          if(ProximitySensor.getValue() == 0) {
          totalPullUps++;
          Serial.println(totalPullUps);
          OneSheeld.delay(1300);


          
                    if(totalPullUps == 5) {
                      digitalWrite(alarmPin, LOW);




                      
   } //if-statement(totalPullUps)
  } //if-statement(proximinity)
 } //if-statement(time) close
} //void loop close


