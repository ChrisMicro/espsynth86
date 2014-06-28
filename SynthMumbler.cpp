#include "Arduino.h"
#include "Defines.h"
#include "SynthMumbler.h"

SynthMumbler::SynthMumbler(Inputs* inputs)
{
  ModuleSpeechSound *speech_sound = new ModuleSpeechSound();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
  
  speech_sound->sound_input = inputs->mod;
  speech_sound->param1_input = inputs->param1;
  speech_sound->param2_input = inputs->param2;
  speech_sound->pitch_input = inputs->sr;
  
  // Patch up lowpass filter
  lowpass_filter->audio_input = speech_sound;
  lowpass_filter->cutoff_input = inputs->param3;
  lowpass_filter->resonance_input = new ModuleConstant(1500);
  
  this->last_module = lowpass_filter;
}
