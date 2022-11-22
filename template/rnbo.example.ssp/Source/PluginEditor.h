#pragma once

#include <rnbo/RnboPluginEditor.h>


class PluginEditor : public RnboPluginEditor {
public:
    explicit PluginEditor(RnboPluginProcessor & p, unsigned mv) : RnboPluginEditor(p, mv) {}
    ~PluginEditor() override = default;
};
