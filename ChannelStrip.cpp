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

#include "ChannelStrip.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//ChannelStrip::ChannelStrip (int channelID) : ID (channelID)

//[/MiscUserDefs]

//==============================================================================
ChannelStrip::ChannelStrip (int ID) : ID(ID)
{
    //[Constructor_pre] You can add your own custom stuff here..
    
    //[/Constructor_pre]
    
    //[UserPreSize]
    //[/UserPreSize]
    
    setSize (600, 400);
    
    
    //[Constructor] You can add your own custom stuff here..
    
    setSize(60, 180);
    
    addAndMakeVisible(fader = new Slider("Fader"));
    fader->setSliderStyle(Slider::LinearVertical);
    fader->setTextBoxStyle(Slider::TextBoxBelow, false, 40, 20);
    fader->setBounds(15, 30, 50, 160);
    fader->setRange (0, 1, 0.01);
    fader->setColour (Slider::thumbColourId, Colours::red);
    fader->setColour (Slider::trackColourId, Colours::grey);
    fader->addListener(this);
    
    addAndMakeVisible(panner = new Slider("Panner"));
    panner->setSliderStyle(Slider::LinearHorizontal);
    panner->setTextBoxStyle(Slider::NoTextBox, false, 40, 20);
    panner->setBounds(0, 0, 60, 20);
    panner->setRange (0, 1, 0.01);
    panner->setColour (Slider::thumbColourId, Colours::red);
    panner->setColour (Slider::trackColourId, Colours::grey);
    panner->addListener(this);
    
    
    addAndMakeVisible(meter = new Slider("meter"));
    meter->setSliderStyle(Slider::LinearBarVertical);
    meter->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    meter->setBounds(5, 30, 20, 130);
    meter->setRange (0, 1, 0.001);
    meter->setColour (Slider::thumbColourId, Colours::red);
    meter->setColour (Slider::trackColourId, Colours::grey);
    //    meter->setEnabled(false);
    meter->addListener(this);
    
    addAndMakeVisible(label = new Label);
    char buffer[128] = { 0 };
    sprintf(buffer, "%s", stripNames[ID]);
    label->setText(buffer, dontSendNotification);
    label->setBounds(0, 190, 60, 25);
    label->setJustificationType(4);
    
    if(ID == 12 || ID == 13)
    {
        addAndMakeVisible(panner2 = new Slider("Panner 2"));
        panner2->setSliderStyle(Slider::LinearHorizontal);
        panner2->setTextBoxStyle(Slider::NoTextBox, false, 40, 20);
        panner2->setBounds(0, 15, 60, 20);
        panner2->setRange (0, 1, 0.01);
        panner2->setColour (Slider::thumbColourId, Colours::red);
        panner2->setColour (Slider::trackColourId, Colours::grey);
        panner2->addListener(this);
    }
    //[/Constructor]
}

ChannelStrip::~ChannelStrip()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]
    
    
    
    //[Destructor]. You can add your own custom destruction code here..
    fader = nullptr;
    panner = nullptr;
    meter = nullptr;
    panner2 = nullptr;
    
    //[/Destructor]
}

//==============================================================================
void ChannelStrip::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]
    
    g.fillAll (Colours::white);
    
    //[UserPaint] Add your own custom painting code here..
    g.fillAll(Colours::grey);
    //[/UserPaint]
}

void ChannelStrip::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]
    
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ChannelStrip::sliderValueChanged (Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == fader)
    {
        faderValue = fader->getValue();
    }
    else if (sliderThatWasMoved == panner)
    {
        pannerValue = panner->getValue();
    }
    else if (sliderThatWasMoved == panner2)
    {
        panner2Value = panner2->getValue();
    }
    
}
void ChannelStrip::buttonClicked (Button* buttonThatWasClicked)
{
    
}
void ChannelStrip::setMeter(float input)
{
    meter->setValue(input, dontSendNotification);
}
float ChannelStrip::getFaderValue()
{
    return faderValue;
}
void ChannelStrip::setPan(float value)
{
    panner->setValue(value);
}
void ChannelStrip::setFader(float value)
{
    fader->setValue(value);
}
float ChannelStrip::getPan()
{
    return pannerValue;
}
float ChannelStrip::getStereoPan(int channel)
{
    switch (channel)
    {
        case 0:
            return panner->getValue();
        case 1:
            return panner2->getValue();
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --
 
 This is where the Introjucer stores the metadata that describe this GUI layout, so
 make changes in here at your peril!
 
 BEGIN_JUCER_METADATA
 
 <JUCER_COMPONENT documentType="Component" className="ChannelStrip" componentName=""
 parentClasses="public Component" constructorParams="" variableInitialisers=""
 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
 fixedSize="0" initialWidth="600" initialHeight="400">
 <BACKGROUND backgroundColour="ffffffff"/>
 </JUCER_COMPONENT>
 
 END_JUCER_METADATA
 */
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
