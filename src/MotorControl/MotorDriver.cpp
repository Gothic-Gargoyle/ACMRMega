//
// Created by hylbr on 25-2-2023.
//

#include <Arduino.h>
#include "MotorDriver.h"

Motordriver::Motordriver(byte motorSpeed,byte motorDir1, byte motorDir2, byte potmeterPin) {
    this->motorSpeed = motorSpeed; //PWM pin, kan led gebruiken als test
    this->motorDir1 = motorDir1;
    this->motorDir2 = motorDir2;
    this->potMeterPin = potmeterPin;
    init();
}
void Motordriver::init() {
    pinMode(motorSpeed,OUTPUT);
    pinMode(motorDir1,OUTPUT);
    pinMode(motorDir2,OUTPUT);
    pinMode(potMeterPin,INPUT);
    TCCR1B = (TCCR1B & B11111000) | B00000100; //Pin 11 en 12 zitten nu op 122,55Hz
}

int Motordriver::readPotmeterInput(){
    //read potmeterpin implementatie
    potmeterValue = analogRead(potMeterPin);
    return potmeterValue;
}

//is deze nog nodig?
void Motordriver::switchDirection(){

}

void Motordriver::motorControl(){
    //voor schakelen richting: range tussen 0 en midden en midden en max
    //Vooruit
    if (readPotmeterInput() > 512) {
        mappedValue = map(readPotmeterInput(), 512, 1023, 0, 255);
        //serial.print(value + "\n");
        digitalWrite(motorDir1,HIGH);
        digitalWrite(motorDir2,LOW);
        analogWrite(motorSpeed, mappedValue);
        delay(10); //moet delay eruit halen eigs :')

        //achteruit
    }else {
        mappedValue = map(readPotmeterInput(), 511, 0, 0, 255);
        //serial.print(value + "\n");
        digitalWrite(motorDir1,LOW);
        digitalWrite(motorDir2,HIGH);
        analogWrite(motorSpeed, mappedValue);
        delay(10);
    }
}