#include <Arduino.h>
int potmeter = A0;
int ledPin = 11; // configureer de LED pin.

void setup() {
    Serial.begin(9600); // zet seriele poort aan op 9600 baud.
    pinMode(ledPin, OUTPUT); // zet de LED pin als uitgang
}

void loop()
{
    int potentiometerValue = analogRead(potmeter);
    int brightness = potentiometerValue / 4;
    analogWrite(ledPin, brightness);
}