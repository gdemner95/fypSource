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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MixerComponent.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MixerComponent::MixerComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (kickFader = new Slider ("Kick"));
    kickFader->setRange (0, 2, 0.1);
    kickFader->setSliderStyle (Slider::LinearVertical);
    kickFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    kickFader->setColour (Slider::thumbColourId, Colours::red);
    kickFader->setColour (Slider::trackColourId, Colours::grey);
    kickFader->addListener (this);
    kickFader->setSkewFactor (2);

    addAndMakeVisible (KickPan = new Slider ("KickPan"));
    KickPan->setRange (-64, 64, 1);
    KickPan->setSliderStyle (Slider::Rotary);
    KickPan->setTextBoxStyle (Slider::TextBoxAbove, false, 30, 20);
    KickPan->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickPan->setColour (Slider::textBoxBackgroundColourId, Colour (0xff565656));
    KickPan->addListener (this);

    addAndMakeVisible (KickVU = new Slider ("KickVU"));
    KickVU->setRange (0, 10, 0);
    KickVU->setSliderStyle (Slider::LinearBar);
    KickVU->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickVU->setColour (Slider::thumbColourId, Colours::red);
    KickVU->setColour (Slider::trackColourId, Colours::grey);
    KickVU->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickVU->addListener (this);
    KickVU->setSkewFactor (2);

    processor = processor->getProcessor();
    
    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MixerComponent::~MixerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    kickFader = nullptr;
    KickPan = nullptr;
    KickVU = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MixerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffe4e4e4));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MixerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    kickFader->setBounds (40, 408, 40, 168);
    KickPan->setBounds (32, 328, 64, 72);
    KickVU->setBounds (40, 416, 8, 128);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MixerComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == kickFader)
    {
//        processor->setSliderValue(1.0);
        
        //[UserSliderCode_kickFader] -- add your slider handling code here..
        //[/UserSliderCode_kickFader]
    }
    else if (sliderThatWasMoved == KickPan)
    {
        //[UserSliderCode_KickPan] -- add your slider handling code here..
        //[/UserSliderCode_KickPan]
    }
    else if (sliderThatWasMoved == KickVU)
    {
        //[UserSliderCode_KickVU] -- add your slider handling code here..
        //[/UserSliderCode_KickVU]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MixerComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffe4e4e4"/>
  <SLIDER name="Kick" id="502f2c88da794542" memberName="kickFader" virtualName=""
          explicitFocusOrder="0" pos="40 408 40 168" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="2" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="KickPan" id="4924464354e2c5dd" memberName="KickPan" virtualName=""
          explicitFocusOrder="0" pos="32 328 64 72" rotarysliderfill="ffff0000"
          textboxbkgd="ff565656" min="-64" max="64" int="1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="30"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickVU" id="9a686490ce1a9075" memberName="KickVU" virtualName=""
          explicitFocusOrder="0" pos="40 416 8 128" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
