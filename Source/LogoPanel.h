/*
  ==============================================================================

    LogoPanel.h
    Created: 3 Nov 2022 11:03:24am
    Author:  Cody Gilchrist

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomLookAndFeel.h"

//==============================================================================
/*
*/
class Logo : public Component
{
public:
    Logo();
    ~Logo();
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void setText (const String& string, Font& fontToUse, Colour colour);
    
    void createLayout();
    
    void setFont (Font& fontToUse);
    
private:
    
    //float fontHeight;
    Font font;
    AttributedString attString;
    TextLayout textLayout;
    //Colour colour;
    
};

class LogoPanel  : public juce::Component
{
public:
    LogoPanel();
    ~LogoPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    Logo pluginLogo;
    Logo versionLogo;
    Logo websiteLogo;
    
    Font myFont;
    CustomLookAndFeel customLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LogoPanel)
};


