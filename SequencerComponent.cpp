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

#include "SequencerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SequencerComponent::SequencerComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->addListener (this);

    addAndMakeVisible (textButton2 = new TextButton ("new button"));
    textButton2->addListener (this);

    addAndMakeVisible (textButton3 = new TextButton ("new button"));
    textButton3->addListener (this);

    addAndMakeVisible (textButton4 = new TextButton ("new button"));
    textButton4->addListener (this);

    addAndMakeVisible (textButton5 = new TextButton ("new button"));
    textButton5->addListener (this);

    addAndMakeVisible (textButton6 = new TextButton ("new button"));
    textButton6->addListener (this);

    addAndMakeVisible (textButton7 = new TextButton ("new button"));
    textButton7->addListener (this);

    addAndMakeVisible (textButton8 = new TextButton ("new button"));
    textButton8->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SequencerComponent::~SequencerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;
    textButton2 = nullptr;
    textButton3 = nullptr;
    textButton4 = nullptr;
    textButton5 = nullptr;
    textButton6 = nullptr;
    textButton7 = nullptr;
    textButton8 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SequencerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::grey);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SequencerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (184, 64, 48, 56);
    textButton2->setBounds (248, 64, 48, 56);
    textButton3->setBounds (312, 64, 48, 56);
    textButton4->setBounds (376, 64, 48, 56);
    textButton5->setBounds (440, 64, 48, 56);
    textButton6->setBounds (504, 64, 48, 56);
    textButton7->setBounds (568, 64, 48, 56);
    textButton8->setBounds (632, 64, 48, 56);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SequencerComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        midiMessage.addEvent(MidiMessage::noteOn(1, 48, (uint8)127), 0);
        printf("Trigger\n");
//        (MidiMessage::noteOn(0, 48, 127));
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3)
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        //[/UserButtonCode_textButton3]
    }
    else if (buttonThatWasClicked == textButton4)
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
        //[/UserButtonCode_textButton4]
    }
    else if (buttonThatWasClicked == textButton5)
    {
        //[UserButtonCode_textButton5] -- add your button handler code here..
        //[/UserButtonCode_textButton5]
    }
    else if (buttonThatWasClicked == textButton6)
    {
        //[UserButtonCode_textButton6] -- add your button handler code here..
        //[/UserButtonCode_textButton6]
    }
    else if (buttonThatWasClicked == textButton7)
    {
        //[UserButtonCode_textButton7] -- add your button handler code here..
        //[/UserButtonCode_textButton7]
    }
    else if (buttonThatWasClicked == textButton8)
    {
        //[UserButtonCode_textButton8] -- add your button handler code here..
        //[/UserButtonCode_textButton8]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SequencerComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff808080"/>
  <TEXTBUTTON name="new button" id="7043139a8874ceda" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="184 64 48 56" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="48e0b572abfe2ae1" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="248 64 48 56" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a90a5e86f22d4055" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="312 64 48 56" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="e07324fc29eab325" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="376 64 48 56" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d963788fcf85484e" memberName="textButton5"
              virtualName="" explicitFocusOrder="0" pos="440 64 48 56" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="ed0ff031b249ce1d" memberName="textButton6"
              virtualName="" explicitFocusOrder="0" pos="504 64 48 56" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="6ad5b77abde5bbd" memberName="textButton7"
              virtualName="" explicitFocusOrder="0" pos="568 64 48 56" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="e36a063363597611" memberName="textButton8"
              virtualName="" explicitFocusOrder="0" pos="632 64 48 56" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
