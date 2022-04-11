#include "appliance_commanders.hpp"
#include "remote_control.hpp"

using namespace std;
using namespace further_encapsulation;

int main() {
  auto remote = make_unique<RemoteControl>();

  // Living Room Appliances
  auto lr_party = make_shared<MacroCommander>();
  lr_party->commanders.push_back(make_shared<CeilingLightCommander>());
  lr_party->commanders.push_back(make_shared<StereoCommander>());

  remote->setCommander(0, lr_party);
  remote->setCommander(1, make_shared<TVCommander>());

  // Garage Applianecs
  auto garage = make_shared<MacroCommander>();
  garage->commanders.push_back(make_shared<LightCommander>());
  garage->commanders.push_back(make_shared<GarageDoorCommander>());

  remote->setCommander(2, garage);

  // Outdoor Appliances
  remote->setCommander(3, make_shared<SecurityControlCommander>());
  remote->setCommander(4, make_shared<HottubCommander>());

  // Garden Appliances
  auto water = make_shared<MacroCommander>();
  water->commanders.push_back(make_shared<FaucetControlCommander>());
  water->commanders.push_back(make_shared<SprinklerCommander>());

  remote->setCommander(5, water);
  remote->setCommander(6, make_shared<GardenLightCommander>());

  unsigned short input{};
  unsigned short slot{};

  cout << "Welcome to your Objectech Remote Control" << endl
       << "0: Settings" << endl;
  remote->printData();
  cout << "8: Undo" << endl << "9: Exit" << endl;

  while (true) {
    cout << "Enter Slot Number: ";
    cin >> input;

    if (cin.fail()) {
      remote.reset();
      throw domain_error("Unknown Input! Crashing for Safety");
    }

    else if (input == 0)
      cout << "Settings menu coming soon!" << endl;

    else if (input < 8) {
      slot = input;
      cout << "1. On" << endl << "2. Off" << endl;
      cin >> input;

      if (cin.fail()) {
        remote.reset();
        throw domain_error("Unknown Input! Crashing for Safety");
      }

      else if (input == 1)
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
      cout << "Unknown Input: Please input a value from 0-9" << endl;
  }

  cout << "Thank You and Good Bye!!" << endl;
  remote.reset();
}
