#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H

#include <Arduino.h>

class PIRSensor
{
private:
    uint8_t _pin;                          // Stores the pin number defined in the constructor
    volatile bool _motionDetected;         // Stores the current state (volatile for interrupts)
    volatile unsigned long _startTime = 0; // Stores elasped milliseconds time stamp when interuppt was detected

public:
    // Constructor: Tells the class which pin to use
    PIRSensor(uint8_t pin);

    // Initialization method to set up the pin and interrupt
    void begin();

    // The interface methods you suggested (refined for interrupts)
    bool isMotionActive();
    void clearMotionState();
    void handleInterrupt();
    unsigned long getStartTime();
};

#endif