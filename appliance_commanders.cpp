#include "appliance_commanders.hpp"

using namespace std;
using namespace further_encapsulation;

void ApplianceControlCommander::on() { this->appliance.on(); }
void ApplianceControlCommander::off() { this->appliance.off(); }
void ApplianceControlCommander::undo(Button last_command) {
  if (bool(last_command))
    this->off();
  else
    this->on();
}

void StereoCommander::on() {
  this->stereo.on();
  this->stereo.setCD();
  this->stereo.setVolume(11);
}
void StereoCommander::off() { this->stereo.off(); }
void StereoCommander::undo(Button last_command) {
  if (bool(last_command))
    this->off();
  else
    this->on();
}

void FaucetControlCommander::on() { this->faucet.openValve(); }
void FaucetControlCommander::off() { this->faucet.closeValve(); }
void FaucetControlCommander::undo(Button last_command) {
  if (bool(last_command))
    this->off();
  else
    this->on();
}

void HottubCommander::on() {
  this->hottub.circulate();
  this->hottub.setTemperature(40.0);
  this->hottub.jetsOn();
}
void HottubCommander::off() {
  this->hottub.setTemperature(-50.0);
  this->hottub.jetsOff();
}
void HottubCommander::undo(Button last_command) {
  if (bool(last_command))
    this->off();
  else
    this->on();
}

void SecurityControlCommander::on() { this->security.arm(); }
void SecurityControlCommander::off() { this->security.disarm(); }
void SecurityControlCommander::undo(Button last_command) {
  if (bool(last_command))
    this->off();
  else
    this->on();
}

void CeilingLightCommander::on() { this->c_light.on(); }
void CeilingLightCommander::off() { this->c_light.off(); }
void CeilingLightCommander::undo(Button last_command) {
  if (bool(last_command))
    this->off();
  else
    this->on();
}
