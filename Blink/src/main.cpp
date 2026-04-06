#include "Arduino.h"

// Define which pairs to light up for BIBA. Each pair define the port numbers
const uint8_t bibaLEDs[][2] =
    {
        {7, 3}, // LED 1
        {3, 7}, // LED 2

        {7, 4}, // LED 3

        {3, 4}, // LED 5

        {7, 8}, // LED 7
        {8, 7}, // LED 8

        {3, 8}, // LED 9

        {4, 8}, // LED 11

        {7, 0}, // LED 13

        {3, 0}, // LED 15

        {4, 0}, // LED 17

        {8, 0}, // LED 19

        {7, 6}, // LED 21
        {6, 7}, // LED 22

        {6, 3}, // LED 24

        {4, 6}, // LED 25
        {6, 4}, // LED 26

        {8, 6}, // LED 27

        {0, 6}, // LED 29

        {7, 5}, // LED 31
        {5, 7}, // LED 32

        {3, 5}, // LED 33
        {5, 3}, // LED 34

        {4, 5}, // LED 35
        {5, 4}, // LED 36

        {8, 5}, // LED 37

        {0, 5}, // LED 39

        {6, 5}, // LED 41

        {7, 1}, // LED 43

        {3, 1}, // LED 45
        {1, 3}, // LED 46

        {1, 4}, // LED 48

        {8, 1}, // LED 49
        {1, 8}, // LED 50

        {0, 1}, // LED 51

        {6, 1}, // LED 53

        {5, 1}, // LED 55
        {1, 5}, // LED 56

        {7, 2}, // LED 57
        {2, 7}, // LED 58

        {2, 3}, // LED 60

};

const int totalLedsInBiba = sizeof(bibaLEDs) / sizeof(bibaLEDs[0]);

// Helper to set a Port index to High, Low, or Disconnected (Input)
void setPort(int portIdx, int mode)
{
  // Modes: 0 = Input (Off), 1 = Output High, 2 = Output Low

  // Mapping table from your image: Port Index 0 = P003, Index 1 = P004, etc.
  switch (portIdx)
  {
  case 0: // P003
    if (mode == 0)
      R_PORT0->PDR_b.PDR3 = 0;
    else
    {
      R_PORT0->PODR_b.PODR3 = (mode == 1);
      R_PORT0->PDR_b.PDR3 = 1;
    }
    break;
  case 1: // P004
    if (mode == 0)
      R_PORT0->PDR_b.PDR4 = 0;
    else
    {
      R_PORT0->PODR_b.PODR4 = (mode == 1);
      R_PORT0->PDR_b.PDR4 = 1;
    }
    break;
  case 2: // P011
    if (mode == 0)
      R_PORT0->PDR_b.PDR11 = 0;
    else
    {
      R_PORT0->PODR_b.PODR11 = (mode == 1);
      R_PORT0->PDR_b.PDR11 = 1;
    }
    break;
  case 3: // P012
    if (mode == 0)
      R_PORT0->PDR_b.PDR12 = 0;
    else
    {
      R_PORT0->PODR_b.PODR12 = (mode == 1);
      R_PORT0->PDR_b.PDR12 = 1;
    }
    break;
  case 4: // P013
    if (mode == 0)
      R_PORT0->PDR_b.PDR13 = 0;
    else
    {
      R_PORT0->PODR_b.PODR13 = (mode == 1);
      R_PORT0->PDR_b.PDR13 = 1;
    }
    break;
  case 5: // P015
    if (mode == 0)
      R_PORT0->PDR_b.PDR15 = 0;
    else
    {
      R_PORT0->PODR_b.PODR15 = (mode == 1);
      R_PORT0->PDR_b.PDR15 = 1;
    }
    break;
  case 6: // P204
    if (mode == 0)
      R_PORT2->PDR_b.PDR4 = 0;
    else
    {
      R_PORT2->PODR_b.PODR4 = (mode == 1);
      R_PORT2->PDR_b.PDR4 = 1;
    }
    break;
  case 7: // P205
    if (mode == 0)
      R_PORT2->PDR_b.PDR5 = 0;
    else
    {
      R_PORT2->PODR_b.PODR5 = (mode == 1);
      R_PORT2->PDR_b.PDR5 = 1;
    }
    break;
  case 8: // P206
    if (mode == 0)
      R_PORT2->PDR_b.PDR6 = 0;
    else
    {
      R_PORT2->PODR_b.PODR6 = (mode == 1);
      R_PORT2->PDR_b.PDR6 = 1;
    }
    break;
  case 9: // P212
    if (mode == 0)
      R_PORT2->PDR_b.PDR12 = 0;
    else
    {
      R_PORT2->PODR_b.PODR12 = (mode == 1);
      R_PORT2->PDR_b.PDR12 = 1;
    }
    break;
  case 10: // P213
    if (mode == 0)
      R_PORT2->PDR_b.PDR13 = 0;
    else
    {
      R_PORT2->PODR_b.PODR13 = (mode == 1);
      R_PORT2->PDR_b.PDR13 = 1;
    }
    break;
  }
}

void enableCycleCounter()
{
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; // Enable Trace
  DWT->CYCCNT = 0;                                // Reset counter
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;            // Enable cycle counter
}

void BiBaLed()
{
  for (int i = 0; i < totalLedsInBiba; i++)
  {
    int highRow = bibaLEDs[i][0];
    int lowRow = bibaLEDs[i][1];

    // 1. Turn LED ON
    setPort(highRow, 1); // Set Anode High
    setPort(lowRow, 2);  // Set Cathode Low

    delayMicroseconds(1); // Persistence of vision window

    // 2. Turn LED OFF (Crucial: Set back to Input/High-Z)
    setPort(highRow, 0);
    setPort(lowRow, 0);
  }
}

void setup()
{

  // Serial.begin(9600);
  // while (!Serial)
  //{
  //   ; // Wait for serial port to connect. Needed for native USB
  // }
  // enableCycleCounter(); // Do this once in setup or at the start
  // Serial.println("Ready!");
}

void loop()
{
  // start counting
  // uint32_t start = DWT->CYCCNT;

  BiBaLed();
  // stop counting
  // uint32_t end = DWT->CYCCNT;
  // uint32_t totalCycles = end - start;

  // static int frameCount = 0;
  // if (++frameCount >= 5000)
  //{
  //   Serial.print("Cycles taken: ");
  //   Serial.println(totalCycles);
  //   frameCount = 0;
  // }
}
