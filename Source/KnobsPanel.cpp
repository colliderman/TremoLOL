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
    //LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);
    
    const auto borderSize = BorderSize<int>(0);
    
    myFont.setHeight(28.0f);
    
    speedKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    speedKnob.setTextBoxStyle(Slider::NoTextBox, 0, 0, 0);
//    speedKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 74, 29);
    speedKnob.setTextValueSuffix(" Hz");
//    speedKnob.setRange(0.0f, 1.0f);
    auto skr = NormalisableRange<double>(1, 240, 1);
    speedKnob.setNormalisableRange(skr);
    speedKnob.setValue(speedKnob.getMaximum()/2);
    
    addAndMakeVisible(speedKnob);
    
    depthKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    depthKnob.setTextBoxStyle(Slider::NoTextBox, 0, 0, 0);
    depthKnob.setTextValueSuffix(" %");
//    depthKnob.setRange(0.0f, 1.0f);
    auto dkr = NormalisableRange<double>(0, 100, 1);
    depthKnob.setNormalisableRange(dkr);
    depthKnob.setValue(depthKnob.getMaximum()/2);
    addAndMakeVisible(depthKnob);
    
    gainKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    gainKnob.setTextBoxStyle(Slider::NoTextBox, 0, 0, 0);
    gainKnob.setTextValueSuffix(" dB");
    auto gkr = NormalisableRange<double>(-30, 30, 0.1);
    gainKnob.setNormalisableRange(gkr);
//    gainKnob.setValue(gainKnob.);
    gainKnob.setValue(0.1);//this is a terrible workaround..
    //gainKnob.valueChanged();
    addAndMakeVisible(gainKnob);
    
    //Knob Labels
    
    speedKnobLabel.setText ("SPEED", juce::dontSendNotification);
    speedKnobLabel.setFont(myFont);
    speedKnobLabel.setColour (juce::Label::textColourId, juce::Colours::white);
    speedKnobLabel.setJustificationType (juce::Justification::verticallyCentred);
    speedKnobLabel.setMinimumHorizontalScale(1.0f);
    speedKnobLabel.setBorderSize(borderSize);
    addAndMakeVisible (speedKnobLabel);
    
    depthKnobLabel.setText ("DEPTH", juce::dontSendNotification);
    depthKnobLabel.setFont(myFont);
    depthKnobLabel.setColour (juce::Label::textColourId, juce::Colours::white);
    depthKnobLabel.setJustificationType (juce::Justification::centred);
    depthKnobLabel.setMinimumHorizontalScale(1.0f);
    depthKnobLabel.setBorderSize(borderSize);
    addAndMakeVisible (depthKnobLabel);
    
    gainKnobLabel.setText ("GAIN", juce::dontSendNotification);
    gainKnobLabel.setFont(myFont);
    gainKnobLabel.setColour (juce::Label::textColourId, juce::Colours::white);
    gainKnobLabel.setJustificationType (juce::Justification::centred);
    gainKnobLabel.setMinimumHorizontalScale(1.0f);
    gainKnobLabel.setBorderSize(borderSize);
    addAndMakeVisible (gainKnobLabel);
    
    //Value Labels
    speedKnob.onValueChange = [this] { speedKnobValue.setText(speedKnob.getTextFromValue(speedKnob.getValue()), dontSendNotification); };
    speedKnobValue.onTextChange = [this] { speedKnob.setValue(speedKnob.getValueFromText(speedKnobValue.getText())); };
    speedKnobValue.setEditable(true);
    speedKnobValue.setFont(myFont);
    speedKnobValue.setColour(Label::textColourId, Colours::white);
    speedKnobValue.setJustificationType(Justification::centred);
    speedKnobValue.setMinimumHorizontalScale(1.0f);
    speedKnobValue.setBorderSize(borderSize);
    addAndMakeVisible(speedKnobValue);
    
    depthKnob.onValueChange = [this] { depthKnobValue.setText(depthKnob.getTextFromValue(depthKnob.getValue()), dontSendNotification); };
    depthKnobValue.onTextChange = [this] { depthKnob.setValue(depthKnob.getValueFromText(depthKnobValue.getText())); };
    depthKnobValue.setEditable(true);
    depthKnobValue.setFont(myFont);
    depthKnobValue.setColour(Label::textColourId, Colours::white);
    depthKnobValue.setJustificationType(Justification::centred);
    depthKnobValue.setMinimumHorizontalScale(1.0f);
    depthKnobValue.setBorderSize(borderSize);
    addAndMakeVisible(depthKnobValue);
    
     gainKnob.onValueChange = [this] { gainKnobValue.setText(gainKnob.getTextFromValue(gainKnob.getValue()), dontSendNotification); };
    //gainKnobValue.setText(gainKnob.getTextFromValue(gainKnob.getValue()), dontSendNotification);
    gainKnobValue.onTextChange = [this] { gainKnob.setValue(gainKnob.getValueFromText(gainKnobValue.getText())); };
    gainKnobValue.setEditable(true);
    gainKnobValue.setFont(myFont);
    gainKnobValue.setColour(Label::textColourId, Colours::white);
    gainKnobValue.setJustificationType(Justification::centred);
    gainKnobValue.setMinimumHorizontalScale(1.0f);
    gainKnobValue.setBorderSize(borderSize);
    addAndMakeVisible(gainKnobValue);
    
    
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
    
    //for debugging
//    Rectangle<float>gainLabelRect(myFont.getStringWidthFloat(gainKnobLabel.getText()), myFont.getHeight());
//    g.setColour(Colours::pink);
//    g.drawRect(gainKnobLabel.getBounds());
//    g.drawRect(speedKnobLabel.getBounds());
//    g.drawRect(depthKnobLabel.getBounds());
    
//    g.setColour(Colours::blue);
//    g.drawRect(gainKnobValue.getBounds());
}


void KnobsPanel::resized()
{
    auto area = getLocalBounds();
    auto knobsPanelWidthDivided = area.getWidth() / 3;
    auto knobsPanelHeight = area.getHeight();
    auto knobMarginX = knobsPanelWidthDivided * 0.125f;//0.132f
    auto knobMarginY = knobsPanelHeight * 0.235f;
    
    speedKnob.setBounds(area.removeFromLeft(area.getWidth() / 3).reduced(knobMarginX, knobMarginY));
    depthKnob.setBounds(area.removeFromLeft(area.getWidth() / 2).reduced(knobMarginX, knobMarginY));
    gainKnob.setBounds(area.reduced(knobMarginX, knobMarginY));
    
    speedKnobLabel.setBoundsRelative(0.083f, 0.055f, 0.162f, 0.145f);
    depthKnobLabel.setBoundsRelative(0.417f, 0.055f, 0.167f, 0.145f);
    gainKnobLabel.setBoundsRelative(0.762f, 0.055f, 0.147f, 0.145f);
    
    speedKnobValue.setBoundsRelative(0.074f, 0.785f, 0.185f, 0.145f);
    depthKnobValue.setBoundsRelative(0.434f, 0.785f, 0.147f, 0.145f);
    gainKnobValue.setBoundsRelative(0.73f, 0.785f, 0.211f, 0.145f);
    
    auto newFontScaleFactor = (float)getBounds().getWidth() / 408.0f;
    myFont.setHeight(28.0f * newFontScaleFactor);
    
    speedKnobLabel.setFont(myFont);
    depthKnobLabel.setFont(myFont);
    gainKnobLabel.setFont(myFont);
    
    speedKnobValue.setFont(myFont);
    depthKnobValue.setFont(myFont);
    gainKnobValue.setFont(myFont);
    
}

