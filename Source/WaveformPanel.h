/*
  ==============================================================================

    WaveformPanel.h
    Created: 2 Sep 2022 11:02:18am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
*/
class WaveformPanel    : public Component
{
public:
    WaveformPanel();
    ~WaveformPanel();

    void paint (Graphics&) override;
    void resized() override;

private:

    Font myFont;
    
    Label shapeLabel;
        
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformPanel)
};
