#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "RnboBasePluginProcessor.h"
#include "ssp/MultiBarEditor.h"

class RnboBasePluginEditor : public ssp::MultiBarEditor {
public:
    explicit RnboBasePluginEditor(RnboBasePluginProcessor &, unsigned maxviews);

    ~RnboBasePluginEditor() {}

    void drawView(Graphics &) override;
    void resized() override;
protected:
    using base_type = ssp::MultiBarEditor;

private:
    juce::Colour clrs_[4];
    RnboBasePluginProcessor &processor_;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RnboBasePluginEditor)
};

