/*
  hcmiuiot_car.cpp - Library to manage the movements of a DC motor with the L298N module
  Author: HCMIU Internet of Things Club
  Web: https://www.facebook.com/hcmiuiot/
*/
#include "Arduino.h"
#include "HCMIUIOT_CAR.h"
#include "L298N.h"

#define DEBUG 0

// Car::Car(
//     uint8_t pinEnable_A,
//     uint8_t pinIN1_A,
//     uint8_t pinIN2_A,
//     uint8_t pinEnable_B,
//     uint8_t pinIN1_B,
//     uint8_t pinIN2_B,
//     float wheelRadius,
//     float halfWheelsDistance,
//     uint8_t numberOfEncoderPulses) : _motorA(pinEnable_A,
//                                              pinIN1_A,
//                                              pinIN2_A),
//                                      _motorB(pinEnable_B,
//                                              pinIN1_B,
//                                              pinIN2_B)
// {
// }
// Car::Car(
//     uint8_t pinIN1_A,
//     uint8_t pinIN2_A,
//     uint8_t pinIN1_B,
//     uint8_t pinIN2_B,
//     float wheelRadius,
//     float halfWheelsDistance,
//     uint8_t numberOfEncoderPulses) : _motorA(pinIN1_A,
//                                              pinIN2_A),
//                                      _motorB(pinIN1_B,
//                                              pinIN2_B)
// {
//     //
// }

Car::Car() : _motorA(DF_PIN_ENABLE_A,
                     DF_PIN_IN1_A,
                     DF_PIN_IN2_A),
             _motorB(DF_PIN_ENABLE_B,
                     DF_PIN_IN1_B,
                     DF_PIN_IN2_B)
{
    _distancePerPulse  = 6.283185 * _wheelRadius / _numberOfPulse;
}

void Car::setSpeed(uint8_t speed)
{
    _speed = map(speed, 0, 100, 70, 255);
    _motorA.setSpeed(_speed);
    _motorB.setSpeed(_speed);
}

void Car::forward(float distance_in_cm)
{
    // float 
    _motorA.forward();
    _motorB.forward();

}

void Car::turnLeft(float angle_in_deg){};
void Car::turnRight(float angle_in_deg){};

void Car::turnArcLeft(/* some params here */){};
void Car::turnArcRight(/* some params here */){};

void Car::stop()
{
    _motorA.stop();
    _motorB.stop();
}