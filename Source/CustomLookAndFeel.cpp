/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 3 Jan 2020 11:39:59pm
    Author:  Cody Gilchrist

  ==============================================================================
*/

#include "CustomLookAndFeel.h"

//==============================================================================

CustomLookAndFeel::CustomLookAndFeel()
{
    Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::Futura_ttc, BinaryData::Futura_ttcSize);
    setDefaultSansSerifTypeface (tface);
    //setDefaultSansSerifTypefaceName("Futura");
    //mouseEnter = false;
}

void CustomLookAndFeel::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                       const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    
    auto radius = (float) jmin (width / 2, height / 2) - 2.0f;
    auto centerX = (float) x + (float) width * 0.5f;
    auto centerY = (float) y + (float) height * 0.5f;
    auto rx = centerX - radius;
    auto ry = centerY - radius;
    auto rw = radius * 2.0f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    
    //fill
    g.setColour(Colour (0xff312D2D));
    g.fillEllipse(rx, ry, rw, rw);
    
    Path p;
    auto pointerLength = radius * 0.68f;
    //rw * 0.06f is because I want the indicator to be the equivalent of 6 pixels
    //wide relative to default knob size, which is 100 pixels circumfrence.
    //ie: 100 x 0.06 = 6
    auto pointerThickness = rw * 0.06f;
    p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
    p.applyTransform(AffineTransform::rotation (angle).translated(centerX, centerY));
    
    //pointer
    g.setColour(Colour (0xffD9D9D9));
    g.fillPath (p);
    
    //outline
    if (slider.isMouseOverOrDragging()) {
        g.setColour(Colour (0xffEACCA8));
        g.drawEllipse(rx, ry, rw, rw, rw * 0.02f);
    } else {
        g.setColour(Colour (0xffDDA666));
        g.drawEllipse(rx, ry, rw, rw, rw * 0.02f);
    }
//    //knob stroke/outline
//    g.setColour(Colour (0xffDFB98C));
//    //rw * 0.02f is because I want the outline to be the equivalent of 2 pixels
//    //wide relative to default knob size, which is 100 pixels circumfrence.
//    //ie: 100 x 0.02 = 2
//    g.drawEllipse(rx, ry, rw, rw, rw * 0.02f);
    
}

Label* CustomLookAndFeel::createSliderTextBox(Slider &slider)
{
    return createSliderTextBox(slider);
}
