#include <Arduino.h>
#include "LayoutDriver/LayoutDriver.h"

LayoutDriver layoutDriver;

void setup() {
    Serial.begin(9600);
    Serial.print("ACMRMega v1.0");
}

void loop() {
    layoutDriver.run();
}