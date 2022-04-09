#ifndef REMOTE_CONTROL_HPP
#define REMOTE_CONTROL_HPP

#include "commander_class.hpp"
#include <utility>

namespace further_encapsulation {

class RemoteControl {
private:
  std::shared_ptr<Commander> slots[7]{};
  std::pair<std::shared_ptr<Commander>, Button> last_command{};

public:
  void setCommander(unsigned short int slot,
                    std::shared_ptr<Commander> Appliance) {
    slots[slot] = Appliance;
  }

  void buttonPushed(unsigned short int slot, Button button_pushed) {
    auto appliance = slots[slot];
    if (bool(button_pushed))
      appliance->on();
    else
      appliance->off();
    last_command = std::make_pair(appliance, button_pushed);
  }

  void undoButtonPushed() {
    last_command.first->undo(last_command.second);
    if (bool(last_command.second))
      last_command.second = Button::Off;
    else
      last_command.second = Button::On;
  }
};
} // namespace further_encapsulation

#endif
