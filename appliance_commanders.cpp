#include "appliance_commanders.hpp"

using namespace std;
using namespace further_encapsulation;

// Implementation of the Commanders from appliance_commanders.hpp
void ApplianceControlCommander::on() { this->appliance.on(); }
void ApplianceControlCommander::off() { this->appliance.off(); }

void StereoCommander::on() {
  this->stereo.on();
  this->stereo.setCD();
  this->stereo.setVolume(11);
}
void StereoCommander::off() { this->stereo.off(); }

void FaucetControlCommander::on() { this->faucet.openValve(); }
void FaucetControlCommander::off() { this->faucet.closeValve(); }

void HottubCommander::on() {
  this->hottub.circulate();
  this->hottub.setTemperature(40.0);
  this->hottub.jetsOn();
}
void HottubCommander::off() {
  this->hottub.setTemperature(-50.0);
  this->hottub.jetsOff();
}

void ThermostatCommander::on() { this->thermostat.setTemperature(24.0); }
void ThermostatCommander::off() { this->thermostat.setTemperature(0); }

void SecurityControlCommander::on() { this->security.arm(); }
void SecurityControlCommander::off() { this->security.disarm(); }

void CeilingLightCommander::on() { this->c_light.on(); }
void CeilingLightCommander::off() { this->c_light.off(); }

void OutdoorLightCommander::on() { this->o_light.on(); }
void OutdoorLightCommander::off() { this->o_light.off(); }

void TVCommander::on() {
  this->tv.on();
  this->tv.setInputChannel(69);
  this->tv.setVolume(42);
}
void TVCommander::off() { this->tv.off(); }

void CeilingFanCommander::on() {
  this->last_speed = this->c_fan.getSpeed();
  this->c_fan.medium();
}
void CeilingFanCommander::off() {
  this->last_speed = this->c_fan.getSpeed();
  this->c_fan.off();
}
void CeilingFanCommander::undo(Button last_command) {
  if (this->last_speed == 420)
    this->c_fan.high();
  else if (this->last_speed == 210)
    this->c_fan.medium();
  else if (this->last_speed == 105)
    this->c_fan.low();
  else
    this->c_fan.off();
  this->last_speed = this->c_fan.getSpeed();
}

void GardenLightCommander::on() { this->g_light.manualOn(); }
void GardenLightCommander::off() { this->g_light.manualOff(); }

void GarageDoorCommander::on() { this->g_door.up(); }
void GarageDoorCommander::off() { this->g_door.down(); }

void SprinklerCommander::on() { this->sprinkler.waterOn(); }
void SprinklerCommander::off() { this->sprinkler.waterOff(); }

void LightCommander::on() { this->light.on(); }
void LightCommander::off() { this->light.off(); }
