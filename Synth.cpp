/*
 ==============================================================================
 
 Synth.cpp
 Created: 7 Apr 2016 5:41:16pm
 Author:  George Demner
 
 ==============================================================================
 */

#include "Synth.h"
#include "DrumSynthSound.h"
#include "DrumSynthVoice.h"

void gSynth::noteOn (int midiChannel, int midiNoteNumber, float velocity)
{
    const ScopedLock sl (lock);
    
    for (int i = sounds.size(); --i >= 0;)
    {
        SynthesiserSound* const sound = sounds.getUnchecked(i);
        
        if (sound->appliesToNote (midiNoteNumber)
            && sound->appliesToChannel (midiChannel))
        {
            // If hitting a note that's still ringing, stop it first (it could be
            // still playing because of the sustain or sostenuto pedal).
            for (int j = voices.size(); --j >= 0;)
            {
                SynthesiserVoice* const voice = voices.getUnchecked (j);
                
                if (voice->getCurrentlyPlayingNote() == midiNoteNumber
                    && voice->isPlayingChannel (midiChannel))
                    stopVoice (voice, 1.0f, true);
            }
            
            SynthesiserVoice* voice = findFreeVoice (sound, midiChannel, midiNoteNumber, true);
            DrumSound* gSound = dynamic_cast<DrumSound*> (sound);
            
            if (gSound != nullptr)
            {
                if (gSound->checkHiHat(midiNoteNumber))
                {
                    for (int j = voices.size(); --j >= 0;)
                    {
                        SynthesiserVoice* const otherVoice = voices.getUnchecked (j);
                        DrumSynthVoice* gOtherVoice = dynamic_cast<DrumSynthVoice*> (otherVoice);
                        
                        if (otherVoice != nullptr && otherVoice != gOtherVoice && gOtherVoice->isHat())
                        {
                            stopVoice (voice, 1.0f, false);
                        }
                    }
                }
            }
            
            startVoice (voice, sound, midiChannel, midiNoteNumber, velocity);
        }
    }
};
void gSynth::noteOff (int midiChannel, int midiNoteNumber, float velocity, bool allowTailOff)
{
    const ScopedLock sl (lock);
    
    for (int i = voices.size(); --i >= 0;)
    {
        SynthesiserVoice* const voice = voices.getUnchecked (i);
        
        if (voice->getCurrentlyPlayingNote() == midiNoteNumber
            && voice->isPlayingChannel (midiChannel))
        {
            if (SynthesiserSound* const sound = voice->getCurrentlyPlayingSound())
            {
//                if (sound->appliesToNote (midiNoteNumber)
//                    && sound->appliesToChannel (midiChannel))
//                {
//                    jassert (! voice->keyIsDown || voice->sustainPedalDown == sustainPedalsDown [midiChannel]);
//                    
//                    voice->keyIsDown = false;
//                    
//                    if (! (voice->sustainPedalDown || voice->sostenutoPedalDown))
//                        stopVoice (voice, velocity, allowTailOff);
//                }
            }
        }
    }
};
