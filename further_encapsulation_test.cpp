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

  remote->buttonPushed(1, Button::On);
  remote->undoButtonPushed();

  remote->buttonPushed(0, Button::On);
  remote->buttonPushed(4, Button::On);

  remote->buttonPushed(2, Button::On);
  remote->buttonPushed(0, Button::Off);
  remote->buttonPushed(5, Button::On);
  remote->buttonPushed(2, Button::Off);

  remote->buttonPushed(4, Button::Off);
  remote->buttonPushed(3, Button::On);

  remote.release();
}
