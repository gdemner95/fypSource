/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "DrumSynthAudioSource.h"
#include "SamplerGUI.h"
#include "MixerComponent.h"


//==============================================================================
/**
*/
class Fyp_samplerPrototype2AudioProcessorEditor  : public AudioProcessorEditor, public Button::Listener
{
public:
    Fyp_samplerPrototype2AudioProcessorEditor (Fyp_samplerPrototype2AudioProcessor&);
    ~Fyp_samplerPrototype2AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void buttonClicked(Button* button) override;

    float getSliderValue()
    {
        return mixer.getSliderValue();
    }
    
private:
    TextButton kickButton;
    int lastInputIndex;
    MixerComponent mixer;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Fyp_samplerPrototype2AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Fyp_samplerPrototype2AudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
