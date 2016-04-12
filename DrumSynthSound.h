/*
 ==============================================================================
 
 DrumSynthSound.h
 Created: 29 Jan 2016 2:19:29pm
 Author:  George Demner
 
 ==============================================================================
 */

#ifndef DRUMSYNTHSOUND_H_INCLUDED
#define DRUMSYNTHSOUND_H_INCLUDED

#include "JuceHeader.h"

struct VelRange
{
    const int randomNumbers[10] = {
        2,
        4,
        3,
        5,
        3,
        1,
        0,
        4,
        2,
        1,
    };
    
    AudioSampleBuffer* getNextSample(){
        int chosen = randomNumbers[rand() % 10];
        return &samples[chosen];
    };
    AudioSampleBuffer samples[6];
};

struct Drum
{
    VelRange* getVelRange(int velocity){
        if (velocity >= 0 & velocity < 21){
            //play lowest velocity for passed timbre
            return &velocities[0];
        }
        else if (velocity >= 21 & velocity < 40){
            return &velocities[1];
        }
        else if (velocity >= 41 & velocity < 60){
            return &velocities[2];
        }
        else if (velocity >= 61 & velocity < 80){
            return &velocities[3];
        }
        else if (velocity >= 81 & velocity < 90){
            return &velocities[4];
        }
        else
        {
            //play highest velocity for passed timbre
            return &velocities[5];
        }
    }
    
    VelRange velocities[6];
};

class DrumSound : public SynthesiserSound
{
public:
    DrumSound (int note, int channel, int fileNameIndex, int micIndex, int ID);
    virtual ~DrumSound() { }
    
    bool appliesToNote (int midiNoteNumber);
    bool appliesToChannel (int midiChannel);
    int getID();
    int getMic();
    //applies to slider?
    
    AudioSampleBuffer* getBufferForVelocity (float velocity);
    
    AudioSampleBuffer* getBuffer(int timbre, float velocity){
        velocity *= 127;
        return buffer.getVelRange(velocity)->getNextSample();
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
private:
    int note;
    int channel;
    int ID;
    int micIndex;
    bool isHiHat;
    
    Drum buffer;
};



#endif  // DRUMSYNTHSOUND_H_INCLUDED
