/*
 ==============================================================================
 
 DrumSynth.h
 Created: 25 Feb 2016 9:19:38am
 Author:  George Demner
 
 ==============================================================================
 */

#ifndef DRUMSYNTH_H_INCLUDED
#define DRUMSYNTH_H_INCLUDED
#include "DrumSynthSound.cpp"

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
    
    DrumSound* getNextSample(){
        int chosen = randomNumbers[rand() % 10];
        printf("chosen sample: %d", chosen);
        return samples[chosen];
    };
    DrumSound* samples[6];
};

class Drum()
{
public:
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
private:
};

struct CymbalMics
{
    Drum mics[8];
};



#endif  // DRUMSYNTH_H_INCLUDED
