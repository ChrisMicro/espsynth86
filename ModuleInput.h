/*
 *  +----------------------+
 *  | ModuleInput          |
 *  |----------------------|
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// ModuleInput represents a physical input of the equation composer.  It's not
// necessary to create your own ModuleInput modules when creating synths  
// because all 7 inputs are created for you and passed into each synth.  If you 
// want to trace the code, look at Inputs.cpp, which is instantiated in 
// EquationComposer.ino and passed into each synth.  But you can ignore the gory 
// details and simply access the inputs using:
//
//  inputs->sr
//  inputs->mod
//  inputs->param1
//  inputs->param2
//  inputs->param3
//  inputs->gate
//
// Example usage:
//
//  ModuleWavetableOsc *osc = new ModuleWavetableOsc();
//  osc->wavetable_input  = inputs->mod;
//  osc->frequency_input  = inputs->sr;
//  
//  this->last_module = osc;

#ifndef ModuleInput_h
#define ModuleInput_h

#include "Arduino.h"
#include "Module.h"

class ModuleInput : public Module
{
  
  public:
    
    // Methods
    ModuleInput();
    uint32_t run();
    
    void setValue(uint32_t value);
    uint32_t getValue();

    virtual uint32_t read() = 0;  // Pure virtual function.  This must be implemented in the derived class.
    
    // Variables
    uint32_t value; // The value of the input
    int pin;        // The pin for the input
};

#endif
