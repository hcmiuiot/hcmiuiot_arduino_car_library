#ifndef HCMIUIOT_CAR_h
#define HCMIUIOT_CAR_h

#include "Arduino.h"
#include "L298N.h"

#define DF_WHEEL_RADIUS 3.25 // cm
#define DF_N_PULSE 20
#define DF_HALF_WHEELS_DISTANCE 6.6 // cm

#define DF_PIN_ENABLE_A 10
#define DF_PIN_IN1_A 9
#define DF_PIN_IN2_A 8

#define DF_PIN_ENABLE_B 3
#define DF_PIN_IN1_B 5
#define DF_PIN_IN2_B 4

#define DF_SPEED 100
#define DF_DISTANCE_PER_PULSE 1.021

class Car
{
public:
    // Car(
    //     uint8_t pinEnable_A = DF_PIN_ENABLE_A,
    //     uint8_t pinIN1_A = DF_PIN_IN1_A,
    //     uint8_t pinIN2_A = DF_PIN_IN2_A,
    //     uint8_t pinEnable_B = DF_PIN_ENABLE_B,
    //     uint8_t pinIN1_B = DF_PIN_IN1_B,
    //     uint8_t pinIN2_B = DF_PIN_IN2_B,
    //     float wheelRadius = DF_WHEEL_RADIUS,
    //     float halfWheelsDistance = DF_HALF_WHEELS_DISTANCE,
    //     uint8_t numberOfEncoderPulses = DF_N_PULSE);
    // Car(
    //     uint8_t pinIN1_A = DF_PIN_IN1_A,
    //     uint8_t pinIN2_A = DF_PIN_IN2_A,
    //     uint8_t pinIN1_B = DF_PIN_IN1_B,
    //     uint8_t pinIN2_B = DF_PIN_IN2_B,
    //     float wheelRadius = DF_WHEEL_RADIUS,
    //     float halfWheelsDistance = DF_HALF_WHEELS_DISTANCE,
    //     uint8_t numberOfEncoderPulses = DF_N_PULSE);
    
    Car();

    void setSpeed(uint8_t speed);

    void forward(float distance_in_cm);
    void backward(float distance_in_cm);

    void turnLeft(float angle_in_deg);
    void turnRight(float angle_in_deg);

    void turnArcLeft(/* some params here */);
    void turnArcRight(/* some params here */);

    void stop();

private:
    L298N _motorA;
    L298N _motorB;
    uint8_t _speed = DF_SPEED;
    float _wheelRadius = DF_WHEEL_RADIUS;
    float _halfWheelsDistance = DF_HALF_WHEELS_DISTANCE;
    uint8_t _numberOfPulse = DF_N_PULSE;
    float _distancePerPulse = DF_DISTANCE_PER_PULSE;
};

#endif
