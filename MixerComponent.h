/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_CAE02453DB8909B0__
#define __JUCE_HEADER_CAE02453DB8909B0__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//#include "Strings.h"
#include "ChannelStrip.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
 
 The component that builds the mixer interface. 
                                                                    //[/Comments]
*/
class MixerComponent  : public Component
{
public:
    //==============================================================================
    MixerComponent ();
    ~MixerComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    float getSliderValue(int sliderID)
    {
        return channelStrips[sliderID]->getFaderValue();
    }
    float getPan(int pannerID)
    {
        return channelStrips[pannerID]->getPan();
    }
    void setDefaults(){
        for (int i = 0; i < 14; i++)
        {
            channelStrips[i]->setFader(1.0);
            channelStrips[i]->setPan(0.5);
        }
    }
    void setMeter(int meterID, float value)
    {
        channelStrips[meterID]->setMeter(value);
    }
    float getStereoPan(int ID, int channel)
    {
        return channelStrips[ID]->getStereoPan(channel);
    };

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    Array<ChannelStrip*> channelStrips;
    ScopedPointer<ChannelStrip> tempStrip;

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_CAE02453DB8909B0__
