#ifndef CONSOLE_REMOTE_HPP
#define CONSOLE_REMOTE_HPP

#include "remote_control.hpp"

namespace further_encapsulation {
void consoleRemote(std::unique_ptr<RemoteControl> remote) {
  std::cout << "Welcome to your Objectech Remote Control" << std::endl
            << "0: Settings" << std::endl;
  remote->printData();
  std::cout << "8: Undo" << std::endl << "9: Exit" << std::endl;

  unsigned short input{};
  unsigned short slot{};

  while (true) {
    std::cout << "Enter Slot Number: ";
    std::cin >> input;

    if (std::cin.fail()) {
      remote.reset();
      throw std::domain_error("Unknown Input! Crashing for Safety");
    }

    else if (input == 0)
      std::cout << "Settings menu coming soon!" << std::endl;

    else if (input < 8) {
      slot = input;
      std::cout << "1. On" << std::endl << "2. Off" << std::endl;
      std::cin >> input;

      if (std::cin.fail()) {
        remote.reset();
        throw std::domain_error("Unknown Input! Crashing for Safety");
      }

      else if (input == 1)
        remote->buttonPushed(slot - 1, Button::On);

      else if (input == 2)
        remote->buttonPushed(slot - 1, Button::Off);

      else
        std::cout << "Cancelling" << std::endl;
    }

    else if (input == 8)
      remote->undoButtonPushed();

    else if (input == 9)
      break;

    else
      std::cout << "Bad Input: Please input a value from 0-9" << std::endl;
  }

  remote.reset();
}
} // namespace further_encapsulation

#endif
