#ifndef RANDOM_APPLIANCES_HPP
#define RANDOM_APPLIANCES_HPP

#include <iostream>

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
  void setVolume(unsigned int volume);
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
  void setTemperature();
};

class Thermostat {
public:
  void setTemperature();
};

class SecurityControl {
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
  void setInputChannel();
  void setVolume();
};

class CeilingFan {
private:
  unsigned int speed;

public:
  void high();
  void medium();
  void low();
  void off();
  unsigned int getSpeed();
};

class GardenLight {
private:
  unsigned short int dusk_time;
  unsigned short int dawn_time;

public:
  void setDuskTime();
  void setDawnTime();
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
