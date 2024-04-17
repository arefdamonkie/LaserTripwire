#include <TimeLib.h>

int ledPin = 2;
double last_time_unbroken;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin,  OUTPUT);
    last_time_unbroken = now();
}

void loop() {
    int value = analogRead(A0);

    Serial.println("Analog  Value: ");
    Serial.println(value);
    
    if (value > 960) {
        last_time_unbroken = now();
        digitalWrite(ledPin, LOW);
    } else if (now() - last_time_unbroken > 3) {
        digitalWrite(ledPin,  HIGH);
    }
    
    delay(250);
}
