/*
  ==============================================================================

    KnobsPanel.cpp
    Created: 23 Aug 2022 1:10:38pm
    Author:  Cody Gilchrist

  ==============================================================================
*/

#include "KnobsPanel.h"

KnobsPanel::KnobsPanel()
{
    //if this isn't here, font isn't Futura. Thought setting this
    //in PluginEditor constructor would affect this component because
    //it's a child but I guess not..
    LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);
    myFont.setHeight(29.0f);
    
    
    speedKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    speedKnob.setTextBoxStyle(Slider::NoTextBox, 0, 0, 0);
//    speedKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 74, 29);
//    speedKnob.setTextValueSuffix(" Hz");
    speedKnob.setRange(0.0f, 1.0f);
    speedKnob.setValue(speedKnob.getMaximum()/2);
    
    addAndMakeVisible(speedKnob);
    
    addAndMakeVisible (speedKnobLabel);
    speedKnobLabel.setText ("SPEED", juce::dontSendNotification);
    speedKnobLabel.setFont(myFont);
    //speedKnobLabel.attachToComponent (&speedKnob, false);
    speedKnobLabel.setColour (juce::Label::textColourId, juce::Colours::white);
    speedKnobLabel.setJustificationType (juce::Justification::verticallyCentred);
    
    depthKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    depthKnob.setTextBoxStyle(Slider::NoTextBox, 0, 0, 0);
    depthKnob.setRange(0.0f, 1.0f);
    depthKnob.setValue(depthKnob.getMaximum()/2);
    
    addAndMakeVisible(depthKnob);
    
    addAndMakeVisible (depthKnobLabel);
    depthKnobLabel.setText ("DEPTH", juce::dontSendNotification);
    depthKnobLabel.setFont(myFont);
    depthKnobLabel.setColour (juce::Label::textColourId, juce::Colours::white);
    //depthKnobLabel.setJustificationType (juce::Justification::centred);
    depthKnobLabel.setMinimumHorizontalScale(1.0f); //ensures it doesn't get horizontally scaled if bounding box too small
    
    gainKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    gainKnob.setTextBoxStyle(Slider::NoTextBox, 0, 0, 0);
    gainKnob.setRange(0.0f, 1.0f);
    gainKnob.setValue(depthKnob.getMaximum()/2);
    
    addAndMakeVisible(gainKnob);
    
    addAndMakeVisible (gainKnobLabel);
    gainKnobLabel.setText ("GAIN", juce::dontSendNotification);
    gainKnobLabel.setFont(myFont);
    //speedKnobLabel.attachToComponent (&speedKnob, false);
    gainKnobLabel.setColour (juce::Label::textColourId, juce::Colours::white);
    gainKnobLabel.setJustificationType (juce::Justification::centred);
    gainKnobLabel.setMinimumHorizontalScale(1.0f);
    
    setSize(408, 200);
}

KnobsPanel::~KnobsPanel()
{
    
}

void KnobsPanel::paint(Graphics &g)
{
    g.setColour(Colour (0xffDA8C30));
    
    //0.1f keeps corner radius constant when resizing
    g.fillRoundedRectangle(0.0f, 0.0f, getWidth(), getHeight(), (float)getHeight()*0.1f);
//
    g.setColour(Colours::blue);
    g.fillRect(speedKnobLabel.getBounds());
    
    //for debugging
    Rectangle<float>gainLabelRect(myFont.getStringWidthFloat(gainKnobLabel.getText()), myFont.getHeight());
    g.setColour(Colours::pink);
    g.drawRect(gainKnobLabel.getBounds());
    
}

void KnobsPanel::resized()
{
    //thought this might make knobspanel resize but it does not..
//    setBounds(0.0f, 0.0f, getLocalBounds().getWidth(), getLocalBounds().getHeight());
    
    //None of these worked to resize knobs panel either
    //setSize(getLocalBounds().getWidth(), getLocalBounds().getHeight());
    //setSize(getBounds().getWidth(), getBounds().getHeight());
    //setSize(getBoundsInParent().getWidth(), getBoundsInParent().getHeight());
    
  // ===========================================================================
    
//    speedKnob.setBoundsRelative(0.042f, 0.25f, 0.25f, 0.51f);
//    depthKnob.setBoundsRelative(0.377f, 0.25f, 0.25f, 0.51f);
//    gainKnob.setBoundsRelative(0.713f, 0.25f, 0.25f, 0.51f);
    
    auto area = getLocalBounds();
    auto knobsPanelWidthDivided = area.getWidth() / 3;
    auto knobsPanelHeight = area.getHeight();
    auto knobMarginX = knobsPanelWidthDivided * 0.132f;
    auto knobMarginY = knobsPanelHeight * 0.25f;
    
    speedKnob.setBounds(area.removeFromLeft(area.getWidth() / 3).reduced(knobMarginX, knobMarginY));
    depthKnob.setBounds(area.removeFromLeft(area.getWidth() / 2).reduced(knobMarginX, knobMarginY));
    gainKnob.setBounds(area.reduced(knobMarginX, knobMarginY));

    speedKnobLabel.setSize(area.getWidth() * 0.162, area.getHeight() * 0.145);
    speedKnobLabel.setCentreRelative(speedKnob.getLocalBounds().getWidth()/2, -speedKnob.getLocalBounds().getHeight()/2);
    //speedKnobLabel.setBoundsRelative(speedKnob.getWidth()/2 - speedKnobLabel.getWidth()/2, speedKnob.getHeight()/2, <#float proportionalWidth#>, <#float proportionalHeight#>)
    //speedKnobLabel.setBoundsRelative(0.083f, 0.055f, 0.3, 0.3);//0.162, 0.145
//    depthKnobLabel.setBoundsRelative(0.417f, 0.055f, 0.167f, 0.145f);
    
    
    //gainKnobLabel.setBoundsRelative(0.762f, 0.055f, 0.147f, 0.145f);
    //this is just hard coded to see how big the bounding box needs to be before it doesn't cut off text
    gainKnobLabel.setBounds(311, 11, 80, 35);
    
//    depthKnobLabel.setBoundsRelative(0.417f, 0.055f, myFont.getStringWidthFloat(depthKnobLabel.getText()), myFont.getHeight());
    depthKnobLabel.setSize(myFont.getStringWidth(depthKnobLabel.getText()), myFont.getHeight());
    depthKnobLabel.setCentrePosition(getLocalBounds().getWidth() / 2, area.getHeight() * 0.05f);
    
    //this kinda works but I think it needs to be done a better way..
    //auto newFontScaleFactor = (((float)getBounds().getWidth() - 408.0f)/408.0f) + 1.0f;
    //myFont.setHeight(29.0f * newFontScaleFactor);
    
    //speedKnobLabel.setFont(myFont);
    depthKnobLabel.setFont(myFont);
    //gainKnobLabel.setFont(myFont);
    
    //DBG(speedKnobLabel.getFont().getTypefaceName());
    //DBG(depthKnobLabel.getFont().getTypefaceName());
    DBG(gainKnobLabel.getFont().getStringWidth(gainKnobLabel.getText()));
    DBG(gainKnobLabel.getFont().getHeight());

    
}


