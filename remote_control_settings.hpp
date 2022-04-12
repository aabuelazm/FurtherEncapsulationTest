#ifndef REMOTE_CONTROL_SETTINGS_HPP
#define REMOTE_CONTROL_SETTINGS_HPP

#include "appliance_commanders.hpp"
#include "remote_control.hpp"

using namespace std;

namespace further_encapsulation {
unique_ptr<RemoteControl> remoteSettings(unique_ptr<RemoteControl> remote);
void addAppliance();
void removeAppliance();
void makeMacro();
unique_ptr<RemoteControl> setSlot(unique_ptr<RemoteControl> remote);
} // namespace further_encapsulation

#endif
