/*
 *  +------------------------+
 *  | ModuleSamplePLayer     |
 *  |------------------------|
 *  > sample_selection_input |
 *  > trigger_input          |
 *  > sample_rate_input      |
 *  |                 output >
 *  +------------------------+
 *
 */
// =============================================================================
// 
// ModuleSamplePLayer is an audio sample playback module.  All of the samples
// available are currently drum sounds.  There is no external memory for the
// equation composer, so it can hold very few samples.
//
// Samples are defined in GlobalSamples.cpp.
//
// Example usage:
//
//  ModuleDrumSequencer *drum_sequencer = new ModuleDrumSequencer();
//  ModuleSamplePlayer *kick = new ModuleSamplePlayer();
//  ModuleSamplePlayer *snare = new ModuleSamplePlayer();
//  ModuleSamplePlayer *hihat = new ModuleSamplePlayer();
//  ModuleKitSelect *kit_select = new ModuleKitSelect();
//  ModuleMixer3 *mixer = new ModuleMixer3();
//  ModuleWaveFolder *wave_folder = new ModuleWaveFolder();
//  ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
//
//  // Use the external clock when available, otherwise
//  // default to the internal 120BPM clock
//  ext_clock->clock_input = inputs->gate;
//
//  drum_sequencer->clock_input = ext_clock;
//
//  // Use the 3 parameters to select the patterns 
//  // used for the drums.
//  drum_sequencer->kick_pattern_input = inputs->param1;
//  drum_sequencer->snare_pattern_input = inputs->param2;
//  drum_sequencer->hihat_pattern_input = inputs->param3;
//
//  // Use the mode input to select the drum kit
//  kit_select->kit_selection_input = inputs->mod;
//
//  // Set the kick, snare, and hihat inputs
//  kick->trigger_input = drum_sequencer->kick_output;
//  kick->sample_rate_input = inputs->sr;
//  kick->sample_selection_input = kit_select->kick_output;
//
//  snare->trigger_input = drum_sequencer->snare_output;
//  snare->sample_rate_input = inputs->sr;
//  snare->sample_selection_input = kit_select->snare_output;
//
//  hihat->trigger_input = drum_sequencer->hihat_output;;
//  hihat->sample_rate_input = inputs->sr;
//  hihat->sample_selection_input = kit_select->hihat_output;
//
//  // Mix everything together
//  mixer->input_1 = kick;
//  mixer->input_2 = snare;
//  mixer->input_3 = hihat;
//
//  // Apply some wave folding, just to make things exciting
//  wave_folder->audio_input = mixer;
//  wave_folder->lower_clipping_level_input = new ModuleConstant(1492);
//  wave_folder->upper_clipping_level_input = new ModuleConstant(2604);
//
//  this->last_module = wave_folder;
//

#ifndef ModuleSamplePlayer_h
#define ModuleSamplePlayer_h

#include "Arduino.h"
#include "Module.h"

class ModuleSamplePlayer : public Module
{
  
  public:
    ModuleSamplePlayer();
    uint16_t compute();

    // Inputs
    Module *sample_selection_input;
    Module *trigger_input;
    Module *sample_rate_input;    
    
  private:
    boolean triggered;
    boolean playing;
    
    uint32_t t;  // Accumulator used in equations 
    uint32_t w;  // The final output
    
    uint32_t fixed_point_20_12_index;

    void stop_playback();
};

#endif
