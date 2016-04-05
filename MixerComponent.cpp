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

    addAndMakeVisible (kickInFader = new Slider ("KickIn"));
    kickInFader->setRange (0, 1, 0.1);
    kickInFader->setSliderStyle (Slider::LinearVertical);
    kickInFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    kickInFader->setColour (Slider::thumbColourId, Colours::red);
    kickInFader->setColour (Slider::trackColourId, Colours::grey);
    kickInFader->addListener (this);

    addAndMakeVisible (KickInVU = new Slider ("KickVU"));
    KickInVU->setRange (0, 10, 0);
    KickInVU->setSliderStyle (Slider::LinearBar);
    KickInVU->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickInVU->setColour (Slider::thumbColourId, Colours::red);
    KickInVU->setColour (Slider::trackColourId, Colours::grey);
    KickInVU->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickInVU->setColour (Slider::rotarySliderOutlineColourId, Colour (0x00000000));
    KickInVU->addListener (this);
    KickInVU->setSkewFactor (2);

    addAndMakeVisible (kickInPan = new Slider ("kickInPan"));
    kickInPan->setTooltip (TRANS("Panning"));
    kickInPan->setRange (0, 1, 0.1);
    kickInPan->setSliderStyle (Slider::LinearHorizontal);
    kickInPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    kickInPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    kickInPan->setColour (Slider::thumbColourId, Colours::red);
    kickInPan->setColour (Slider::trackColourId, Colours::grey);
    kickInPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    kickInPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    kickInPan->addListener (this);

    addAndMakeVisible (kickOutFader = new Slider ("KickOut"));
    kickOutFader->setRange (0, 1, 0.1);
    kickOutFader->setSliderStyle (Slider::LinearVertical);
    kickOutFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    kickOutFader->setColour (Slider::thumbColourId, Colours::red);
    kickOutFader->setColour (Slider::trackColourId, Colours::grey);
    kickOutFader->addListener (this);

    addAndMakeVisible (KickOutVU = new Slider ("KickOutVU"));
    KickOutVU->setRange (0, 10, 0);
    KickOutVU->setSliderStyle (Slider::LinearBar);
    KickOutVU->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU->addListener (this);
    KickOutVU->setSkewFactor (2);

    addAndMakeVisible (kickOutPan = new Slider ("kickOutPan"));
    kickOutPan->setTooltip (TRANS("Panning"));
    kickOutPan->setRange (0, 1, 0.1);
    kickOutPan->setSliderStyle (Slider::LinearHorizontal);
    kickOutPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    kickOutPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    kickOutPan->setColour (Slider::thumbColourId, Colours::red);
    kickOutPan->setColour (Slider::trackColourId, Colours::grey);
    kickOutPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    kickOutPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    kickOutPan->addListener (this);

    addAndMakeVisible (snareUpFader = new Slider ("snareUpFader"));
    snareUpFader->setRange (0, 1, 0.1);
    snareUpFader->setSliderStyle (Slider::LinearVertical);
    snareUpFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    snareUpFader->setColour (Slider::thumbColourId, Colours::red);
    snareUpFader->setColour (Slider::trackColourId, Colours::grey);
    snareUpFader->addListener (this);

    addAndMakeVisible (KickOutVU2 = new Slider ("KickOutVU"));
    KickOutVU2->setRange (0, 10, 0);
    KickOutVU2->setSliderStyle (Slider::LinearBar);
    KickOutVU2->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU2->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU2->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU2->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU2->addListener (this);
    KickOutVU2->setSkewFactor (2);

    addAndMakeVisible (snareUpPan = new Slider ("snareUpPan"));
    snareUpPan->setTooltip (TRANS("Panning"));
    snareUpPan->setRange (0, 1, 0.1);
    snareUpPan->setSliderStyle (Slider::LinearHorizontal);
    snareUpPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    snareUpPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    snareUpPan->setColour (Slider::thumbColourId, Colours::red);
    snareUpPan->setColour (Slider::trackColourId, Colours::grey);
    snareUpPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    snareUpPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    snareUpPan->addListener (this);

    addAndMakeVisible (snareDownFader = new Slider ("snareDownFader"));
    snareDownFader->setRange (0, 1, 0.1);
    snareDownFader->setSliderStyle (Slider::LinearVertical);
    snareDownFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    snareDownFader->setColour (Slider::thumbColourId, Colours::red);
    snareDownFader->setColour (Slider::trackColourId, Colours::grey);
    snareDownFader->addListener (this);

    addAndMakeVisible (KickOutVU3 = new Slider ("KickOutVU"));
    KickOutVU3->setRange (0, 10, 0);
    KickOutVU3->setSliderStyle (Slider::LinearBar);
    KickOutVU3->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU3->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU3->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU3->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU3->addListener (this);
    KickOutVU3->setSkewFactor (2);

    addAndMakeVisible (snareDownPan = new Slider ("snareDownPan"));
    snareDownPan->setTooltip (TRANS("Panning"));
    snareDownPan->setRange (0, 1, 0.1);
    snareDownPan->setSliderStyle (Slider::LinearHorizontal);
    snareDownPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    snareDownPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    snareDownPan->setColour (Slider::thumbColourId, Colours::red);
    snareDownPan->setColour (Slider::trackColourId, Colours::grey);
    snareDownPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    snareDownPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    snareDownPan->addListener (this);

    addAndMakeVisible (lowTomFader = new Slider ("lowTomFader"));
    lowTomFader->setRange (0, 1, 0.1);
    lowTomFader->setSliderStyle (Slider::LinearVertical);
    lowTomFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    lowTomFader->setColour (Slider::thumbColourId, Colours::red);
    lowTomFader->setColour (Slider::trackColourId, Colours::grey);
    lowTomFader->addListener (this);

    addAndMakeVisible (KickOutVU4 = new Slider ("KickOutVU"));
    KickOutVU4->setRange (0, 10, 0);
    KickOutVU4->setSliderStyle (Slider::LinearBar);
    KickOutVU4->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU4->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU4->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU4->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU4->addListener (this);
    KickOutVU4->setSkewFactor (2);

    addAndMakeVisible (lowTomPan = new Slider ("lowTomPan"));
    lowTomPan->setTooltip (TRANS("Panning"));
    lowTomPan->setRange (0, 1, 0.1);
    lowTomPan->setSliderStyle (Slider::LinearHorizontal);
    lowTomPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    lowTomPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    lowTomPan->setColour (Slider::thumbColourId, Colours::red);
    lowTomPan->setColour (Slider::trackColourId, Colours::grey);
    lowTomPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    lowTomPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    lowTomPan->addListener (this);

    addAndMakeVisible (midTomFader = new Slider ("midTomFader"));
    midTomFader->setRange (0, 1, 0.1);
    midTomFader->setSliderStyle (Slider::LinearVertical);
    midTomFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    midTomFader->setColour (Slider::thumbColourId, Colours::red);
    midTomFader->setColour (Slider::trackColourId, Colours::grey);
    midTomFader->addListener (this);

    addAndMakeVisible (KickOutVU5 = new Slider ("KickOutVU"));
    KickOutVU5->setRange (0, 10, 0);
    KickOutVU5->setSliderStyle (Slider::LinearBar);
    KickOutVU5->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU5->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU5->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU5->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU5->addListener (this);
    KickOutVU5->setSkewFactor (2);

    addAndMakeVisible (midTomPan = new Slider ("midTomPan"));
    midTomPan->setTooltip (TRANS("Panning"));
    midTomPan->setRange (0, 1, 0.1);
    midTomPan->setSliderStyle (Slider::LinearHorizontal);
    midTomPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    midTomPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    midTomPan->setColour (Slider::thumbColourId, Colours::red);
    midTomPan->setColour (Slider::trackColourId, Colours::grey);
    midTomPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    midTomPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    midTomPan->addListener (this);

    addAndMakeVisible (highTomFader = new Slider ("highTomFader"));
    highTomFader->setRange (0, 1, 0.1);
    highTomFader->setSliderStyle (Slider::LinearVertical);
    highTomFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    highTomFader->setColour (Slider::thumbColourId, Colours::red);
    highTomFader->setColour (Slider::trackColourId, Colours::grey);
    highTomFader->addListener (this);

    addAndMakeVisible (KickOutVU6 = new Slider ("KickOutVU"));
    KickOutVU6->setRange (0, 10, 0);
    KickOutVU6->setSliderStyle (Slider::LinearBar);
    KickOutVU6->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU6->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU6->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU6->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU6->addListener (this);
    KickOutVU6->setSkewFactor (2);

    addAndMakeVisible (highTomPan = new Slider ("highTomPan"));
    highTomPan->setTooltip (TRANS("Panning"));
    highTomPan->setRange (0, 1, 0.1);
    highTomPan->setSliderStyle (Slider::LinearHorizontal);
    highTomPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    highTomPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    highTomPan->setColour (Slider::thumbColourId, Colours::red);
    highTomPan->setColour (Slider::trackColourId, Colours::grey);
    highTomPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    highTomPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    highTomPan->addListener (this);

    addAndMakeVisible (hatsFader = new Slider ("hatsFader"));
    hatsFader->setRange (0, 1, 0.1);
    hatsFader->setSliderStyle (Slider::LinearVertical);
    hatsFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    hatsFader->setColour (Slider::thumbColourId, Colours::red);
    hatsFader->setColour (Slider::trackColourId, Colours::grey);
    hatsFader->addListener (this);

    addAndMakeVisible (KickOutVU7 = new Slider ("KickOutVU"));
    KickOutVU7->setRange (0, 10, 0);
    KickOutVU7->setSliderStyle (Slider::LinearBar);
    KickOutVU7->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU7->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU7->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU7->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU7->addListener (this);
    KickOutVU7->setSkewFactor (2);

    addAndMakeVisible (hatsPan = new Slider ("hatsPan"));
    hatsPan->setTooltip (TRANS("Panning"));
    hatsPan->setRange (0, 1, 0.1);
    hatsPan->setSliderStyle (Slider::LinearHorizontal);
    hatsPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    hatsPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    hatsPan->setColour (Slider::thumbColourId, Colours::red);
    hatsPan->setColour (Slider::trackColourId, Colours::grey);
    hatsPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    hatsPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    hatsPan->addListener (this);

    addAndMakeVisible (crashFader = new Slider ("crashFader"));
    crashFader->setRange (0, 1, 0.1);
    crashFader->setSliderStyle (Slider::LinearVertical);
    crashFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    crashFader->setColour (Slider::thumbColourId, Colours::red);
    crashFader->setColour (Slider::trackColourId, Colours::grey);
    crashFader->addListener (this);

    addAndMakeVisible (KickOutVU8 = new Slider ("KickOutVU"));
    KickOutVU8->setRange (0, 10, 0);
    KickOutVU8->setSliderStyle (Slider::LinearBar);
    KickOutVU8->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU8->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU8->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU8->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU8->addListener (this);
    KickOutVU8->setSkewFactor (2);

    addAndMakeVisible (crashPan = new Slider ("crashPan"));
    crashPan->setTooltip (TRANS("Panning"));
    crashPan->setRange (0, 1, 0.1);
    crashPan->setSliderStyle (Slider::LinearHorizontal);
    crashPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    crashPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    crashPan->setColour (Slider::thumbColourId, Colours::red);
    crashPan->setColour (Slider::trackColourId, Colours::grey);
    crashPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    crashPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    crashPan->addListener (this);

    addAndMakeVisible (splashFader = new Slider ("splashFader"));
    splashFader->setRange (0, 1, 0.1);
    splashFader->setSliderStyle (Slider::LinearVertical);
    splashFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    splashFader->setColour (Slider::thumbColourId, Colours::red);
    splashFader->setColour (Slider::trackColourId, Colours::grey);
    splashFader->addListener (this);

    addAndMakeVisible (KickOutVU9 = new Slider ("KickOutVU"));
    KickOutVU9->setRange (0, 10, 0);
    KickOutVU9->setSliderStyle (Slider::LinearBar);
    KickOutVU9->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU9->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU9->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU9->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU9->addListener (this);
    KickOutVU9->setSkewFactor (2);

    addAndMakeVisible (splashPan = new Slider ("splashPan"));
    splashPan->setTooltip (TRANS("Panning"));
    splashPan->setRange (0, 1, 0.1);
    splashPan->setSliderStyle (Slider::LinearHorizontal);
    splashPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    splashPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    splashPan->setColour (Slider::thumbColourId, Colours::red);
    splashPan->setColour (Slider::trackColourId, Colours::grey);
    splashPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    splashPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    splashPan->addListener (this);

    addAndMakeVisible (rideFader = new Slider ("rideFader"));
    rideFader->setRange (0, 1, 0.1);
    rideFader->setSliderStyle (Slider::LinearVertical);
    rideFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    rideFader->setColour (Slider::thumbColourId, Colours::red);
    rideFader->setColour (Slider::trackColourId, Colours::grey);
    rideFader->addListener (this);

    addAndMakeVisible (KickOutVU10 = new Slider ("KickOutVU"));
    KickOutVU10->setRange (0, 10, 0);
    KickOutVU10->setSliderStyle (Slider::LinearBar);
    KickOutVU10->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU10->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU10->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU10->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU10->addListener (this);
    KickOutVU10->setSkewFactor (2);

    addAndMakeVisible (ridePan = new Slider ("ridePan"));
    ridePan->setTooltip (TRANS("Panning"));
    ridePan->setRange (0, 1, 0.1);
    ridePan->setSliderStyle (Slider::LinearHorizontal);
    ridePan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    ridePan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    ridePan->setColour (Slider::thumbColourId, Colours::red);
    ridePan->setColour (Slider::trackColourId, Colours::grey);
    ridePan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    ridePan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    ridePan->addListener (this);

    addAndMakeVisible (chinaFader = new Slider ("chinaFader"));
    chinaFader->setRange (0, 1, 0.1);
    chinaFader->setSliderStyle (Slider::LinearVertical);
    chinaFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    chinaFader->setColour (Slider::thumbColourId, Colours::red);
    chinaFader->setColour (Slider::trackColourId, Colours::grey);
    chinaFader->addListener (this);

    addAndMakeVisible (KickOutVU11 = new Slider ("KickOutVU"));
    KickOutVU11->setRange (0, 10, 0);
    KickOutVU11->setSliderStyle (Slider::LinearBar);
    KickOutVU11->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU11->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU11->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU11->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU11->addListener (this);
    KickOutVU11->setSkewFactor (2);

    addAndMakeVisible (chinaPan = new Slider ("chinaPan"));
    chinaPan->setTooltip (TRANS("Panning"));
    chinaPan->setRange (0, 1, 0.1);
    chinaPan->setSliderStyle (Slider::LinearHorizontal);
    chinaPan->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    chinaPan->setColour (Slider::backgroundColourId, Colour (0x00000000));
    chinaPan->setColour (Slider::thumbColourId, Colours::red);
    chinaPan->setColour (Slider::trackColourId, Colours::grey);
    chinaPan->setColour (Slider::rotarySliderFillColourId, Colour (0x00000000));
    chinaPan->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    chinaPan->addListener (this);

    addAndMakeVisible (kickInButton = new TextButton ("KickInButton"));
    kickInButton->setButtonText (TRANS("Kick In"));
    kickInButton->addListener (this);
    kickInButton->setColour (TextButton::buttonColourId, Colours::grey);
    kickInButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    kickInButton->setColour (TextButton::textColourOnId, Colours::azure);
    kickInButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (kickOutButton = new TextButton ("kickOutButton"));
    kickOutButton->setButtonText (TRANS("Kick Out"));
    kickOutButton->addListener (this);
    kickOutButton->setColour (TextButton::buttonColourId, Colours::grey);
    kickOutButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    kickOutButton->setColour (TextButton::textColourOnId, Colours::azure);
    kickOutButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (snareUpButton = new TextButton ("snareUpButton"));
    snareUpButton->setButtonText (TRANS("Snare Up"));
    snareUpButton->addListener (this);
    snareUpButton->setColour (TextButton::buttonColourId, Colours::grey);
    snareUpButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    snareUpButton->setColour (TextButton::textColourOnId, Colours::azure);
    snareUpButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (snareDownButton = new TextButton ("snareDownButton"));
    snareDownButton->setButtonText (TRANS("Snare Down"));
    snareDownButton->addListener (this);
    snareDownButton->setColour (TextButton::buttonColourId, Colours::grey);
    snareDownButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    snareDownButton->setColour (TextButton::textColourOnId, Colours::azure);
    snareDownButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (lowTomButton = new TextButton ("lowTomButton"));
    lowTomButton->setButtonText (TRANS("Low Tom"));
    lowTomButton->addListener (this);
    lowTomButton->setColour (TextButton::buttonColourId, Colours::grey);
    lowTomButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    lowTomButton->setColour (TextButton::textColourOnId, Colours::azure);
    lowTomButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (midTomButton = new TextButton ("midTomButton"));
    midTomButton->setButtonText (TRANS("Mid Tom"));
    midTomButton->addListener (this);
    midTomButton->setColour (TextButton::buttonColourId, Colours::grey);
    midTomButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    midTomButton->setColour (TextButton::textColourOnId, Colours::azure);
    midTomButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (highTomButton = new TextButton ("highTomButton"));
    highTomButton->setButtonText (TRANS("High Tom"));
    highTomButton->addListener (this);
    highTomButton->setColour (TextButton::buttonColourId, Colours::grey);
    highTomButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    highTomButton->setColour (TextButton::textColourOnId, Colours::azure);
    highTomButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (hatsButton = new TextButton ("hatsButton"));
    hatsButton->setButtonText (TRANS("Hats"));
    hatsButton->addListener (this);
    hatsButton->setColour (TextButton::buttonColourId, Colours::grey);
    hatsButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    hatsButton->setColour (TextButton::textColourOnId, Colours::azure);
    hatsButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (crashLButton = new TextButton ("crashLButton"));
    crashLButton->setButtonText (TRANS("Crash Left"));
    crashLButton->addListener (this);
    crashLButton->setColour (TextButton::buttonColourId, Colours::grey);
    crashLButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    crashLButton->setColour (TextButton::textColourOnId, Colours::azure);
    crashLButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (splashButton = new TextButton ("splashButton"));
    splashButton->setButtonText (TRANS("Splash"));
    splashButton->addListener (this);
    splashButton->setColour (TextButton::buttonColourId, Colours::grey);
    splashButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    splashButton->setColour (TextButton::textColourOnId, Colours::azure);
    splashButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (rideButton = new TextButton ("rideButton"));
    rideButton->setButtonText (TRANS("Ride"));
    rideButton->addListener (this);
    rideButton->setColour (TextButton::buttonColourId, Colours::grey);
    rideButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    rideButton->setColour (TextButton::textColourOnId, Colours::azure);
    rideButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (chinaButton = new TextButton ("chinaButton"));
    chinaButton->setButtonText (TRANS("China"));
    chinaButton->addListener (this);
    chinaButton->setColour (TextButton::buttonColourId, Colours::grey);
    chinaButton->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    chinaButton->setColour (TextButton::textColourOnId, Colours::azure);
    chinaButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (ohFader = new Slider ("ohFader"));
    ohFader->setRange (0, 1, 0.1);
    ohFader->setSliderStyle (Slider::LinearVertical);
    ohFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    ohFader->setColour (Slider::thumbColourId, Colours::red);
    ohFader->setColour (Slider::trackColourId, Colours::grey);
    ohFader->addListener (this);

    addAndMakeVisible (KickOutVU12 = new Slider ("KickOutVU"));
    KickOutVU12->setRange (0, 10, 0);
    KickOutVU12->setSliderStyle (Slider::LinearBar);
    KickOutVU12->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU12->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU12->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU12->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU12->addListener (this);
    KickOutVU12->setSkewFactor (2);

    addAndMakeVisible (chinaButton2 = new TextButton ("chinaButton"));
    chinaButton2->setButtonText (TRANS("Over heads"));
    chinaButton2->addListener (this);
    chinaButton2->setColour (TextButton::buttonColourId, Colours::grey);
    chinaButton2->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    chinaButton2->setColour (TextButton::textColourOnId, Colours::azure);
    chinaButton2->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (roomFader = new Slider ("roomFader"));
    roomFader->setRange (0, 1, 0.1);
    roomFader->setSliderStyle (Slider::LinearVertical);
    roomFader->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    roomFader->setColour (Slider::thumbColourId, Colours::red);
    roomFader->setColour (Slider::trackColourId, Colours::grey);
    roomFader->addListener (this);

    addAndMakeVisible (KickOutVU13 = new Slider ("KickOutVU"));
    KickOutVU13->setRange (0, 10, 0);
    KickOutVU13->setSliderStyle (Slider::LinearBar);
    KickOutVU13->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    KickOutVU13->setColour (Slider::thumbColourId, Colours::red);
    KickOutVU13->setColour (Slider::trackColourId, Colours::grey);
    KickOutVU13->setColour (Slider::rotarySliderFillColourId, Colours::red);
    KickOutVU13->addListener (this);
    KickOutVU13->setSkewFactor (2);

    addAndMakeVisible (chinaButton3 = new TextButton ("chinaButton"));
    chinaButton3->setButtonText (TRANS("Room"));
    chinaButton3->addListener (this);
    chinaButton3->setColour (TextButton::buttonColourId, Colours::grey);
    chinaButton3->setColour (TextButton::buttonOnColourId, Colour (0x00000000));
    chinaButton3->setColour (TextButton::textColourOnId, Colours::azure);
    chinaButton3->setColour (TextButton::textColourOffId, Colours::black);


    //[UserPreSize]
//        for (int i = 0; i < 16; i++)
//        {
//            mySliders.add(new Slider("Slider"));
//            mySliders[i]->setSliderStyle(Slider::LinearVertical);
//            mySliders[i]->setTextBoxStyle(Slider::TextBoxBelow, false, 40, 20);
//            mySliders[i]->setBounds((i + 1) * 30, 20, 40, 160);
//            ohFader->setRange (0, 1, 0.1);
//            mySliders[i]->setColour (Slider::thumbColourId, Colours::red);
//            mySliders[i]->setColour (Slider::trackColourId, Colours::grey);
//            addAndMakeVisible(mySliders[i]);
//        }
    for (int i = 0; i < 16; i++)
    {
        channelStrips.add(new ChannelStrip());
        channelStrips[i]->setBounds(i * 60, 0, 60, 200);
        addAndMakeVisible(channelStrips[i]);
    }
//    addAndMakeVisible(strip1 = new ChannelStrip());
//    strip1->setBounds(0, 0, 60, 200);
    
    
    sliders.add(kickInFader);
    panners.add(kickInPan);
    ids.add(0);

    sliders.add(kickOutFader);
    panners.add(kickOutPan);
    ids.add(1);

    sliders.add(snareUpFader);
    panners.add(snareUpPan);
    ids.add(2);

    sliders.add(snareDownFader);
    panners.add(snareDownPan);
    ids.add(3);

    sliders.add(lowTomFader);
    panners.add(lowTomPan);
    ids.add(4);

    sliders.add(midTomFader);
    panners.add(midTomPan);
    ids.add(5);

    sliders.add(highTomFader);
    panners.add(highTomPan);
    ids.add(6);

    sliders.add(hatsFader);
    panners.add(hatsPan);
    ids.add(7);

    sliders.add(crashFader);
    panners.add(crashPan);
    ids.add(8);

    sliders.add(splashFader);
    panners.add(splashPan);
    ids.add(9);

    sliders.add(rideFader);
    panners.add(ridePan);
    ids.add(10);

    sliders.add(chinaFader);
    panners.add(chinaPan);
    ids.add(11);

    sliders.add(ohFader);
    ids.add(12);

    sliders.add(roomFader);
    ids.add(13);

//    for (int i = 0; i < 16; i++)
//    {
//        mySliders[i]->setSliderStyle(Slider::LinearVertical);
//        addAndMakeVisible(mySliders[i]);
//        
//    }
    
    
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    
    
    
    KickOutVU->setSliderStyle (Slider::LinearBarVertical);

    
    //[/Constructor]
}

MixerComponent::~MixerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    kickInFader = nullptr;
    KickInVU = nullptr;
    kickInPan = nullptr;
    kickOutFader = nullptr;
    KickOutVU = nullptr;
    kickOutPan = nullptr;
    snareUpFader = nullptr;
    KickOutVU2 = nullptr;
    snareUpPan = nullptr;
    snareDownFader = nullptr;
    KickOutVU3 = nullptr;
    snareDownPan = nullptr;
    lowTomFader = nullptr;
    KickOutVU4 = nullptr;
    lowTomPan = nullptr;
    midTomFader = nullptr;
    KickOutVU5 = nullptr;
    midTomPan = nullptr;
    highTomFader = nullptr;
    KickOutVU6 = nullptr;
    highTomPan = nullptr;
    hatsFader = nullptr;
    KickOutVU7 = nullptr;
    hatsPan = nullptr;
    crashFader = nullptr;
    KickOutVU8 = nullptr;
    crashPan = nullptr;
    splashFader = nullptr;
    KickOutVU9 = nullptr;
    splashPan = nullptr;
    rideFader = nullptr;
    KickOutVU10 = nullptr;
    ridePan = nullptr;
    chinaFader = nullptr;
    KickOutVU11 = nullptr;
    chinaPan = nullptr;
    kickInButton = nullptr;
    kickOutButton = nullptr;
    snareUpButton = nullptr;
    snareDownButton = nullptr;
    lowTomButton = nullptr;
    midTomButton = nullptr;
    highTomButton = nullptr;
    hatsButton = nullptr;
    crashLButton = nullptr;
    splashButton = nullptr;
    rideButton = nullptr;
    chinaButton = nullptr;
    ohFader = nullptr;
    KickOutVU12 = nullptr;
    chinaButton2 = nullptr;
    roomFader = nullptr;
    KickOutVU13 = nullptr;
    chinaButton3 = nullptr;


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

    kickInFader->setBounds (40, 410, 40, 160);
    KickInVU->setBounds (35, 415, 10, 130);
    kickInPan->setBounds (25, 385, 60, 25);
    kickOutFader->setBounds (105, 410, 40, 160);
    KickOutVU->setBounds (100, 415, 10, 130);
    kickOutPan->setBounds (90, 385, 60, 25);
    snareUpFader->setBounds (170, 410, 40, 160);
    KickOutVU2->setBounds (165, 415, 10, 130);
    snareUpPan->setBounds (155, 385, 60, 25);
    snareDownFader->setBounds (235, 410, 40, 160);
    KickOutVU3->setBounds (230, 415, 10, 130);
    snareDownPan->setBounds (220, 385, 60, 25);
    lowTomFader->setBounds (300, 410, 40, 160);
    KickOutVU4->setBounds (295, 415, 10, 130);
    lowTomPan->setBounds (285, 385, 60, 25);
    midTomFader->setBounds (365, 410, 40, 160);
    KickOutVU5->setBounds (360, 415, 10, 130);
    midTomPan->setBounds (350, 385, 60, 25);
    highTomFader->setBounds (430, 410, 40, 160);
    KickOutVU6->setBounds (425, 415, 10, 130);
    highTomPan->setBounds (416, 384, 59, 26);
    hatsFader->setBounds (495, 410, 40, 160);
    KickOutVU7->setBounds (490, 415, 10, 130);
    hatsPan->setBounds (480, 385, 60, 25);
    crashFader->setBounds (560, 410, 40, 160);
    KickOutVU8->setBounds (555, 415, 10, 130);
    crashPan->setBounds (545, 385, 60, 25);
    splashFader->setBounds (625, 410, 40, 160);
    KickOutVU9->setBounds (620, 415, 10, 130);
    splashPan->setBounds (610, 385, 60, 25);
    rideFader->setBounds (690, 410, 40, 160);
    KickOutVU10->setBounds (685, 415, 10, 130);
    ridePan->setBounds (675, 385, 60, 25);
    chinaFader->setBounds (755, 410, 40, 160);
    KickOutVU11->setBounds (750, 415, 10, 130);
    chinaPan->setBounds (740, 385, 60, 25);
    kickInButton->setBounds (35, 575, 50, 50);
    kickOutButton->setBounds (100, 575, 50, 50);
    snareUpButton->setBounds (165, 575, 50, 50);
    snareDownButton->setBounds (230, 575, 50, 50);
    lowTomButton->setBounds (295, 575, 50, 50);
    midTomButton->setBounds (360, 575, 50, 50);
    highTomButton->setBounds (425, 575, 50, 50);
    hatsButton->setBounds (490, 575, 50, 50);
    crashLButton->setBounds (555, 575, 50, 50);
    splashButton->setBounds (620, 575, 50, 50);
    rideButton->setBounds (685, 575, 50, 50);
    chinaButton->setBounds (750, 575, 50, 50);
    ohFader->setBounds (820, 410, 40, 160);
    KickOutVU12->setBounds (815, 415, 10, 130);
    chinaButton2->setBounds (815, 575, 50, 50);
    roomFader->setBounds (885, 410, 40, 160);
    KickOutVU13->setBounds (880, 415, 10, 130);
    chinaButton3->setBounds (880, 575, 50, 50);
    
    
    
    //[UserResized] Add your own custom resize handling here..
    
//    for (int i = 0; i < 16; i++)
//    {
//        mySliders[i]->setBounds((i+1) * 20, 20, 40, 160);
//        
//    }
    
    //[/UserResized]
}

void MixerComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    for (int i = 0; i < 16; i++)
    {
//        if (sliderThatWasMoved == mySliders.getUnchecked(i))
//        {
//            //send the value or something
//            break;
//        }
    }
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == kickInFader)
    {
        //[UserSliderCode_kickInFader] -- add your slider handling code here..
        //[/UserSliderCode_kickInFader]
    }
    else if (sliderThatWasMoved == KickInVU)
    {
        //[UserSliderCode_KickInVU] -- add your slider handling code here..
        //[/UserSliderCode_KickInVU]
    }
    else if (sliderThatWasMoved == kickInPan)
    {
        //[UserSliderCode_kickInPan] -- add your slider handling code here..
        //[/UserSliderCode_kickInPan]
    }
    else if (sliderThatWasMoved == kickOutFader)
    {
        //[UserSliderCode_kickOutFader] -- add your slider handling code here..
        //[/UserSliderCode_kickOutFader]
    }
    else if (sliderThatWasMoved == KickOutVU)
    {
        //[UserSliderCode_KickOutVU] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU]
    }
    else if (sliderThatWasMoved == kickOutPan)
    {
        //[UserSliderCode_kickOutPan] -- add your slider handling code here..
        //[/UserSliderCode_kickOutPan]
    }
    else if (sliderThatWasMoved == snareUpFader)
    {
        //[UserSliderCode_snareUpFader] -- add your slider handling code here..
        //[/UserSliderCode_snareUpFader]
    }
    else if (sliderThatWasMoved == KickOutVU2)
    {
        //[UserSliderCode_KickOutVU2] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU2]
    }
    else if (sliderThatWasMoved == snareUpPan)
    {
        //[UserSliderCode_snareUpPan] -- add your slider handling code here..
        //[/UserSliderCode_snareUpPan]
    }
    else if (sliderThatWasMoved == snareDownFader)
    {
        //[UserSliderCode_snareDownFader] -- add your slider handling code here..
        //[/UserSliderCode_snareDownFader]
    }
    else if (sliderThatWasMoved == KickOutVU3)
    {
        //[UserSliderCode_KickOutVU3] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU3]
    }
    else if (sliderThatWasMoved == snareDownPan)
    {
        //[UserSliderCode_snareDownPan] -- add your slider handling code here..
        //[/UserSliderCode_snareDownPan]
    }
    else if (sliderThatWasMoved == lowTomFader)
    {
        //[UserSliderCode_lowTomFader] -- add your slider handling code here..
        //[/UserSliderCode_lowTomFader]
    }
    else if (sliderThatWasMoved == KickOutVU4)
    {
        //[UserSliderCode_KickOutVU4] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU4]
    }
    else if (sliderThatWasMoved == lowTomPan)
    {
        //[UserSliderCode_lowTomPan] -- add your slider handling code here..
        //[/UserSliderCode_lowTomPan]
    }
    else if (sliderThatWasMoved == midTomFader)
    {
        //[UserSliderCode_midTomFader] -- add your slider handling code here..
        //[/UserSliderCode_midTomFader]
    }
    else if (sliderThatWasMoved == KickOutVU5)
    {
        //[UserSliderCode_KickOutVU5] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU5]
    }
    else if (sliderThatWasMoved == midTomPan)
    {
        //[UserSliderCode_midTomPan] -- add your slider handling code here..
        //[/UserSliderCode_midTomPan]
    }
    else if (sliderThatWasMoved == highTomFader)
    {
        //[UserSliderCode_highTomFader] -- add your slider handling code here..
        //[/UserSliderCode_highTomFader]
    }
    else if (sliderThatWasMoved == KickOutVU6)
    {
        //[UserSliderCode_KickOutVU6] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU6]
    }
    else if (sliderThatWasMoved == highTomPan)
    {
        //[UserSliderCode_highTomPan] -- add your slider handling code here..
        //[/UserSliderCode_highTomPan]
    }
    else if (sliderThatWasMoved == hatsFader)
    {
        //[UserSliderCode_hatsFader] -- add your slider handling code here..
        //[/UserSliderCode_hatsFader]
    }
    else if (sliderThatWasMoved == KickOutVU7)
    {
        //[UserSliderCode_KickOutVU7] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU7]
    }
    else if (sliderThatWasMoved == hatsPan)
    {
        //[UserSliderCode_hatsPan] -- add your slider handling code here..
        //[/UserSliderCode_hatsPan]
    }
    else if (sliderThatWasMoved == crashFader)
    {
        //[UserSliderCode_crashFader] -- add your slider handling code here..
        //[/UserSliderCode_crashFader]
    }
    else if (sliderThatWasMoved == KickOutVU8)
    {
        //[UserSliderCode_KickOutVU8] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU8]
    }
    else if (sliderThatWasMoved == crashPan)
    {
        //[UserSliderCode_crashPan] -- add your slider handling code here..
        //[/UserSliderCode_crashPan]
    }
    else if (sliderThatWasMoved == splashFader)
    {
        //[UserSliderCode_splashFader] -- add your slider handling code here..
        //[/UserSliderCode_splashFader]
    }
    else if (sliderThatWasMoved == KickOutVU9)
    {
        //[UserSliderCode_KickOutVU9] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU9]
    }
    else if (sliderThatWasMoved == splashPan)
    {
        //[UserSliderCode_splashPan] -- add your slider handling code here..
        //[/UserSliderCode_splashPan]
    }
    else if (sliderThatWasMoved == rideFader)
    {
        //[UserSliderCode_rideFader] -- add your slider handling code here..
        //[/UserSliderCode_rideFader]
    }
    else if (sliderThatWasMoved == KickOutVU10)
    {
        //[UserSliderCode_KickOutVU10] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU10]
    }
    else if (sliderThatWasMoved == ridePan)
    {
        //[UserSliderCode_ridePan] -- add your slider handling code here..
        //[/UserSliderCode_ridePan]
    }
    else if (sliderThatWasMoved == chinaFader)
    {
        //[UserSliderCode_chinaFader] -- add your slider handling code here..
        //[/UserSliderCode_chinaFader]
    }
    else if (sliderThatWasMoved == KickOutVU11)
    {
        //[UserSliderCode_KickOutVU11] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU11]
    }
    else if (sliderThatWasMoved == chinaPan)
    {
        //[UserSliderCode_chinaPan] -- add your slider handling code here..
        //[/UserSliderCode_chinaPan]
    }
    else if (sliderThatWasMoved == ohFader)
    {
        //[UserSliderCode_ohFader] -- add your slider handling code here..
        //[/UserSliderCode_ohFader]
    }
    else if (sliderThatWasMoved == KickOutVU12)
    {
        //[UserSliderCode_KickOutVU12] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU12]
    }
    else if (sliderThatWasMoved == roomFader)
    {
        //[UserSliderCode_roomFader] -- add your slider handling code here..
        //[/UserSliderCode_roomFader]
    }
    else if (sliderThatWasMoved == KickOutVU13)
    {
        //[UserSliderCode_KickOutVU13] -- add your slider handling code here..
        //[/UserSliderCode_KickOutVU13]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MixerComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == kickInButton)
    {
        //[UserButtonCode_kickInButton] -- add your button handler code here..
        //[/UserButtonCode_kickInButton]
    }
    else if (buttonThatWasClicked == kickOutButton)
    {
        //[UserButtonCode_kickOutButton] -- add your button handler code here..
        //[/UserButtonCode_kickOutButton]
    }
    else if (buttonThatWasClicked == snareUpButton)
    {
        //[UserButtonCode_snareUpButton] -- add your button handler code here..
        //[/UserButtonCode_snareUpButton]
    }
    else if (buttonThatWasClicked == snareDownButton)
    {
        //[UserButtonCode_snareDownButton] -- add your button handler code here..
        //[/UserButtonCode_snareDownButton]
    }
    else if (buttonThatWasClicked == lowTomButton)
    {
        //[UserButtonCode_lowTomButton] -- add your button handler code here..
        //[/UserButtonCode_lowTomButton]
    }
    else if (buttonThatWasClicked == midTomButton)
    {
        //[UserButtonCode_midTomButton] -- add your button handler code here..
        //[/UserButtonCode_midTomButton]
    }
    else if (buttonThatWasClicked == highTomButton)
    {
        //[UserButtonCode_highTomButton] -- add your button handler code here..
        //[/UserButtonCode_highTomButton]
    }
    else if (buttonThatWasClicked == hatsButton)
    {
        //[UserButtonCode_hatsButton] -- add your button handler code here..
        //[/UserButtonCode_hatsButton]
    }
    else if (buttonThatWasClicked == crashLButton)
    {
        //[UserButtonCode_crashLButton] -- add your button handler code here..
        //[/UserButtonCode_crashLButton]
    }
    else if (buttonThatWasClicked == splashButton)
    {
        //[UserButtonCode_splashButton] -- add your button handler code here..
        //[/UserButtonCode_splashButton]
    }
    else if (buttonThatWasClicked == rideButton)
    {
        //[UserButtonCode_rideButton] -- add your button handler code here..
        //[/UserButtonCode_rideButton]
    }
    else if (buttonThatWasClicked == chinaButton)
    {
        //[UserButtonCode_chinaButton] -- add your button handler code here..
        //[/UserButtonCode_chinaButton]
    }
    else if (buttonThatWasClicked == chinaButton2)
    {
        //[UserButtonCode_chinaButton2] -- add your button handler code here..
        //[/UserButtonCode_chinaButton2]
    }
    else if (buttonThatWasClicked == chinaButton3)
    {
        //[UserButtonCode_chinaButton3] -- add your button handler code here..
        //[/UserButtonCode_chinaButton3]
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

<JUCER_COMPONENT documentType="Component" className="MixerComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffe4e4e4"/>
  <SLIDER name="KickIn" id="502f2c88da794542" memberName="kickInFader"
          virtualName="" explicitFocusOrder="0" pos="40 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickVU" id="9a686490ce1a9075" memberName="KickInVU" virtualName=""
          explicitFocusOrder="0" pos="35 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" rotaryslideroutline="0"
          min="0" max="10" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="kickInPan" id="fe9ca562b73f9942" memberName="kickInPan"
          virtualName="" explicitFocusOrder="0" pos="25 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOut" id="427dfd1cb97e471d" memberName="kickOutFader"
          virtualName="" explicitFocusOrder="0" pos="105 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="4cf23a27962f98dc" memberName="KickOutVU"
          virtualName="" explicitFocusOrder="0" pos="100 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="kickOutPan" id="d89ee00779a275c2" memberName="kickOutPan"
          virtualName="" explicitFocusOrder="0" pos="90 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="snareUpFader" id="98268fecd230dd44" memberName="snareUpFader"
          virtualName="" explicitFocusOrder="0" pos="170 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="896d7fa08b9b4ca0" memberName="KickOutVU2"
          virtualName="" explicitFocusOrder="0" pos="165 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="snareUpPan" id="14c864c5afb46d0e" memberName="snareUpPan"
          virtualName="" explicitFocusOrder="0" pos="155 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="snareDownFader" id="a3fdd690c702f855" memberName="snareDownFader"
          virtualName="" explicitFocusOrder="0" pos="235 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="3e69dfb973acedd6" memberName="KickOutVU3"
          virtualName="" explicitFocusOrder="0" pos="230 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="snareDownPan" id="e976c10b69aa1cf6" memberName="snareDownPan"
          virtualName="" explicitFocusOrder="0" pos="220 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="lowTomFader" id="982e60b7c9aafddd" memberName="lowTomFader"
          virtualName="" explicitFocusOrder="0" pos="300 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="f04a69648ee13f15" memberName="KickOutVU4"
          virtualName="" explicitFocusOrder="0" pos="295 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="lowTomPan" id="fb8532dc94723cb7" memberName="lowTomPan"
          virtualName="" explicitFocusOrder="0" pos="285 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="midTomFader" id="7c0dfc73de23a26f" memberName="midTomFader"
          virtualName="" explicitFocusOrder="0" pos="365 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="fa47d177ed88b5cc" memberName="KickOutVU5"
          virtualName="" explicitFocusOrder="0" pos="360 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="midTomPan" id="719a268b685f8ac2" memberName="midTomPan"
          virtualName="" explicitFocusOrder="0" pos="350 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="highTomFader" id="c234fb256dad497a" memberName="highTomFader"
          virtualName="" explicitFocusOrder="0" pos="430 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="9de392d099028954" memberName="KickOutVU6"
          virtualName="" explicitFocusOrder="0" pos="425 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="highTomPan" id="9e627033612f8be7" memberName="highTomPan"
          virtualName="" explicitFocusOrder="0" pos="416 384 59 26" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="hatsFader" id="5025016217e7aeff" memberName="hatsFader"
          virtualName="" explicitFocusOrder="0" pos="495 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="d8b6b4f2e64f1a10" memberName="KickOutVU7"
          virtualName="" explicitFocusOrder="0" pos="490 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="hatsPan" id="5d55a75e977852d3" memberName="hatsPan" virtualName=""
          explicitFocusOrder="0" pos="480 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="crashFader" id="9a329e8e48ba0a03" memberName="crashFader"
          virtualName="" explicitFocusOrder="0" pos="560 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="a13ac6882579005f" memberName="KickOutVU8"
          virtualName="" explicitFocusOrder="0" pos="555 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="crashPan" id="43ddbc88da364451" memberName="crashPan" virtualName=""
          explicitFocusOrder="0" pos="545 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="splashFader" id="8375ce7b0738f30e" memberName="splashFader"
          virtualName="" explicitFocusOrder="0" pos="625 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="4e05b812e2a3aad" memberName="KickOutVU9"
          virtualName="" explicitFocusOrder="0" pos="620 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="splashPan" id="6d6ffe75649bc907" memberName="splashPan"
          virtualName="" explicitFocusOrder="0" pos="610 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="rideFader" id="2885e5d581ff2ad7" memberName="rideFader"
          virtualName="" explicitFocusOrder="0" pos="690 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="cebe8a43967e0742" memberName="KickOutVU10"
          virtualName="" explicitFocusOrder="0" pos="685 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="ridePan" id="b87d8beae6e8f2be" memberName="ridePan" virtualName=""
          explicitFocusOrder="0" pos="675 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="chinaFader" id="ad202ada80eb1db6" memberName="chinaFader"
          virtualName="" explicitFocusOrder="0" pos="755 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="a9417ab7af065720" memberName="KickOutVU11"
          virtualName="" explicitFocusOrder="0" pos="750 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="chinaPan" id="26dddec559dfb5c8" memberName="chinaPan" virtualName=""
          explicitFocusOrder="0" pos="740 385 60 25" tooltip="Panning"
          bkgcol="0" thumbcol="ffff0000" trackcol="ff808080" rotarysliderfill="0"
          rotaryslideroutline="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="KickInButton" id="dfdeb72a91172598" memberName="kickInButton"
              virtualName="" explicitFocusOrder="0" pos="35 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Kick In"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="kickOutButton" id="7b8f1c4631063085" memberName="kickOutButton"
              virtualName="" explicitFocusOrder="0" pos="100 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Kick Out"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="snareUpButton" id="463de4d86979e5c8" memberName="snareUpButton"
              virtualName="" explicitFocusOrder="0" pos="165 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Snare Up"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="snareDownButton" id="820fd3e4d540371f" memberName="snareDownButton"
              virtualName="" explicitFocusOrder="0" pos="230 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Snare Down"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="lowTomButton" id="38ae7896f6e3dd1c" memberName="lowTomButton"
              virtualName="" explicitFocusOrder="0" pos="295 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Low Tom"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="midTomButton" id="cb2076014216ab8a" memberName="midTomButton"
              virtualName="" explicitFocusOrder="0" pos="360 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Mid Tom"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="highTomButton" id="449fb9888889ed29" memberName="highTomButton"
              virtualName="" explicitFocusOrder="0" pos="425 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="High Tom"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="hatsButton" id="98c05172ecac92d8" memberName="hatsButton"
              virtualName="" explicitFocusOrder="0" pos="490 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Hats"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="crashLButton" id="86a859707e0ab936" memberName="crashLButton"
              virtualName="" explicitFocusOrder="0" pos="555 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Crash Left"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="splashButton" id="572a7d8070292515" memberName="splashButton"
              virtualName="" explicitFocusOrder="0" pos="620 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Splash"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="rideButton" id="f18abc7cacea7527" memberName="rideButton"
              virtualName="" explicitFocusOrder="0" pos="685 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Ride"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="chinaButton" id="a6c6686085aa8e5d" memberName="chinaButton"
              virtualName="" explicitFocusOrder="0" pos="750 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="China"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="ohFader" id="6f780b7b532e0f32" memberName="ohFader" virtualName=""
          explicitFocusOrder="0" pos="820 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="b1ae874dcc8d3d4b" memberName="KickOutVU12"
          virtualName="" explicitFocusOrder="0" pos="815 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <TEXTBUTTON name="chinaButton" id="f14d378edf6ef57e" memberName="chinaButton2"
              virtualName="" explicitFocusOrder="0" pos="815 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Over heads"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="roomFader" id="452f965d32fe9f2a" memberName="roomFader"
          virtualName="" explicitFocusOrder="0" pos="885 410 40 160" thumbcol="ffff0000"
          trackcol="ff808080" min="0" max="1" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="KickOutVU" id="99af572043f432c8" memberName="KickOutVU13"
          virtualName="" explicitFocusOrder="0" pos="880 415 10 130" thumbcol="ffff0000"
          trackcol="ff808080" rotarysliderfill="ffff0000" min="0" max="10"
          int="0" style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <TEXTBUTTON name="chinaButton" id="6e548e8e69cca907" memberName="chinaButton3"
              virtualName="" explicitFocusOrder="0" pos="880 575 50 50" bgColOff="ff808080"
              bgColOn="0" textCol="fff0ffff" textColOn="ff000000" buttonText="Room"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
