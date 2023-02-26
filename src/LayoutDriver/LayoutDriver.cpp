//
// Created by hylbr on 25-2-2023.
//

#include "LayoutDriver.h"
#include "MotorControl/MotorDriver.h"

Motordriver motordriver(11,23,24,A0);

LayoutDriver::LayoutDriver(){
}

void LayoutDriver::run() {
    motordriver.motorControl();
}