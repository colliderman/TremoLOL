/*
  ==============================================================================

    Knobs.h
    Created: 11 Nov 2022 9:01:48am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Knobs  : public juce::Component
{
public:
    Knobs();
    ~Knobs() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    std::unique_ptr<Slider> mSlider;
    std::unique_ptr<Label> mNameLabel;
    std::unique_ptr<Label> mValueLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Knobs)
};
