//
// Created by hylbr on 25-2-2023.
//

#ifndef ACMRMEGA_MOTORDRIVER_H
#define ACMRMEGA_MOTORDRIVER_H
#include <Arduino.h>

class Motordriver {
private:
    //moet PWM zijn!
    byte motorSpeed;

    //Zijn digital
    byte motorDir1;
    byte motorDir2;

    //analog In
    byte potMeterPin;


    int potmeterValue;
    int mappedValue;


public:
    Motordriver(byte motorSpeed,byte motorDir1, byte motorDir2, byte potmeterPin);
    void init();

    int readPotmeterInput();

    void motorControl();

    void switchDirection();
};
#endif //ACMRMEGA_MOTORDRIVER_H
