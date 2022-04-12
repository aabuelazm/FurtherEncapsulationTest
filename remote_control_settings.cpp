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

unique_ptr<RemoteControl> remoteSettings(unique_ptr<RemoteControl> remote) {
  unsigned short input;

  cout << "Settings Menu" << endl
       << "1: Add Appliance" << endl
       << "2: Remove Appliance" << endl
       << "3: Make Macro" << endl
       << "4: Set Slot" << endl
       << "5: Exit Settings Menu";

  while (true) {
    cout << "Input Command: ";
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

unsigned short further_encapsulation::getInput() {
  unsigned short input{};
  cin >> input;

  if (cin.fail())
    throw domain_error("Unknown Input! Crashing for Safety");

  return input;
}
