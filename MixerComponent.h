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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MixerComponent  : public Component,
                        public SliderListener
{
public:
    //==============================================================================
    MixerComponent ();
    ~MixerComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    float getSliderValue(int sliderID)
    {
        return kickFader->getValue();
    }
    float getPan(int pannerID)
    {
        return kickPan->getValue();
    }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> kickFader;
    ScopedPointer<Slider> KickPan;
    ScopedPointer<Slider> KickVU;
    ScopedPointer<Slider> kickPan;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_CAE02453DB8909B0__
