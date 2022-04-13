#ifndef REMOTE_CONTROL_HPP
#define REMOTE_CONTROL_HPP

#include "commander_class.hpp"
#include <utility>

using namespace std;

// This header includes all the functions that our remote control has, 7 slots
// with an On and Off button each, a single undo button, and a way to change
// slots/tell client what options it has. This code can be adapted to fit
// different methods of changing slots, be it through a terminal or some other
// way you would want your remote to be updated.
namespace further_encapsulation {
class RemoteControl {
private:
  shared_ptr<Commander> slots[7]{};
  pair<shared_ptr<Commander>, Button> last_command{};

public:
  RemoteControl() {
    for (int i = 0; i < 7; i++)
      slots[i] = make_shared<Commander>();

    last_command.first = slots[0];
  }

  ~RemoteControl() {}

  void setCommander(unsigned short int slot, shared_ptr<Commander> Appliance) {
    slots[slot] = Appliance;
  }

  void buttonPushed(unsigned short int slot, Button button_pushed) {
    auto appliance = slots[slot];
    if (bool(button_pushed))
      appliance->on();
    else
      appliance->off();
    last_command = make_pair(appliance, button_pushed);
  }

  void undoButtonPushed() {
    last_command.first->undo(last_command.second);
    if (bool(last_command.second))
      last_command.second = Button::Off;
    else
      last_command.second = Button::On;
  }

  void printData() {
    for (unsigned short int i = 1; i <= 7; i++) {
      cout << i << ": ";
      slots[i - 1]->printData();
    }
  }
};
} // namespace further_encapsulation

#endif
