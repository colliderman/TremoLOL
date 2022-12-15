/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TremoLOLAudioProcessor::TremoLOLAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
        parameters (*this, nullptr, Identifier ("APVTS"),
                    {
            std::make_unique<AudioParameterFloat> (ParameterID{"depth", 1},
                                                               "Depth",
                                                               0.1f,
                                                               1.0f,
                                                               0.5f),
            std::make_unique<AudioParameterFloat>(ParameterID{"speed", 1},
                                                              "Speed",
                                                              0.1f,
                                                              1.0f,
                                                              0.2f)
        })
{
    depthParameter = parameters.getRawParameterValue ("depth");
    speedParameter = parameters.getRawParameterValue ("speed");
}

TremoLOLAudioProcessor::~TremoLOLAudioProcessor()
{
}

//==============================================================================
const String TremoLOLAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TremoLOLAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TremoLOLAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TremoLOLAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TremoLOLAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TremoLOLAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TremoLOLAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TremoLOLAudioProcessor::setCurrentProgram (int index)
{
}

const String TremoLOLAudioProcessor::getProgramName (int index)
{
    return {};
}

void TremoLOLAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TremoLOLAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void TremoLOLAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TremoLOLAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TremoLOLAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        // ..do something to the data...
//        auto curSampleRate = getSampleRate();
//        //auto rate = speedParameter->AudioProcessorParameter::getValue();
//        //auto depth = depthParameter->AudioProcessorParameter::getValue();
//        float rate = 0.25f;
//        float depth = 0.5f;
//        
//        //initialize oscillator state
//        float phase = 0.0f;
//        float phaseIncrement = rate / (float)curSampleRate;
//        
//        // apply tremolo effect to each sample
//        for (int i = 0; i < buffer.getNumSamples(); i++)
//        {
//            // calculate tremolo amount based on oscillator state
//            float tremoloAmount = (1.0f + depth * std::sin(phase)) / 2.0f;
//            
//            // apply tremolo amount to sample
//            channelData[i] *= tremoloAmount;
//            
//            // increment oscillator phase
//            phase += phaseIncrement;
//        }
    }
    /*Tremolo algorithm from ChatGPT!
     void tremolo(float* samples, int numSamples, float depth, float rate) {
       // initialize oscillator state
       float phase = 0.0f;
       float phaseIncrement = rate / 44100.0f;

       // apply tremolo effect to each sample
       for (int i = 0; i < numSamples; i++) {
         // calculate tremolo amount based on oscillator state
         float tremoloAmount = (1.0f + depth * std::sin(phase)) / 2.0f;

         // apply tremolo amount to sample
         samples[i] *= tremoloAmount;

         // increment oscillator phase
         phase += phaseIncrement;
       }
     }
     
     //triangle wave function!
     #include <math.h>

     // generate a triangle wave with a range of 0 to 1
     float triangleWave(float phase) {
       // scale the sine wave from -1 to 1 to 0 to 1
       float sineWave = (sin(phase) + 1.0f) / 2.0f;

       // offset the sine wave to create a triangle wave
       return sineWave < 0.5f ? 2.0f * sineWave : 2.0f * (1.0f - sineWave);
     }

    //tremolo function from above, but now uses triangle wave function
     void tremolo(float* samples, int numSamples, float depth, float rate) {
       // initialize oscillator state
       float phase = 0.0f;
       float phaseIncrement = rate / 44100.0f;

       // apply tremolo effect to each sample
       for (int i = 0; i < numSamples; i++) {
         // calculate tremolo amount based on oscillator state
         float tremoloAmount = (1.0f + depth * triangleWave(phase)) / 2.0f;

         // apply tremolo amount to sample
         samples[i] *= tremoloAmount;

         // increment oscillator phase
         phase += phaseIncrement;
       }
     }

     //And here's the square wave...
     // generate a square wave with a range of 0 to 1
     float squareWave(float phase) {
       return sin(phase) > 0 ? 1.0f : 0.0f;
     }

     void tremolo(float* samples, int numSamples, float depth, float rate) {
       // initialize oscillator state
       float phase = 0.0f;
       float phaseIncrement = rate / 44100.0f;

       // apply tremolo effect to each sample
       for (int i = 0; i < numSamples; i++) {
         // calculate tremolo amount based on oscillator state
         float tremoloAmount = (1.0f + depth * squareWave(phase)) / 2.0f;

         // apply tremolo amount to sample
         samples[i] *= tremoloAmount;

         // increment oscillator phase
         phase += phaseIncrement;
       }
     }

*/
}

//==============================================================================
bool TremoLOLAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TremoLOLAudioProcessor::createEditor()
{
    return new TremoLOLAudioProcessorEditor (*this, parameters);
    //return new GenericAudioProcessorEditor (*this);
}

//==============================================================================
void TremoLOLAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TremoLOLAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TremoLOLAudioProcessor();
}

