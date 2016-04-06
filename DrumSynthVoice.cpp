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
    setPlayingHiHat(midiNoteNumber);
    if(isHiHat)
    {
    for (int i = 0; i < 32; i++)
    {
        DrumSynthVoice* tempVoice = static_cast<DrumSynthVoice*> (p->synth.getVoice(i));
        if (tempVoice->getPlayingHiHat())
        {
            
            if (tempVoice->check > 4){
                check = 0;
                break;
            }
            else
            {
                tempVoice->stopNote(1, false);
                check++;
            }
        }
    }
    }
    
    printf("VOICE");
    jassert (dynamic_cast<DrumSound*> (sound) != nullptr);
    DrumSound* drumSound = static_cast<DrumSound*> (sound);
    
    currentDrumBuffer = drumSound->getBuffer(0, velocity);
    Fyp_samplerPrototype2AudioProcessorEditor* editor = static_cast<Fyp_samplerPrototype2AudioProcessorEditor*>(p->getActiveEditor());
    positionInBuffer = 0;
    level = velocity;
    
    //is it muted?
    //is it soloed?
    
    /** Get level values */
    fLevel = editor->getSliderValue(drumSound->getID());

    /** Get panning values */
    fPan = editor->getPanLevel(drumSound->getID());
    printf("Pan 0 = %f\n",fPan);

    printf("Level = %f\n",fLevel);
    tailOff = 0.0;
}

void DrumSynthVoice::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (currentDrumBuffer == nullptr)
        return;
    
    const AudioSampleBuffer& currentSound = *currentDrumBuffer;
    
    while( --numSamples >= 0)
    {
        for(int i = outputBuffer.getNumChannels(); --i >= 0;)
        {
            if(positionInBuffer < currentSound.getNumSamples())
            {
                const float sampleValue = currentSound.getSample (i % currentSound.getNumChannels(), positionInBuffer);
                switch(i)
                {
                    case 0:
                        outputBuffer.addSample (i, startSample, (sampleValue * (fLevel * level)) * (1 - fPan));
                        break;
                    case 1:
                        outputBuffer.addSample (i, startSample, (sampleValue * (fLevel * level)) * fPan);
                        break;
                }
            }
            else
            {
                tailOff = 0.0;
                clearCurrentNote();
                currentDrumBuffer = nullptr;
                break;
            }
        }
        
        startSample++;
        positionInBuffer++;
    }
    //        }
}