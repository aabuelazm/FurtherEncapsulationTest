#ifndef REMOTE_CONTROL_HPP
#define REMOTE_CONTROL_HPP

#include "commander_class.hpp"
#include <concepts>
#include <utility>

namespace further_encapsulation {

class RemoteControl {
private:
  Commander *slots[7]{};
  std::pair<Commander *, Button> last_command{};

public:
  void setCommander(unsigned short int slot, Commander *Appliance) {
    slots[slot] = Appliance;
  }

  void buttonPushed(unsigned short int slot, Button button_pushed) {
    auto *appliance = slots[slot];
    switch (button_pushed) {
      case Button::On :
        appliance->on();
        break;
      case Button::Off :
        appliance->off();
        break;
      }
    last_command = std::make_pair(appliance, button_pushed);
  }

  void undoButtonPushed() {
    last_command.first->undo(last_command.second);
    if (last_command.second == Button::On)
      last_command.second = Button::Off;
    else
      last_command.second = Button::On;
  }
};
} // namespace further_encapsulation

#endif
