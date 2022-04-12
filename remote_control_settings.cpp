#include "remote_control_settings.hpp"

using namespace std;
using namespace further_encapsulation;

static vector<shared_ptr<RemoteControl>> saved_appliances{};

static void printSavedAppliances() {
  auto len = saved_appliances.size();
  cout << "Your Appliances:" << endl;

  for (size_t i = 1; i <= len; i++) {
    cout << i << ": ";
    saved_appliances[i - 1]->printData();
  }
}

unique_ptr<RemoteControl> remoteSettings(unique_ptr<RemoteControl> remote) {
  unsigned short input{};

  cout << "Settings Menu" << endl
       << "1: Add Appliance" << endl
       << "2: Remove Appliance" << endl
       << "3: Make Macro" << endl
       << "4: Set Slot" << endl
       << "5: Exit Settings Menu";

  while (true) {
    cout << "Input Command: ";
    cin >> input;

    if (cin.fail()) {
      throw domain_error("Unknown Input! Crashing for Safety!");
    }

    else if (input == 1)
      addAppliance();

    else if (input == 2)
      removeAppliance();

    else if (input == 3)
      makeMacro();

    else if (input == 4)
      remote = setSlot(move(remote));

    else if (input == 5)
      break;

    else
      cout << "Bad Input: Please input a value from 1-4" << endl;
  }

  return remote;
}

void addAppliance() {
  printSavedAppliances();
  
}
