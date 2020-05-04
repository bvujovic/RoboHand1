#include "RoboHand.h"

RoboHand::RoboHand(uint8_t pinMot1, uint8_t pinMot2, float pwmCoef)
{
    this->pinMot1 = pinMot1;
    this->pinMot2 = pinMot2;
    this->pwmCoef = pwmCoef;

    pinMode(pinMot1, OUTPUT);
    digitalWrite(pinMot1, false);
    pinMode(pinMot2, OUTPUT);
    digitalWrite(pinMot2, false);
}

void RoboHand::Catch()
{
    analogWrite(pinMot1, pwmCoef * PWMRANGE);
    digitalWrite(pinMot2, false);
}

void RoboHand::Release()
{
    analogWrite(pinMot2, pwmCoef * PWMRANGE);
    digitalWrite(pinMot1, false);
    delay(200);
    digitalWrite(pinMot1, false);
    digitalWrite(pinMot2, false);
}