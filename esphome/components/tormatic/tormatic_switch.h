#pragma once

#include "esphome/core/defines.h"
#ifdef USE_SWITCH

#include "esphome/components/switch/switch.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "tormatic_cover.h"

namespace esphome::tormatic {

// Controls the drive's light. The state is only ever taken from the drive's
// status replies, never assumed from a command.
class TormaticSwitch : public switch_::Switch, public Component, public Parented<Tormatic> {
 public:
  void setup() override;
  void dump_config() override;

 protected:
  void write_state(bool state) override;
};

}  // namespace esphome::tormatic

#endif  // USE_SWITCH
