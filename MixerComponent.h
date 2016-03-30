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
                        public SliderListener,
                        public ButtonListener
{
public:
    //==============================================================================
    MixerComponent ();
    ~MixerComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    float getSliderValue(int sliderID)
    {
        int index = ids.indexOf(sliderID);

        return sliders[index]->getValue();
    }
    float getPan(int pannerID)
    {
        int index = ids.indexOf(pannerID);
        if(panners[index] != nullptr)
            return panners[index]->getValue();
    }
    void setDefaults(){
        for (int i = 0; i <= 13; i++)
        {
            if(panners[i] != nullptr)
                panners[i]->setValue(0.5, dontSendNotification);
            
            sliders[i]->setValue(1.0, dontSendNotification);
        }
    }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Array<Slider*>  sliders;
    Array<Slider*>  panners;
    Array<int>      ids;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> kickInFader;
    ScopedPointer<Slider> KickInVU;
    ScopedPointer<Slider> kickInPan;
    ScopedPointer<Slider> kickOutFader;
    ScopedPointer<Slider> KickOutVU;
    ScopedPointer<Slider> kickOutPan;
    ScopedPointer<Slider> snareUpFader;
    ScopedPointer<Slider> KickOutVU2;
    ScopedPointer<Slider> snareUpPan;
    ScopedPointer<Slider> snareDownFader;
    ScopedPointer<Slider> KickOutVU3;
    ScopedPointer<Slider> snareDownPan;
    ScopedPointer<Slider> lowTomFader;
    ScopedPointer<Slider> KickOutVU4;
    ScopedPointer<Slider> lowTomPan;
    ScopedPointer<Slider> midTomFader;
    ScopedPointer<Slider> KickOutVU5;
    ScopedPointer<Slider> midTomPan;
    ScopedPointer<Slider> highTomFader;
    ScopedPointer<Slider> KickOutVU6;
    ScopedPointer<Slider> highTomPan;
    ScopedPointer<Slider> hatsFader;
    ScopedPointer<Slider> KickOutVU7;
    ScopedPointer<Slider> hatsPan;
    ScopedPointer<Slider> crashFader;
    ScopedPointer<Slider> KickOutVU8;
    ScopedPointer<Slider> crashPan;
    ScopedPointer<Slider> splashFader;
    ScopedPointer<Slider> KickOutVU9;
    ScopedPointer<Slider> splashPan;
    ScopedPointer<Slider> rideFader;
    ScopedPointer<Slider> KickOutVU10;
    ScopedPointer<Slider> ridePan;
    ScopedPointer<Slider> chinaFader;
    ScopedPointer<Slider> KickOutVU11;
    ScopedPointer<Slider> chinaPan;
    ScopedPointer<TextButton> kickInButton;
    ScopedPointer<TextButton> kickOutButton;
    ScopedPointer<TextButton> snareUpButton;
    ScopedPointer<TextButton> snareDownButton;
    ScopedPointer<TextButton> lowTomButton;
    ScopedPointer<TextButton> midTomButton;
    ScopedPointer<TextButton> highTomButton;
    ScopedPointer<TextButton> hatsButton;
    ScopedPointer<TextButton> crashLButton;
    ScopedPointer<TextButton> splashButton;
    ScopedPointer<TextButton> rideButton;
    ScopedPointer<TextButton> chinaButton;
    ScopedPointer<Slider> ohFader;
    ScopedPointer<Slider> KickOutVU12;
    ScopedPointer<TextButton> chinaButton2;
    ScopedPointer<Slider> roomFader;
    ScopedPointer<Slider> KickOutVU13;
    ScopedPointer<TextButton> chinaButton3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_CAE02453DB8909B0__
