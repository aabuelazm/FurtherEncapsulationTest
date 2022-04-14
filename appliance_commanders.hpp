#ifndef APPLIANCE_COMMANDERS_HPP
#define APPLIANCE_COMMANDERS_HPP

#include "commander_class.hpp"
#include "random_appliances.hpp"

// A header file that creates subclasses that act as our encapsulation of the
// many different random appliances, think of them as drivers or whatever (with
// ApplianceControl being our generic driver).
namespace further_encapsulation {
class ApplianceControlCommander : virtual public Commander {
private:
  ApplianceControl appliance{};

public:
  void on();
  void off();
};

class StereoCommander : virtual public Commander {
private:
  Stereo stereo{};

public:
  void on();
  void off();
};

class FaucetControlCommander : virtual public Commander {
private:
  FaucetControl faucet{};

public:
  void on();
  void off();
};

class HottubCommander : virtual public Commander {
private:
  Hottub hottub{};

public:
  void on();
  void off();
};

class ThermostatCommander : virtual public Commander {
private:
  Thermostat thermostat{};

public:
  void on();
  void off();
};

class SecurityControlCommander : virtual public Commander {
private:
  SecurityControl security{};

public:
  void on();
  void off();
};

class CeilingLightCommander : virtual public Commander {
private:
  CeilingLight c_light{};

public:
  void on();
  void off();
};

class OutdoorLightCommander : virtual public Commander {
private:
  OutdoorLight o_light{};

public:
  void on();
  void off();
};

class TVCommander : virtual public Commander {
private:
  TV tv{};

public:
  void on();
  void off();
};

class CeilingFanCommander : virtual public Commander {
private:
  CeilingFan c_fan{};
  unsigned int last_speed{};

public:
  void on();
  void off();
  void undo(Button last_command);
};

class GardenLightCommander : virtual public Commander {
private:
  GardenLight g_light{};

public:
  void on();
  void off();
};

class GarageDoorCommander : virtual public Commander {
private:
  GarageDoor g_door{};

public:
  void on();
  void off();
};

class SprinklerCommander : virtual public Commander {
private:
  Sprinkler sprinkler{};

public:
  void on();
  void off();
};

class LightCommander : virtual public Commander {
private:
  Light light{};

public:
  void on();
  void off();
};
} // namespace further_encapsulation

#endif
