#include <Arduino.h>

// put function declarations here:

void setup()
{
  // Set Port 1 Pin 2 to Output
  R_PORT1->PDR_b.PDR2 = 1;
}

void loop()
{
  // SET led state to High
  R_PORT1->PODR_b.PODR2 = 1;
  delay(1000);
  // SET led state to Low
  R_PORT1->PODR_b.PODR2 = 0;
  delay(1000);
}
