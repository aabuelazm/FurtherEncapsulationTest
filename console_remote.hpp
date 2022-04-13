#ifndef CONSOLE_REMOTE_HPP
#define CONSOLE_REMOTE_HPP

#include "remote_control_settings.hpp"

using namespace std;

namespace further_encapsulation {
void consoleRemote(unique_ptr<RemoteControl> remote) {
  unsigned short input{};
  unsigned short button{};

  while (true) {
    cout << endl
         << "Welcome to your Objectech Remote Control" << endl
         << "0: Settings" << endl;
    remote->printData();
    cout << "8: Undo" << endl
         << "9: Exit" << endl
         << "Enter Slot Number: " << flush;
    input = getInput();

    if (input == 0)
      remote = remoteSettings(move(remote));

    else if (input < 8) {
      cout << endl
           << "1: On" << endl
           << "2: Off" << endl
           << "Enter Button: " << flush;
      button = getInput();

      if (button == 1)
        remote->buttonPushed(input - 1, Button::On);

      else if (button == 2)
        remote->buttonPushed(input - 1, Button::Off);

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
