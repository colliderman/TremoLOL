/*
  ==============================================================================

    ControlsPanel.h
    Created: 3 Nov 2022 11:44:18am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
//#include "CustomLookAndFeel.h"
#include "WaveformPanel.h"
#include "KnobsPanel.h"
#include "RhythmPanel.h"

//==============================================================================
/*
*/
class ControlsPanel  : public juce::Component
{
public:
    ControlsPanel();
    ~ControlsPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    WaveformPanel   waveformPanel;
    KnobsPanel      knobsPanel;
    RhythmPanel     rhythmPanel;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControlsPanel)
};
