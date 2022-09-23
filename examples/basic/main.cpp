#include <Arduino.h>
#include <TimedBool.h>

TimedBool b1;             // timer not startet
TimedBool b2(2000);       // timer not startet
TimedBool b3(2000, true); // timer startet

void setup() {
  Serial.begin(115200);

  b1.setDuration(2000);
  b1 = true;  // start timer

  b2 = false; // start timer
}

void loop() {

  if (b1 == false) {
    Serial.printf("b1 is false now, setting to true\r\n");
    b1 = true; // (re)start timer
  }

  if (b2 == true) {
    Serial.printf("b2 is true now, setting to false\r\n");
    b2 = false; // (re)start timer
  }

  if (b3 == false) {
    Serial.printf("b3 is false now, setting to true\r\n");
    b3 = true;  // (re)start timer
  }

  delay(1); // needed by wokwi
}
