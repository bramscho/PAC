//MUST CONNECT THE ARDUINO'S GROUND TO THE SNAP CIRCUITS GROUND
//once the things connected to the 8-channel relay are activated the Arduino must be restarted for it to work again
//  OneSheeld.delay(5000);

#define CUSTOM_SETTINGS
#define INCLUDE_CLOCK_SHIELD
#define INCLUDE_PROXIMITY_SENSOR_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#include <OneSheeld.h>

int totalPushUps = 0;

int hour, minute, second, day, month, year;

int relayChannelOne = 4; //alarm(horn)
int relayChannelTwo = 2; //coffee maker
int relayChannelThree = 3; //lamp


bool flag = false;

void setup() {

  OneSheeld.begin();

  Clock.queryDateAndTime();


  pinMode(relayChannelOne, OUTPUT);
  pinMode(relayChannelTwo, OUTPUT);
  pinMode(relayChannelThree, OUTPUT);



}

void loop() {

hour = Clock.getHours();
minute = Clock.getMinutes();

    if (hour == 23 && minute == 08) {





  if (ProximitySensor.getValue() == 0 && flag == false ) {

    flag = true;
    totalPushUps++;
    Terminal.println(totalPushUps);

    if (totalPushUps == 6) {


      Terminal.println("5 Pushups done");
      OneSheeld.delay(1000);
      totalPushUps = 0;

    } //if-statement(totalPushUps)

  } //if-statement(proximinity)

  else if(ProximitySensor.getValue() > 0) {

    flag = false;

  }

                   }



} //void loop


