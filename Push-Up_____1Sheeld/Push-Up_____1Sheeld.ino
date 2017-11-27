//power from digital pin
//MUST CONNECT THE ARDUINO'S GROUND TO THE SNAP CIRCUITS GROUND
//once the things connected to the 8-channel relay areactivated the arduino must be restarted for it to work again

#define CUSTOM_SETTINGS
#define INCLUDE_CLOCK_SHIELD
#define INCLUDE_PROXIMITY_SENSOR_SHIELD
#include <OneSheeld.h>


int totalPushUps = 0;

int hour, minute, second, day, month, year;

int piezoPin = 13; //piezo buzzer


//consider renaming the following one what they are controlling is determined
int relayChannelOne = 1; //alarm(horn)//coffe maker
int relayChannelTwo = 2; //coffe maker
int relayChannelThree = 3; //lamp


boolean startTime = true;

void setup() {

  OneSheeld.begin();

  Clock.queryDateAndTime();

  Serial.begin(115200);

  pinMode(piezoPin, OUTPUT);

  pinMode(relayChannelOne, OUTPUT);
  pinMode(relayChannelTwo, OUTPUT);
  pinMode(relayChannelThree, OUTPUT);
delay(250);
Serial.print("setup is complete");
delay(250);
}

void loop() {


  hour = Clock.getHours();
  minute = Clock.getMinutes();
  second = Clock.getSeconds();
  day = Clock.getDay();
  month = Clock.getMonth();
  year = Clock.getYear();

  if (hour == 16 && minute == 47) {

    if (startTime  == true) {

      Serial.print("boolean is true ");
      digitalWrite(piezoPin, HIGH);

      digitalWrite(relayChannelOne, HIGH);
      digitalWrite(relayChannelTwo, HIGH);
      digitalWrite(relayChannelThree, HIGH);
    } //boolean close

    startTime = false;



         if (ProximitySensor.getValue() == 1) {
            totalPushUps++;
           Serial.println(totalPushUps);


                     if (totalPushUps == 5) {
                        digitalWrite(piezoPin, LOW);
                        Serial.println("5 pushups done");




                              } //if-statement(totalPushUps)
         } //if-statement(proximinity)
  } //if-statement(time) close
      OneSheeld.delay(5000);
            delay(5000);

} //void loop close

