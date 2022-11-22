#pragma once

#include <rnbo/RnboPluginProcessor.h>

class PluginProcessor : public RnboPluginProcessor {
public:
    explicit PluginProcessor();
    ~PluginProcessor() = default;

    AudioProcessorEditor *createEditor() override;
};
