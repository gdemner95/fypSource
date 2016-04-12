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
    sustainPedalDown = true;
    if(checkHiHat(midiNoteNumber))/*midiNoteNumber == 47 || midiNoteNumber == 54 || midiNoteNumber == 56 || midiNoteNumber == 58*/
    {
        DrumSynthVoice* tempVoice;
        for (int i = 0; i < p->synth.getNumVoices(); i++)
        {
            tempVoice = dynamic_cast<DrumSynthVoice*>(p->synth.getVoice(i));
            if(tempVoice != nullptr && tempVoice->isHiHat && tempVoice != this)
            {
                tempVoice->stopNote(0, true);
            }
        }
    }
    
    jassert (dynamic_cast<DrumSound*> (sound) != nullptr);
    drumSound = static_cast<DrumSound*> (sound);
    
    currentDrumBuffer = drumSound->getBuffer(0, velocity);
    editor = static_cast<Fyp_samplerPrototype2AudioProcessorEditor*>(p->getActiveEditor());
    positionInBuffer = 0;
    level = velocity;
    int ID = drumSound->getID();
    int micIndex = drumSound->getMic();
    if(ID == 12 || ID == 13)
    {
        if (micIndex == 1)
            fPan = 1 - editor->getStereoSliderValue(ID, 0);
        else if (micIndex == 2)
            fPan = editor->getStereoSliderValue(ID, 1);
        else if (micIndex == 3)
            fPan = 1 - editor->getStereoSliderValue(ID, 0);
        else if (micIndex == 4)
            fPan = editor->getStereoSliderValue(ID, 1);

    }
    else
    {
        fPan = editor->getSliderValue(ID);
    }
    
    /** Get level values */
    fLevel = editor->getSliderValue(drumSound->getID());
    
    /** Get panning values */
    fPan = editor->getPanLevel(drumSound->getID());
    tailOff = 0.0;
}

void DrumSynthVoice::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (currentDrumBuffer == nullptr)
        return;
    
    const AudioSampleBuffer& currentSound = *currentDrumBuffer;

    if (tailOff > 0)
    {
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
                            outputBuffer.addSample (i, startSample, ((sampleValue * (fLevel * level)) * (1 - fPan)) * tailOff);
                            break;
                        case 1:
                            outputBuffer.addSample (i, startSample, ((sampleValue * (fLevel * level)) * fPan) * tailOff);
                            break;
                    }
                    if(tailOff < 0.005)
                    {
                        clearCurrentNote();
                        currentDrumBuffer = nullptr;
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
            tailOff *= 0.99;
        }
    }
    else
    {
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
    }
    
};