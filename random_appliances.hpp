#ifndef RANDOM_APPLIANCES_HPP
#define RANDOM_APPLIANCES_HPP

#include <iostream>

// This is a header file with the example appliances for the home
// automation/Command pattern chapter of Head First Design Patterns
namespace further_encapsulation {
class ApplianceControl {
public:
  void on();
  void off();
};

class Stereo {
public:
  void on();
  void off();
  void setCD();
  void setDVD();
  void setRadio();
  void setVolume(unsigned short int volume);
};

class FaucetControl {
public:
  void openValve();
  void closeValve();
};

class Hottub {
public:
  void circulate();
  void jetsOn();
  void jetsOff();
  void setTemperature(float temperature);
};

class Thermostat {
public:
  void setTemperature(float temperature);
};

class SecurityControl {
public:
  void arm();
  void disarm();
};

class CeilingLight {
public:
  void on();
  void off();
  void dim();
};

class OutdoorLight {
public:
  void on();
  void off();
};

class TV {
public:
  void on();
  void off();
  void setInputChannel(unsigned int channel);
  void setVolume(unsigned int volume);
};

class CeilingFan {
private:
  unsigned int speed{};

public:
  void high();
  void medium();
  void low();
  void off();
  unsigned int getSpeed();
};

class GardenLight {
private:
  unsigned short int dusk_time{};
  unsigned short int dawn_time{};

public:
  void setDuskTime(unsigned short int d_time);
  void setDawnTime(unsigned short int d_time);
  void manualOn();
  void manualOff();
};

class GarageDoor {
public:
  void up();
  void down();
  void stop();
  void lightOn();
  void lightOff();
};

class Sprinkler {
public:
  void waterOn();
  void waterOff();
};

class Light {
public:
  void on();
  void off();
};
} // namespace further_encapsulation

#endif
