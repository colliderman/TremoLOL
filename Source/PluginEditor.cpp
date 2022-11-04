/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

//#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TremoLOLAudioProcessorEditor::TremoLOLAudioProcessorEditor (TremoLOLAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    //tremoloTop = ImageCache::getFromMemory(BinaryData::tremolo_V2_top_png, BinaryData::tremolo_V2_top_pngSize);
    
    
    LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);
    //LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypefaceName("Futura");
    //customLookAndFeel.setDefaultSansSerifTypefaceName("Futura");
    myFont.setHeight(84.0f);
    
    createLogoString();
    logo.createLayout(logoString, 500.0f);
    
//    addAndMakeVisible(pluginNameLabel);
//    pluginNameLabel.setText ("TremoLOL", juce::dontSendNotification);
//    pluginNameLabel.setFont(myFont);
//    //speedKnobLabel.attachToComponent (&speedKnob, false);
//    pluginNameLabel.setColour (juce::Label::textColourId, juce::Colours::white);
//    //pluginNameLabel.setJustificationType (juce::Justification::topLeft);

//    addAndMakeVisible(logo);
//    logo.setReadOnly(true);
//    logo.setCaretVisible(false);
//    logo.setColour(TextEditor::backgroundColourId, Colours::transparentBlack);
//    logo.setColour(TextEditor::outlineColourId, Colours::transparentBlack);

//
    addAndMakeVisible(logoPanel);
    addAndMakeVisible(controlsPanel);
    addAndMakeVisible(presetsPanel);
    addAndMakeVisible(helpPanel);
    
//    addAndMakeVisible(knobsPanel);
//    addAndMakeVisible(waveformPanel);
//    addAndMakeVisible(rhythmPanel);
//    
    //This code for maintaining aspect ratio while resizing taken from here:
//https://forum.juce.com/t/correct-way-to-resize-with-constrained-aspect-ratio/24974/2
    
    aspectRatio = 1.89f;
    setResizable(true, true);
    setResizeLimits(550, 550/aspectRatio, 2400, 2400/aspectRatio);
    //getConstrainer returns a pointer to bounds container object that this window is using
    getConstrainer()->setFixedAspectRatio(aspectRatio);
    
    setSize (824, 824/aspectRatio);

}

TremoLOLAudioProcessorEditor::~TremoLOLAudioProcessorEditor()
{
}

//==============================================================================
void TremoLOLAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colour (0Xff312D2D)); //colour code from Figma UI
    
    //g.drawImageAt(tremoloTop, ((getWidth() - tremoloTop.getWidth())/2), ((getHeight() - tremoloTop.getHeight())/2));
    g.setColour(Colours::blue);
    //g.fillRect(pluginNameLabel.getBounds());
    
    auto area = getLocalBounds();
    logo.draw(g, area.toFloat());
    g.drawRect(area);
}

void TremoLOLAudioProcessorEditor::resized()
{
    //Magic numbers in active function seem to work for now but should be
    //changed to compute a more accurate proportion.
    
//    knobsPanel.setBoundsRelative((area.getWidth()-knobsPanel.getWidth())/2,
//                                 0.280f,
//                                 knobsPanel.getWidth()/area.getWidth(),
//                                 knobsPanel.getHeight()/area.getHeight());
    
    auto newFontScaleFactor = (((float)getBounds().getWidth() - 836.0f)/836.0f) + 1.0f;
    myFont.setHeight(84.0f * newFontScaleFactor);
    
//    logo.clear();
//    logo.setFont(myFont);
//    logo.setColour(TextEditor::textColourId, Colours::white);
//    logo.insertTextAtCaret("Tremo");
//    logo.setColour(TextEditor::textColourId, Colours::orange);
//    logo.insertTextAtCaret("LOL");
//
    //logo.setBoundsRelative(0.024f, 0.087f, 0.360f, 0.190f);
    auto area = getLocalBounds();
    
    logoPanel.setBounds(area.removeFromTop(area.getHeight() * 0.280f));
    controlsPanel.setBounds(area.removeFromTop(area.getHeight() * 0.637f));
    presetsPanel.setBounds(area.removeFromTop(area.getHeight() * 0.421f));
    helpPanel.setBounds(area.removeFromTop(area.getHeight())); //could be just area?
    
//    knobsPanel.setBoundsRelative(0.252f,
//                                0.280f,
//                                0.495f,
//                                0.459f);
    
//    waveformPanel.setBoundsRelative(0.024f, 0.280f, 0.204f, 0.459f);
    
//    rhythmPanel.setBoundsRelative(0.772f, 0.280f, 0.204f, 0.459f);
//  ==============================================================================
//    DBG("My font style is " + myFont.getTypefaceStyle());
//    DBG("My font type is " + myFont.getTypefaceName());

}

void TremoLOLAudioProcessorEditor::createLogoString()
{
    //AttributedString logoString;
//    logoString.append("Tremo", Colours::white);
//    logoString.append("LOL", Colours::orange);
    logoString.append("Tremo", myFont, Colours::white);
    logoString.append("LOL", myFont, Colours::orange);
}
