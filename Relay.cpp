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
Relay::Relay(int RelayNm, int state)
{
  if (1 == RelayNm)  relayPin = RELAY1PIN;
  if (2 == RelayNm)  relayPin = RELAY2PIN;
  if (3 == RelayNm)  relayPin = RELAY3PIN; 
  if (4 == RelayNm)  relayPin = RELAY4PIN; 
  pinMode(relayPin, OUTPUT); 

  if (LOW == state) {
    relayState = LOW; 
    off(); 
  } 
  else {
    relayState = HIGH;
    on(); 
  }
}

/**
 * Turn relay on
 */
void Relay::on() 
{
  digitalWrite(relayPin, HIGH); 
  relayState=HIGH; 
}

/**
 * Turn relay off
 */
void Relay::off()
{
  digitalWrite(relayPin, LOW); 
  relayState = LOW; 
}

/**
 * Toggle relay
 */
void Relay::toggle()
{
  if (HIGH == relayState) {
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
int Relay::state()
{
  return(relayState); 
}

/**
 * Relay on
 * @return integer
 */
int Relay::isOn()
{
  if (relayState==HIGH) 
    return true; 
  else
    return false; 
}

// If the relay is off, returns true, otherwise returns false
/**
 * Relay off
 * @return integer
 */
int Relay::isOff()
{
  if (relayState==LOW) 
    return true; 
  else
    return false; 
}


