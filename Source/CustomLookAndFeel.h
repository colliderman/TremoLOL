/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 3 Jan 2020 11:39:59pm
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

class CustomLookAndFeel : public LookAndFeel_V4
{
public:
    CustomLookAndFeel();
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
    
    Label * createSliderTextBox (Slider& slider) override;
    
private:
    
};
