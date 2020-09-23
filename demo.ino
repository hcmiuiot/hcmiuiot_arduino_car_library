#include "HCMIUIOT_CAR.h"

Car car;

static volatile int nPulse = 0;

void change() {
  digitalWrite(LED_BUILTIN, digitalRead(2));
  nPulse++;
  Serial.println(nPulse);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
  //  attachInterrupt(0, rising, RISING);
  //  attachInterrupt(0, falling, FALLING);
  attachInterrupt(0, change, CHANGE);
  Serial.begin(9600);
  //
  car.stop();
}

void loop() {
//  while (!Serial.available());
  delay(10000);
//  Serial.read();
  //  pinMode(12, INPUT);
  nPulse = 0;
  int expectedPulse = 70;

//  car.setSpeed(Serial.parseInt());
  car.setSpeed(5);
  car.forward(0);


  while (nPulse < expectedPulse);

  //  for (long long int i = 0; i < 1000; i++) {
  //   Serial.println(digitalRead(12));
  ////    delay(100);
  //  }
  //delay(3000);
  car.stop();
}
