#include <HCSR04.h> // take into account that you're gonna use the sensor HCSR04.

UltraSonicDistanceSensor distanceSensor(13, 12);  // Initialize sensor that uses digital pins trig 13 and echo 12.



int i = 11; //initialize the variable "i"

void setup () {
  //we define which are the diferent LEDs located.
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
//we define the coniditon of the sensor
  if (distanceSensor.measureDistanceCm() < 20) {
    for (i = 11; i > 6; i--) { //we begin in pin 11 and it decrease one by one until pin 6.

      digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);                       // wait for 500 miliseconds
      digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
      //delay(500);
    }
  }
  else {
    digitalWrite(i, LOW); // turn the LED off by making the voltage LOW

  }
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
  Serial.println(distanceSensor.measureDistanceCm());
  delay(500);
}
