/*
  ==============================================================================

    LogoPanel.h
    Created: 3 Nov 2022 11:03:24am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class LogoPanel  : public juce::Component
{
public:
    LogoPanel();
    ~LogoPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    TextLayout logo;
    AttributedString logoString;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LogoPanel)
};
