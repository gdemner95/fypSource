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
class DrumSynthVoice : public SynthesiserVoice
{
public:
    DrumSynthVoice(Fyp_samplerPrototype2AudioProcessor* processor)
    :   level(0.0),
    tailOff(0.0), /*drumSound (nullptr)*/
    p(processor),
    currentDrumBuffer (nullptr)
    {
        
    };
    
    bool canPlaySound(SynthesiserSound* sound) override {
        
        return dynamic_cast<DrumSound*>(sound) != nullptr;
    }
    
    void setPlayingHiHat(int noteNumber){
        if (noteNumber == 54 || noteNumber == 56 || noteNumber == 58 || noteNumber == 47)
        {
             isHiHat = true;
        }

    }
    bool getPlayingHiHat()
    {
        if(isHiHat)
            return true;
        else
            return false;
    }
    
    void pitchWheelMoved (int newPitchWheelValue) override {}
    void controllerMoved (int controllerNumber, int newControllerValue) override {}
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override;
    
    
    void stopNote(float velocity, bool allowTailOff) override
    {
        allowTailOff = true;
        if (allowTailOff)
        {
            if (tailOff == 0.0)
                tailOff = 1.0;
        }
        else
        {
            clearCurrentNote();
            currentDrumBuffer = nullptr;
        }
        if(velocity == 1){
            clearCurrentNote();
            currentDrumBuffer = nullptr;
        }
    }
    
    void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    
    
private:
    float fLevel, fPan;
    double level, tailOff;
    bool isHiHat;
    int check;
    ScopedPointer<noteHandler> noteHandle;
    Fyp_samplerPrototype2AudioProcessor* p;
    DrumSound* drumSound;
    AudioSampleBuffer* currentDrumBuffer;
    int positionInBuffer;
    
};

#endif  // DRUMSYNTHVOICE_H_INCLUDED
