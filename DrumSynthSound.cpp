/*
 ==============================================================================
 
 DrumSynthSound.cpp
 Created: 29 Jan 2016 2:19:29pm
 Author:  George Demner
 
 ==============================================================================
 */
#include "JuceHeader.h"
#include "DrumSynthSound.h"
#include "Strings.h"

DrumSound::DrumSound (int n, int c, int fileNameIndex, int micIndex)
:   note (n), channel (c)
{
    File localDir = File::getSpecialLocation (File::currentExecutableFile).getParentDirectory().getParentDirectory().getChildFile ("Resources");
    
    AudioFormatManager formatManager;
    ScopedPointer<AudioFormatReader> drumReader[8];
    
    formatManager.registerFormat (new WavAudioFormat(), true);
    char charBuffer[128] = { 0 };
    if(micIndex == 9)
    {
        for (int v = 5; v < 6; v++)
        {
            for (int s = 0; s < 6; s++)
            {
                sprintf(charBuffer, "%s%s%s", fileName[fileNameIndex], velocityIndex[v], stringEnd[s]);
                
                File tempFile = localDir.getChildFile(charBuffer);
                
                drumReader[s] = formatManager.createReaderFor(tempFile);
                
                buffer.velocities[v].samples[s].setSize(drumReader[s]->numChannels, drumReader[s]->lengthInSamples);
                drumReader[s]->read(&buffer.velocities[v].samples[s],
                                    0,
                                    drumReader[s]->lengthInSamples,
                                    0,
                                    true,
                                    true);
                
                printf("sounds added: %s to %d_%d_%d \n", charBuffer, 0 ,v ,s);
            }
        }
    }
    else
    {
        for (int v = 5; v < 6; v++)
        {
            for (int s = 0; s < 6; s++)
            {
                sprintf(charBuffer, "%s%s%s%s", fileName[fileNameIndex], cymbalMics[micIndex], velocityIndex[v], stringEnd[s] );
                
                File tempFile = localDir.getChildFile(charBuffer);
                
                drumReader[s] = formatManager.createReaderFor(tempFile);
                
                buffer.velocities[v].samples[s].setSize(drumReader[s]->numChannels, drumReader[s]->lengthInSamples);
                drumReader[s]->read(&buffer.velocities[v].samples[s],
                                    0,
                                    drumReader[s]->lengthInSamples,
                                    0,
                                    true,
                                    true);
                
                printf("sounds added: %s to %d_%d_%d_%d \n", charBuffer, 0 ,v ,s, micIndex);
            }
        }
    }
}

bool DrumSound::appliesToNote (int midiNoteNumber)
{
    return note == midiNoteNumber;
}

bool DrumSound::appliesToChannel (int midiChannel)
{
    return channel == 0 || channel == midiChannel;
}
AudioSampleBuffer* DrumSound::getBufferForVelocity (float velocity)
{
    AudioSampleBuffer* tempBuffer = buffer.getVelRange(velocity)->getNextSample();
    return tempBuffer;
    // get the array of buffers for this velocity band
    // this will be the array of random variations
    // choose one of these and return a pointer to it..
    jassertfalse;
}


