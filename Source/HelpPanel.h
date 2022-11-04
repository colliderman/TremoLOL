/*
  ==============================================================================

    HelpPanel.h
    Created: 3 Nov 2022 11:44:55am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class HelpPanel  : public juce::Component
{
public:
    HelpPanel();
    ~HelpPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelpPanel)
};
