/*
  ==============================================================================

    KnobsPanel.h
    Created: 23 Aug 2022 1:10:38pm
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//#include "CustomLookAndFeel.h"

class KnobsPanel : public Component
{
public:
    KnobsPanel (AudioProcessorValueTreeState&);
    ~KnobsPanel();
    
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
    void paint (Graphics&) override;
    void resized () override;
    
    
private:
    AudioProcessorValueTreeState& valueTreeState;
    //CustomLookAndFeel customLookAndFeel;
    //Font myFont {"Futura", "Medium", 22.0f};
    Font myFont;

    Slider speedKnob;
    Slider depthKnob;
    Slider gainKnob;
    
    Label speedKnobLabel;
    Label depthKnobLabel;
    Label gainKnobLabel;
    
    Label speedKnobValue;
    Label depthKnobValue;
    Label gainKnobValue;
    
    std::unique_ptr<SliderAttachment> depthAttachment;
    std::unique_ptr<SliderAttachment> speedAttachment;

};
