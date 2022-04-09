#include "appliance_commanders.hpp"
#include "remote_control.hpp"

using namespace std;
using namespace further_encapsulation;

int main() {
  auto remote = make_unique<RemoteControl>();

  // Living Room Appliances
  auto lr_light = make_shared<LightCommander>();
  auto lr_stereo = make_shared<StereoCommander>();
  auto lr_tv = make_shared<TVCommander>();

  auto lr_party = make_shared<MacroCommander>();
  lr_party->commanders.push_back(lr_light);
  lr_party->commanders.push_back(lr_stereo);

  // Garage Applianecs
  auto g_light = make_shared<LightCommander>();
  auto g_door = make_shared<GarageDoorCommander>();

  auto garage = make_shared<MacroCommander>();
  garage->commanders.push_back(g_light);
  garage->commanders.push_back(g_door);

  // Outdoor Appliances
  auto security = make_shared<SecurityControlCommander>();
  auto hottub = make_shared<HottubCommander>();

  // Garden Appliances
  auto y_faucet = make_shared<FaucetControlCommander>();
  auto y_sprinkler = make_shared<SprinklerCommander>();
  auto y_light = make_shared<GardenLightCommander>();

  auto water = make_shared<MacroCommander>();
  water->commanders.push_back(y_faucet);
  water->commanders.push_back(y_sprinkler);
}
