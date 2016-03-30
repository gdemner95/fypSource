/*
  ==============================================================================

    DrumSynthVoice.cpp
    Created: 1 Feb 2016 1:43:06pm
    Author:  George Demner

  ==============================================================================
*/

#include "DrumSynthVoice.h"
#include "PluginEditor.h"
void DrumSynthVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
    jassert (dynamic_cast<DrumSound*> (sound) != nullptr);
    DrumSound* drumSound = static_cast<DrumSound*> (sound);
    
    currentDrumBuffer = drumSound->getBuffer(0, velocity);
    Fyp_samplerPrototype2AudioProcessorEditor* editor = static_cast<Fyp_samplerPrototype2AudioProcessorEditor*>(p->getActiveEditor());
    positionInBuffer = 0;
    level = velocity;
    //        vel = velocity;
    
    /** Get level values */
    fLevel = editor->getSliderValue(drumSound->getID());

    /** Get panning values */
    fPan = editor->getPanLevel(drumSound->getID());
    printf("Pan 0 = %f\n",fPan);

    printf("Level = %f\n",fLevel);
    tailOff = 0.0;
}