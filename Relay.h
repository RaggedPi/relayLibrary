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

#define RELAY1PIN 7
#define RELAY2PIN 6
#define RELAY3PIN 5
#define RELAY4PIN 4

class Relay
{
    public: 
      Relay(int RelayNm, int state);                // Constructor 
      void on();                                    // Turn relay on 
      void off();                                   // Turn relay off
      void toggle();                                // Toggle relay state
      int state();                                  // relay state
      int isOn();                                   // boolean
      int isOff();                                  // Returns TRUE if the relay is off, false otherwise 

    private: 
      int relayState;                               // relay state
      int relayPin;                                 // arduino pin
};

#endif
