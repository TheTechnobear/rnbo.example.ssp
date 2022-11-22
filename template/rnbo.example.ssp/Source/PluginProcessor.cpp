#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "ssp/EditorHost.h"

PluginProcessor::PluginProcessor() : RnboPluginProcessor() {

}


AudioProcessorEditor *PluginProcessor::createEditor() {
    return new ssp::EditorHost(this, new PluginEditor(*this, params_.rnboParams_.size() / 16));
}

AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}
