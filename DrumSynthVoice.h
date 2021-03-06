/*
 ==============================================================================
 
 DrumSynthVoice.h
 Created: 1 Feb 2016 1:43:06pm
 Author:  George Demner
 
 ==============================================================================
 */

#ifndef DRUMSYNTHVOICE_H_INCLUDED
#define DRUMSYNTHVOICE_H_INCLUDED

#include "JuceHeader.h"
#include "MixerComponent.h"
#include "DrumSynthSound.h"
#include "PluginProcessor.h"
#include "noteHandling.h"
#include "PluginEditor.h"

class DrumSynthVoice : public SynthesiserVoice
{
public:
    DrumSynthVoice(Fyp_samplerPrototype2AudioProcessor* processor)
    :   level(0.0),
    tailOff(0.0),
    isHiHat(false),
    shouldKill(false),
    p(processor),
    drumSound (nullptr),
    currentDrumBuffer (nullptr)
    {
        
    };
    
    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<DrumSound*>(sound) != nullptr;
    }
    
    bool checkHiHat(int noteNumber)
    {
        isHiHat = (noteNumber == 54 || noteNumber == 56 || noteNumber == 58 || noteNumber == 47);
        if (isHiHat == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isHat()
    {
        return isHiHat;
    }

    void pitchWheelMoved (int newPitchWheelValue) override {}
    void controllerMoved (int controllerNumber, int newControllerValue) override {}
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override;
    
    
    void stopNote(float velocity, bool allowTailOff) override
    {
        if (allowTailOff)
        {
            if(isHiHat)
            {
                if (tailOff == 0.0)
                    tailOff = 1.0;
                shouldKill = false;
            }
        }
        else
        {
            clearCurrentNote();
            currentDrumBuffer = nullptr;
        }
    }
    
    void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    
    void setMeter(int meterID, float value)
    {
        editor->setMeter( meterID, value);
    }
private:
    float fLevel, fPan;
    double level, tailOff;
    int check;
    bool isHiHat;
    bool shouldKill;
    bool keyIsDown;
    bool sustainPedalDown;
    float fPanL;
    float fPanR;
    ScopedPointer<noteHandler> noteHandle;
    Fyp_samplerPrototype2AudioProcessor* p;
    Fyp_samplerPrototype2AudioProcessorEditor* editor;
    DrumSound* drumSound;
    AudioSampleBuffer* currentDrumBuffer;
    int positionInBuffer;
    
};

#endif  // DRUMSYNTHVOICE_H_INCLUDED
