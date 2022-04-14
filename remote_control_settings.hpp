#ifndef REMOTE_CONTROL_SETTINGS_HPP
#define REMOTE_CONTROL_SETTINGS_HPP

#include "appliance_commanders.hpp"
#include "remote_control.hpp"

using namespace std;

// A way to handle editing our remote control. You have a bunch of saved
// appliances you set aside that you can set to slots using shared shared
// pointers. Useage of smart pointers means we do not have to worry about memory
// leaking.
namespace further_encapsulation {
unique_ptr<RemoteControl> remoteSettings(unique_ptr<RemoteControl> remote);
void addAppliance();
void removeAppliance();
void makeMacro();
unique_ptr<RemoteControl> setSlot(unique_ptr<RemoteControl> remote);

unsigned short getInput();
string getNameInput();
} // namespace further_encapsulation

#endif
