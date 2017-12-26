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

int relayChannelOne = 13; //alarm(horn)
int relayChannelTwo = 12; //coffee maker
int relayChannelThree = 3; //lamp

boolean startTime = true;
bool flag = false;
bool test = false;
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
second = Clock.getSeconds();

    if (hour == 21 && minute == 8) {

if (test == false) {
  

 digitalWrite(relayChannelOne, HIGH);
  digitalWrite(relayChannelTwo, HIGH);
  digitalWrite(relayChannelThree, HIGH);
test = !test;
}

  if (ProximitySensor.getValue() == 0 && flag == false ) {

    flag = true;
    totalPushUps++;
    Terminal.println(totalPushUps);

    if (totalPushUps > 5) {


        Terminal.println("5 Pushups done");
        digitalWrite(relayChannelOne, LOW);
        OneSheeld.delay(1000);

    } //if-statement(totalPushUps)

  } //if-statement(proximinity)

  else if(ProximitySensor.getValue() > 0) {

    flag = false;

  }

                   }



} //void loop

