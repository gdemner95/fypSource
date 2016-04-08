/*
  ==============================================================================

    Synth.h
    Created: 7 Apr 2016 5:41:16pm
    Author:  George Demner

  ==============================================================================
*/

#ifndef SYNTH_H_INCLUDED
#define SYNTH_H_INCLUDED
#include "JuceHeader.h"
class gSynth : public Synthesiser
{
public:
    gSynth() {};
    ~gSynth() {};
    
    void noteOn (int midiChannel, int midiNoteNumber, float velocity) override;
    void noteOff (int midiChannel, int midiNoteNumber, float velocity, bool allowTailOff) override;
    
private:
    bool keyIsDown;
};
#endif  // SYNTH_H_INCLUDED
