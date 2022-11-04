/*
  ==============================================================================

    ControlsPanel.cpp
    Created: 3 Nov 2022 11:44:18am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ControlsPanel.h"

//==============================================================================
ControlsPanel::ControlsPanel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    addAndMakeVisible(waveformPanel);
    addAndMakeVisible(knobsPanel);
    addAndMakeVisible(rhythmPanel);

}

ControlsPanel::~ControlsPanel()
{
}

void ControlsPanel::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("ControlsPanel", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void ControlsPanel::resized()
{
    //Get the calculated size of the parent (PluginEditor) window to use to position the children
    auto area = getLocalBounds();
    auto controlPanelWidth = getLocalBounds().getWidth();
    auto controlMargins = controlPanelWidth * 0.024; //keeps margin proportional to 20px of original 824px width
    
    //Devide the ControlsPanel into 3 sections, maintaining a margin between them
    waveformPanel.setBounds(area.removeFromLeft(area.getWidth() * 0.240f).reduced(controlMargins, 0));
    rhythmPanel.setBounds(area.removeFromRight(area.getWidth() * 0.316f).reduced(controlMargins, 0));
    knobsPanel.setBounds(area);

}
