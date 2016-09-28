/*
  RaggedPi Project
  Relay Shield Simple Library
  Written by david durost <david.durost@gmail.com>
*/

#ifndef RELAY_H
#define RELAY_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif   

// Define relay pins
#define RELAY1 7
#define RELAY2 6
#define RELAY3 5
#define RELAY4 4

class Relay
{
    public: 
      Relay(uint8_t pin, uint8_t state=LOW);        // Constructor 
      void begin();                                 // Initialization
      void on();                                    // Turn relay on 
      void off();                                   // Turn relay off
      void toggle();                                // Toggle relay state
      uint8_t state(uint8_t state=NULL);            // relay state
      bool isOn();                                  // Returns true if relay is on
      bool isOff();                                 // Returns true if the relay is off

    private: 
      uint8_t _state;                               // relay state
      uint8_t _pin;                                 // arduino pin
};

#endif
