/*
  RaggedPi Project
  Relay Shield Simple Library
  Written by david durost <david.durost@gmail.com>
*/

//#include "WProgram.h"   
#include "Relay.h"

/**
 * Constructor
 */
Relay::Relay(uint8_t pin, uint8_t state) {
  _pin=pin;
  _state=state;
}

void Relay::begin() {
  pinMode(_pin, OUTPUT);
  state(_state);
}

/**
 * Turn relay on
 */
void Relay::on() {
  digitalWrite(_pin, HIGH); 
  _state=HIGH; 
}

/**
 * Turn relay off
 */
void Relay::off() {
  digitalWrite(_pin, LOW); 
  _state=LOW; 
}

/**
 * Toggle relay
 */
void Relay::toggle() {
  if (HIGH==_state) {
    off(); 
  } 
  else {
    on(); 
  }
}

/**
 * Relay state
 * @return integer state
 */
int Relay::state(uint8_t state) {
  if (NULL!=state) { 
      if (HIGH==state)  on();
    else off();
  }
  return(_state);
}

/**
 * Relay on
 * @return integer
 */
int Relay::isOn() {
  if (_state==HIGH) 
    return true; 
  else
    return false; 
}

/**
 * Relay off
 * @return integer
 */
int Relay::isOff() {
  if (_state==LOW) 
    return true; 
  else
    return false; 
}
