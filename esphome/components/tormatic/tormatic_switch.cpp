#include "tormatic_switch.h"

#ifdef USE_SWITCH

#include "esphome/core/log.h"

namespace esphome::tormatic {

static const char *const TAG = "tormatic.switch";

// Restore mode is never applied: restoring would send a light command on boot.
void TormaticSwitch::setup() {
  this->parent_->add_on_light_state_callback([this](bool state) { this->publish_state(state); });
}

void TormaticSwitch::dump_config() { LOG_SWITCH("", "Tormatic Light Switch", this); }

// Don't publish here: the drive may ignore the command, and the echo doesn't
// confirm it. The next light status reply publishes the actual state.
void TormaticSwitch::write_state(bool state) { this->parent_->send_light_command(state); }

}  // namespace esphome::tormatic

#endif  // USE_SWITCH
