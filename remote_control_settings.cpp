#include "remote_control_settings.hpp"

using namespace std;
using namespace further_encapsulation;

static vector<shared_ptr<Commander>> saved_appliances{};

static void printSavedAppliances() {
  auto len = saved_appliances.size();
  cout << "Your Appliances:" << endl;

  for (size_t i = 1; i <= len; i++) {
    cout << i << ": ";
    saved_appliances[i - 1]->printData();
  }
}

unique_ptr<RemoteControl>
further_encapsulation::remoteSettings(unique_ptr<RemoteControl> remote) {
  unsigned short input;

  while (true) {
    cout << endl
         << "Settings Menu" << endl
         << "1: Add Appliance" << endl
         << "2: Remove Appliance" << endl
         << "3: Make Macro" << endl
         << "4: Set Slot" << endl
         << "5: Exit Settings Menu" << endl
         << "Input Command: ";
    input = getInput();

    if (input == 1)
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

void further_encapsulation::addAppliance() {
  printSavedAppliances();
  cout << endl
       << "To add new appliance, input corresponding number" << endl
       << "1: ApplianceControl" << endl
       << "2: Stereo" << endl
       << "3: FaucetControl" << endl
       << "4: Hottub" << endl
       << "5: Thermostat" << endl
       << "6: SecurityControl" << endl
       << "7: CeilingLight" << endl
       << "8: OutdoorLight" << endl
       << "9: TV" << endl
       << "10: CeilingFan" << endl
       << "11: GardenLight" << endl
       << "12: GarageDoor" << endl
       << "13: Sprinkler" << endl
       << "14: Light" << endl
       << "Enter Appliance Number: ";

  unsigned short input = getInput();
  if (input == 0)
    cout << "Cancelling" << endl;
  else if (input == 1)
    saved_appliances.push_back(make_shared<ApplianceControlCommander>());
  else if (input == 2)
    saved_appliances.push_back(make_shared<StereoCommander>());
  else if (input == 3)
    saved_appliances.push_back(make_shared<FaucetControlCommander>());
  else if (input == 4)
    saved_appliances.push_back(make_shared<HottubCommander>());
  else if (input == 5)
    saved_appliances.push_back(make_shared<ThermostatCommander>());
  else if (input == 6)
    saved_appliances.push_back(make_shared<SecurityControlCommander>());
  else if (input == 7)
    saved_appliances.push_back(make_shared<CeilingLightCommander>());
  else if (input == 8)
    saved_appliances.push_back(make_shared<OutdoorLightCommander>());
  else if (input == 9)
    saved_appliances.push_back(make_shared<TVCommander>());
  else if (input == 10)
    saved_appliances.push_back(make_shared<CeilingFanCommander>());
  else if (input == 11)
    saved_appliances.push_back(make_shared<GardenLightCommander>());
  else if (input == 12)
    saved_appliances.push_back(make_shared<GarageDoorCommander>());
  else if (input == 13)
    saved_appliances.push_back(make_shared<SprinklerCommander>());
  else if (input == 14)
    saved_appliances.push_back(make_shared<LightCommander>());
  else
    cout << "Bad Input: Please input a value from 1-14" << endl;
}

void further_encapsulation::removeAppliance() {
  cout << endl << "Which appliance would you like to remove?" << endl;
  printSavedAppliances();

  cout << "Enter Appliance Number: ";
  unsigned short input = getInput();
  if (input == 0 || input > saved_appliances.size())
    cout << "Cancelling!" << endl;
  else
    saved_appliances.erase(saved_appliances.begin() + input - 1);
}

void further_encapsulation::makeMacro() {
  cout << endl
       << "Make new macro by adding appliances. This allows control of "
          "multiple appliances using one button"
       << endl
       << "0: End Macro" << endl;
  printSavedAppliances();
  auto new_macro = make_shared<MacroCommander>();
  unsigned short input;
  auto len = saved_appliances.size();

  while (true) {
    cout << "Input Appliance Number: ";
    input = getInput();

    if (input == 0)
      break;
    else if (input > len)
      cout << "Bad Inut: Please input number between 0-" << len << endl;
    else
      new_macro->commanders.push_back(saved_appliances[input - 1]);
  }

  saved_appliances.push_back(new_macro);
}

unique_ptr<RemoteControl>
further_encapsulation::setSlot(unique_ptr<RemoteControl> remote) {
  cout << endl
       << "Which Appliance or Macro do you want to add to your remote?" << endl;
  printSavedAppliances();
  cout << "Enter Appliance Number: ";
  unsigned short appliance_number = getInput();
  if (appliance_number == 0 || appliance_number > saved_appliances.size()) {
    cout << "Bad Input: Please input number between 1-7" << endl;
    return remote;
  }

  cout << endl << "Which slot do you want to overwrite?" << endl;
  remote->printData();
  cout << "Enter Slot Number: ";
  unsigned short slot_number = getInput();
  if (slot_number == 0 || slot_number > 7)
    cout << "Bad Input: Please input number between 1-7" << endl;
  else
    remote->setCommander(slot_number - 1,
                         saved_appliances[appliance_number - 1]);

  return remote;
}

unsigned short further_encapsulation::getInput() {
  unsigned short input{};
  cin >> input;

  if (cin.fail())
    throw domain_error("Unknown Input! Crashing for Safety");

  return input;
}
