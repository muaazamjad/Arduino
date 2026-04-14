#include <Arduino.h>

// put function declarations here:
PinStatus lastPinStatus = HIGH;
void setup()
{
  // Set Port 1 Pin 2 to Output

  Serial.begin(115200);
  R_PORT1->PDR_b.PDR2 = 1;
  // Set PIN D2 To input and enable pull up resistor (High potential)
  pinMode(PIN_D2, INPUT_PULLUP);
}

void loop()
{

  PinStatus pinStatus = digitalRead(PIN_D2);
  // pinStatus Low = Button pressed
  if (pinStatus == 0 && pinStatus != lastPinStatus)
  {
    R_PORT1->PODR_b.PODR2 = 1;
    lastPinStatus = pinStatus;
    Serial.println("LED is on");
  }
  // pinStatus High = Button not pressed
  else if (pinStatus == 1 && pinStatus != lastPinStatus)
  {
    R_PORT1->PODR_b.PODR2 = 0;
    lastPinStatus = pinStatus;
  }
  delay(50);
}
