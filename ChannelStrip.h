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

#ifndef __JUCE_HEADER_DBD2159E47CBB1D6__
#define __JUCE_HEADER_DBD2159E47CBB1D6__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
 An auto-generated component, created by the Introjucer.

 Describe your class and how it works here!


 ChannelStrip (int channelID);

                                                                    //[/Comments]
*/
class ChannelStrip  : public Component, public Button::Listener, public SliderListener
{
public:
    //==============================================================================
    ChannelStrip (int ID);
    ~ChannelStrip();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    float getFaderValue();
    float getPan();
    float getStereoPan(int channel);
    void setPan(float value);
    void setFader(float value);
    void setMeter(float input);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ScopedPointer<Slider> fader;
    ScopedPointer<Slider> meter;
    ScopedPointer<Slider> panner;
    ScopedPointer<Slider> panner2;
    ScopedPointer<Label> label;
    float faderValue;
    float pannerValue;
    float panner2Value;
    int ID;
    const char* stripNames[14] =
    {
        "BD In",
        "BD Out",
        "Snr Up",
        "Snr Down",
        "H. Tom",
        "M. Tom",
        "F. Tom",
        "Hats",
        "Crash",
        "Splash",
        "Ride",
        "China",
        "OH",
        "Room"
    };
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChannelStrip)
};

//[EndFile] You can add extra defines here...

//[/EndFile]

#endif   // __JUCE_HEADER_DBD2159E47CBB1D6__
