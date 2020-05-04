#pragma once

#include <Arduino.h>

// Kontrola hvataljke, tacnije jednog njenog prsta preko motora za vibraciju
class RoboHand
{
private:
    uint8_t pinMot1, pinMot2; // pinovi za motor pokretnog prsta
    float pwmCoef;            // Broj koji se mnozi sa PWMRANGE [0, 1]

public:
    RoboHand(uint8_t pinMot1, uint8_t pinMot2, float pwmCoef = 0.5);

    // Hvatanje - spajanje prstiju.
    void Catch();
    // Pustanje - razdvajanje prstiju.
    void Release();
    // void Refresh(ulong ms);
};
