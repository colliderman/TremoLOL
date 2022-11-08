/*
  ==============================================================================

    WaveformPanel.cpp
    Created: 2 Sep 2022 11:02:18am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "WaveformPanel.h"

//==============================================================================
WaveformPanel::WaveformPanel()
{
    setSize(168, 200);

}

WaveformPanel::~WaveformPanel()
{
}

void WaveformPanel::paint (Graphics& g)
{
    g.setColour(Colour (0xffDA8C30));
    
    //0.1f keeps corner radius constant when resizing
    //g.fillRoundedRectangle(0.0f, 0.0f, getWidth(), getHeight(), (float)getHeight()*0.1f);
    
    g.fillRoundedRectangle(getLocalBounds().toFloat(), (float)getHeight()*0.1f);
    
//    g.setColour(Colour (0xffDDA666));
//    
//    g.drawRoundedRectangle(getLocalBounds().toFloat() * 0.99f, (float)getHeight()*0.1f, (float)getLocalBounds().getHeight() * 0.01f); //2 pixel width
}

void WaveformPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
