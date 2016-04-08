/*
 ==============================================================================
 
 DrumSynthVoice.cpp
 Created: 1 Feb 2016 1:43:06pm
 Author:  George Demner
 
 ==============================================================================
 */

#include "DrumSynthVoice.h"

void DrumSynthVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
    if(checkHiHat(midiNoteNumber))/*midiNoteNumber == 47 || midiNoteNumber == 54 || midiNoteNumber == 56 || midiNoteNumber == 58*/
    {
        printf("Start Note: Is A Hi Hat\n");
        DrumSynthVoice* tempVoice;
        for (int i = 0; i < p->synth.getNumVoices(); i++)
        {
            tempVoice = dynamic_cast<DrumSynthVoice*>(p->synth.getVoice(i));
            if(tempVoice != nullptr && tempVoice->isHiHat && tempVoice != this)
            {
                printf("%d:voice is a hi hat.\n", i);
                tempVoice->stopNote(0, false);
            }
            else
                printf("%d: Voice is not a hi hat!\n", i);
        }
    }
    else
    {
        printf("Start Note Is Not A Hi Hat\n");
    }
    
    jassert (dynamic_cast<DrumSound*> (sound) != nullptr);
    drumSound = static_cast<DrumSound*> (sound);
    
    currentDrumBuffer = drumSound->getBuffer(0, velocity);
    editor = static_cast<Fyp_samplerPrototype2AudioProcessorEditor*>(p->getActiveEditor());
    positionInBuffer = 0;
    level = velocity;
    
    /** Get level values */
    fLevel = editor->getSliderValue(drumSound->getID());
    
    /** Get panning values */
    fPan = editor->getPanLevel(drumSound->getID());
    tailOff = 0.0;
}

void DrumSynthVoice::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    //    printf("%d\n", numSamples);
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
                //                if(startSample % 256 == 0)
                //                {
                //                    editor->setMeter(drumSound->getID(), fabs(sampleValue));
                //                    printf("updated\n");
                //                }
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