/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"
#include "LogoPanel.h"
#include "ControlsPanel.h"
#include "PresetsPanel.h"
#include "HelpPanel.h"
//#include "KnobsPanel.h"
//#include "WaveformPanel.h"
//#include "RhythmPanel.h"

//==============================================================================
/**
*/
class TremoLOLAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    TremoLOLAudioProcessorEditor (TremoLOLAudioProcessor&);
    ~TremoLOLAudioProcessorEditor();

    //==============================================================================
    
    void paint (Graphics&) override;
    void resized() override;
    
    void createLogoString();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TremoLOLAudioProcessor& processor;

    //Image tremoloTop;
    Font myFont;
    
    CustomLookAndFeel customLookAndFeel;
    
    LogoPanel       logoPanel;
    ControlsPanel   controlsPanel;
    PresetsPanel    presetsPanel;
    HelpPanel       helpPanel;
    
        //Label pluginNameLabel;
    //TextEditor logo;
    //TextLayout logo;
    //AttributedString logoString;
//    Slider speedKnob;
//    Slider depthKnob;
    
protected:
    
    float aspectRatio;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremoLOLAudioProcessorEditor)
};
