#include <Arduino.h>
#include <PIRSensor.h>

#define PIR_PIN 2

// Define object of type PIRSensor
PIRSensor mySensor(PIR_PIN);

void setup()
{
  // Call PIRSensor contructor with pin number defined in the constructor
  mySensor.begin();
  R_PORT1->PDR_b.PDR2 = 1; // Set pin 2 of port 1 to output

}

void loop()
{
  if (mySensor.isMotionActive())
  {
    Serial.println("Motion Detected! Turning on LED.");
    // Set pin 2 of port 1 to high
    R_PORT1->PODR_b.PODR2 = 1;

    if (millis() - mySensor.getStartTime() >= 5000)
    {
      // Set pin 2 of port 1 to low
      R_PORT1->PODR_b.PODR2 = 0;
      mySensor.clearMotionState();
    }
  }
}
