/*
  ==============================================================================

    LogoPanel.cpp
    Created: 3 Nov 2022 11:03:24am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LogoPanel.h"

//==============================================================================
Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::paint (juce::Graphics& g)
{
    Rectangle<float> area(font.getStringWidthFloat(attString.getText()), font.getHeight());
    
    textLayout.draw(g, area);
    
    //for debugging
//    g.setColour(Colours::pink);
//    g.drawRect(area);
}

void Logo::resized()
{
    
}

void Logo::setText(const String& string, Font& fontToUse, Colour colour)
{
    attString.append(string, fontToUse, colour);

    font = fontToUse;
}

void Logo::createLayout()
{
    textLayout.createLayout(attString, font.getStringWidthFloat(attString.getText()));
}

void Logo::setFont(Font &fontToUse)
{
    font = fontToUse;
    attString.setFont(font);
    textLayout.createLayout(attString, font.getStringWidthFloat(attString.getText()));
    repaint();
}

//==========================================================================

LogoPanel::LogoPanel()
{
    LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);
    
    myFont.setHeight(84.0f);
    pluginLogo.setText("Tremo", myFont, Colours::white);
    pluginLogo.setText("LOL", myFont, Colours::orange);
    pluginLogo.createLayout();
    addAndMakeVisible(pluginLogo);
    
    myFont.setHeight(26.0f);
    String version = ProjectInfo::versionString;
    versionLogo.setText("Version " + version, myFont, Colours::white);
    versionLogo.createLayout();
    addAndMakeVisible(versionLogo);
    
    myFont.setHeight(26.0f); //probably don't need to call this again here..
    websiteLogo.setText("www.", myFont, Colours::white);
    websiteLogo.setText("squidsonics", myFont, Colours::orange);
    websiteLogo.setText(".com", myFont, Colours::white);
    websiteLogo.createLayout();
    addAndMakeVisible(websiteLogo);
}

LogoPanel::~LogoPanel()
{
}

void LogoPanel::paint (juce::Graphics& g)
{

//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background
//
//    g.setColour (juce::Colours::grey);
//    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
//
//    g.setColour (juce::Colours::white);
//    g.setFont (14.0f);
//    g.drawText ("LogoPanel", getLocalBounds(),
//                juce::Justification::centred, true);   // draw some placeholder text
//
//    Rectangle<float>logoRect(myFont.getStringWidthFloat(logoString.getText().toStdString()), myFont.getHeight());
//    logo.draw(g, logoRect);
//
//    //for debugging
//    g.setColour(Colours::pink);
//    g.drawRect(logoRect);
    
}

void LogoPanel::resized()
{
//    auto newFontScaleFactor = (((float)getBounds().getWidth() - 122.0f)/122.0f) + 1.0f;
    auto newFontScaleFactor = (float)getBounds().getWidth() / 122.0f;
    myFont.setHeight(84.0f * newFontScaleFactor);
    
//    pluginLogo.setBounds(20, 38, 300, 70);
    pluginLogo.setBoundsRelative(0.024f, 0.311f, 0.364f, 0.574f);
    pluginLogo.setFont(myFont);
    
    myFont.setHeight(26.0f * newFontScaleFactor);
    versionLogo.setBounds(681, 57, 125, 30);
    websiteLogo.setBounds(605, 84, 200, 30);
}
