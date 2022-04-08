#include "random_appliances.hpp"

using namespace std;
using namespace further_encapsulation;

class ApplianceControl {
public:
  void on() { cout << "Appliance On" << endl; }
  void off() { cout << "Appliance Off" << endl; }
};

class Stereo {

public:
  void on() { cout << "The Vibes are vibing" << endl; }
  void off() { cout << "The Vibes are dead" << endl; }
  void setCD() { cout << "The Vibes are coming from a disc" << endl; }
  void setDVD() { cout << "The Vibes are coming from a large disc" << endl; }
  void setRadio() { cout << "The Vibes are coming from the waves" << endl; }
  void setVolume(unsigned short int volume) {
    cout << "Vibe check: " << volume << endl;
  }
};

class FaucetControl {
public:
  void openValve() { cout << "WET" << endl; }
  void closeValve() { cout << "NOT WET" << endl; }
};

class Hottub {
public:
  void circulate() { cout << "Hottub swirly" << endl; }
  void jetsOn() { cout << "Hottub fun" << endl; }
  void jetsOff() { cout << "Hottub unfun" << endl; }
  void setTemperature(float temperature) {
    cout << "Hottub is at " << temperature << " degrees. Soup time" << endl;
  }
};

class SecurityControl {
public:
  void arm() { cout << "Engage kill mode" << endl; }
  void disarm() { cout << "Disengage kill mode" << endl; }
};

class CeilingLight {
public:
  void on() { cout << "Let there be light!" << endl; }
  void off() { cout << "Let there be no light!" << endl; }
  void dim() { cout << "Let there be some light!" << endl; }
};

class OutdoorLight {
public:
  void on() { cout << "Laser Defense" << endl; }
  void off() { cout << "Laser Defense Disabled" << endl; }
};

class TV {
public:
  void on() { cout << "Background noise machine on" << endl; }
  void off() { cout << " Background noise machine off" << endl; }
  void setInputChannel(unsigned int channel) {
    cout << "You're now watching Channel " << channel << " news!" << endl;
  }
  void setVolume(unsigned int volume) {
    cout << "Background noise level at " << volume << endl;
  }
};

class CeilingFan {
private:
  unsigned int speed{};

public:
  void high() {
    speed = 420;
    cout << speed << endl;
  }
  void medium() {
    speed = 210;
    cout << speed << endl;
  }
  void low() {
    speed = 105;
    cout << speed << endl;
  }
  void off() {
    speed = 0;
    cout << speed << endl;
  }
  unsigned int getSpeed() {
    cout << "Speed at " << speed << endl;
    return speed;
  }
};

class GardenLight {
private:
  unsigned short int dusk_time{};
  unsigned short int dawn_time{};

public:
  void setDuskTime(unsigned int d_time) {
    dusk_time = d_time;
    cout << "Dusk is now at " << dusk_time << ":00 PM" << endl;
  }
  void setDawnTime(unsigned int d_time) {
    dawn_time = d_time;
    cout << "Dawn is now at " << dusk_time << ":00 AM" << endl;
  }
  void manualOn() { cout << "Hey, I was napping" << endl; }
  void manualOff() { cout << "Hey, I wasn't done" << endl; }
};

class GarageDoor {
public:
  void up() { cout << "Going up!" << endl; }
  void down() { cout << "Going down!" << endl; }
  void stop() { cout << "Ding!" << endl; }
  void lightOn() { cout << "Garage light on" << endl; }
  void lightOff() { cout << "Garage light off" << endl; }
};

class Sprinkler {
public:
  void waterOn() { cout << "Tinkle Time" << endl; }
  void waterOff() { cout << "Tinkle Time Terminated" << endl; }
};

class Light {
public:
  void on() { cout << "You turn me on :)" << endl; }
  void off() { cout << "You turn me off :(" << endl; }
};
