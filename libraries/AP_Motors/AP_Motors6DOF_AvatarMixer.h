#pragma once

#include "AP_Motors6DOF_Mixer.h"

namespace AP_Motors6DOF_Mixer {

class AvatarMixer : public Interface {
public:
    void setup_motors(::AP_Motors6DOF* backend) override;
    void mix(const MixerInputs& inputs, MixerState& state, MixerOutputs& outputs) override;
};

} // namespace AP_Motors6DOF_Mixer
