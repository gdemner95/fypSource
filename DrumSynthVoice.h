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
    };
    
    
    
    void pitchWheelMoved (int newPitchWheelValue) override {}
    void controllerMoved (int controllerNumber, int newControllerValue) override {}
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override;
    
    
    void stopNote(float velocity, bool allowTailOff) override{
        //        clearCurrentNote();
        //        currentDrumBuffer = nullptr;
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
        
    }
    
    void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override
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
    
private:
    float fLevel, fPan;
    double level, tailOff;
    Fyp_samplerPrototype2AudioProcessor* p;
    DrumSound* drumSound;
    AudioSampleBuffer* currentDrumBuffer;
    int positionInBuffer;
    
};

#endif  // DRUMSYNTHVOICE_H_INCLUDED
