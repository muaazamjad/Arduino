#include <Arduino.h>
#include <PIRSensor.h>

#define PIR_PIN 7

// Define object of type PIRSensor
PIRSensor mySensor;

void setup()
{
  // Call PIRSensor contructor with pin number.
  mySensor = PIRSensor(PIR_PIN);
  mySensor.begin();

  // Set PIN 2 of Port 1 to Output
  R_PORT1->PDR_b.PDR2 = 1;
}

void loop()
{
  if (mySensor.isMotionActive())
  {
    // Set pin 2 of port 1 to high
    R_PORT1->PODR_b.PODR2 = 1;

    if (millis() - mySensor.getStartTime() >= 5000)
    {
      // Set pin 2 of port 1 to high
      R_PORT1->PODR_b.PODR2 = 0;
      mySensor.clearMotionState();
    }
  }
}
