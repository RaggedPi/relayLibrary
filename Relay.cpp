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
  digitalWrite(_pin, ON); 
  _state=ON; 
}

/**
 * Turn relay off
 */
void Relay::off() {
  digitalWrite(_pin, OFF); 
  _state=OFF; 
}

/**
 * Toggle relay
 */
void Relay::toggle() {
  _state = 1&~digitalRead(_pin);
  digitalWrite(_pin, _state);  
}

/**
 * Relay state
 * @return integer state
 */
uint8_t Relay::state(uint8_t state) {
  if (NULL != state) { 
      digitalWrite(_pin, state);
      _state = state;      
  }
  return(_state);
}

/**
 * Relay on
 * @return bool
 */
bool Relay::isOn() {
  return (ON == digitalRead(_pin));
}

/**
 * Relay off
 * @return bool
 */
bool Relay::isOff() {
  return (OFF == digitalRead(_pin));  
}
