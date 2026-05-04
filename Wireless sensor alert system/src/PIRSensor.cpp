#include <PIRSensor.h>
#include <Arduino.h>

// Inside PIRSensor.cpp, but outside any class methods
PIRSensor *instance = nullptr;

// This is the function the hardware will actually call
void pirInterruptWrapper()
{
    if (instance != nullptr)
    {
        instance->handleInterrupt(); // Forward the message to the object!
    }
}

PIRSensor::PIRSensor(uint8_t pin)
{
    _pin = pin;
}

void PIRSensor::begin()
{
    pinMode(_pin, INPUT);

    // 2. Store the current object instance globally for the static wrapper
    instance = this;

    // 3. Attach the hardware interrupt
    // We pass the static wrapper, and trigger on a change (e.g., RISING for a PIR detection)
    attachInterrupt(digitalPinToInterrupt(_pin), pirInterruptWrapper, RISING);
}

void PIRSensor::handleInterrupt()
{
    _motionDetected = true;
    _startTime = millis();
}

bool PIRSensor::isMotionActive()
{
    return _motionDetected;
}

void PIRSensor::clearMotionState()
{
    _motionDetected = false;
    _startTime = 0;
}

unsigned long PIRSensor::getStartTime()
{
    return _startTime;
}