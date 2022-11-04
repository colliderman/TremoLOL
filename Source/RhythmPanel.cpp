/*
  ==============================================================================

    RhythmPanel.cpp
    Created: 2 Sep 2022 11:17:17am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "RhythmPanel.h"

//==============================================================================
RhythmPanel::RhythmPanel()
{
    setSize(168, 200);

}

RhythmPanel::~RhythmPanel()
{
}

void RhythmPanel::paint (Graphics& g)
{
    g.setColour(Colour (0xffDA8C30));
    
    //0.1f keeps corner radius constant when resizing
    g.fillRoundedRectangle(0.0f, 0.0f, getWidth(), getHeight(), (float)getHeight()*0.1f);
}

void RhythmPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
