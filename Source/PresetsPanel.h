/*
  ==============================================================================

    PresetsPanel.h
    Created: 3 Nov 2022 11:44:39am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomLookAndFeel.h"

//==============================================================================
/*
*/
class PresetsPanel  : public juce::Component
{
public:
    PresetsPanel();
    ~PresetsPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    CustomLookAndFeel customLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetsPanel)
};
