#ifndef CONSOLE_REMOTE_HPP
#define CONSOLE_REMOTE_HPP

#include "remote_control_settings.hpp"

using namespace std;

namespace further_encapsulation {
void consoleRemote(unique_ptr<RemoteControl> remote) {
  cout << "Welcome to your Objectech Remote Control" << endl
       << "0: Settings" << endl;
  remote->printData();
  cout << "8: Undo" << endl << "9: Exit" << endl;

  unsigned short input{};
  unsigned short slot{};

  while (true) {
    cout << "Enter Slot Number: ";
    input = getInput();

    if (input == 0)
      cout << "Settings menu coming soon!" << endl;

    else if (input < 8) {
      slot = input;
      cout << "1. On" << endl << "2. Off" << endl;
      input = getInput();

      if (input == 1)
        remote->buttonPushed(slot - 1, Button::On);

      else if (input == 2)
        remote->buttonPushed(slot - 1, Button::Off);

      else
        cout << "Cancelling" << endl;
    }

    else if (input == 8)
      remote->undoButtonPushed();

    else if (input == 9)
      break;

    else
      cout << "Bad Input: Please input a value from 0-9" << endl;
  }
}
} // namespace further_encapsulation

#endif
