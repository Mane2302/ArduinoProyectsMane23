#include "SR04.h"
#define TRIG_PIN 12  // pin 12 en el Arduino
#define ECHO_PIN 11  //pin 11 en el Arduino
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
  delay(1000);
}