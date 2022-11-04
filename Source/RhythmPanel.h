/*
  ==============================================================================

    RhythmPanel.h
    Created: 2 Sep 2022 11:17:17am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class RhythmPanel    : public Component
{
public:
    RhythmPanel();
    ~RhythmPanel();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RhythmPanel)
};
