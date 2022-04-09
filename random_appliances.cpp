#include "random_appliances.hpp"

using namespace std;
using namespace further_encapsulation;

void ApplianceControl::on() { cout << "Appliance On" << endl; }
void ApplianceControl::off() { cout << "Appliance Off" << endl; }

void Stereo::on() { cout << "The Vibes are vibing" << endl; }
void Stereo::off() { cout << "The Vibes are dead" << endl; }
void Stereo::setCD() { cout << "The Vibes are coming from a disc" << endl; }
void Stereo::setDVD() {
  cout << "The Vibes are coming from a large disc" << endl;
}
void Stereo::setRadio() {
  cout << "The Vibes are coming from the waves" << endl;
}
void Stereo::setVolume(unsigned short int volume) {
  cout << "Vibe check: " << volume << endl;
}

void FaucetControl::openValve() { cout << "WET" << endl; }
void FaucetControl::closeValve() { cout << "NOT WET" << endl; }

void Hottub::circulate() { cout << "Hottub swirly" << endl; }
void Hottub::jetsOn() { cout << "Hottub fun" << endl; }
void Hottub::jetsOff() { cout << "Hottub unfun" << endl; }
void Hottub::setTemperature(float temperature) {
  cout << "Hottub is at " << temperature << " degrees. Soup time" << endl;
}

void Thermostat::setTemperature(float temperature) {
  cout << "The room is now " << temperature << " degrees." << endl;
}

void SecurityControl::arm() { cout << "Engage kill mode" << endl; }
void SecurityControl::disarm() { cout << "Disengage kill mode" << endl; }

void CeilingLight::on() { cout << "Let there be light!" << endl; }
void CeilingLight::off() { cout << "Let there be no light!" << endl; }
void CeilingLight::dim() { cout << "Let there be some light!" << endl; }

void OutdoorLight::on() { cout << "Laser Defense" << endl; }
void OutdoorLight::off() { cout << "Laser Defense Disabled" << endl; }

void TV::on() { cout << "Background noise machine on" << endl; }
void TV::off() { cout << " Background noise machine off" << endl; }
void TV::setInputChannel(unsigned int channel) {
  cout << "You're now watching Channel " << channel << " news!" << endl;
}
void TV::setVolume(unsigned int volume) {
  cout << "Background noise level at " << volume << endl;
}

void CeilingFan::high() {
  this->speed = 420;
  cout << this->speed << endl;
}
void CeilingFan::medium() {
  this->speed = 210;
  cout << this->speed << endl;
}
void CeilingFan::low() {
  this->speed = 105;
  cout << this->speed << endl;
}
void CeilingFan::off() {
  this->speed = 0;
  cout << this->speed << endl;
}
unsigned int CeilingFan::getSpeed() {
  cout << "Speed at " << this->speed << endl;
  return this->speed;
}

void GardenLight::setDuskTime(unsigned short int d_time) {
  dusk_time = d_time;
  cout << "Dusk is now at " << dusk_time << ":00 PM" << endl;
}
void GardenLight::setDawnTime(unsigned short int d_time) {
  dawn_time = d_time;
  cout << "Dawn is now at " << dusk_time << ":00 AM" << endl;
}
void GardenLight::manualOn() { cout << "Hey, I was napping" << endl; }
void GardenLight::manualOff() { cout << "Hey, I wasn't done" << endl; }

void GarageDoor::up() { cout << "Going up!" << endl; }
void GarageDoor::down() { cout << "Going down!" << endl; }
void GarageDoor::stop() { cout << "Ding!" << endl; }
void GarageDoor::lightOn() { cout << "Garage light on" << endl; }
void GarageDoor::lightOff() { cout << "Garage light off" << endl; }

void Sprinkler::waterOn() { cout << "Tinkle Time" << endl; }
void Sprinkler::waterOff() { cout << "Tinkle Time Terminated" << endl; }

void Light::on() { cout << "You turn me on :)" << endl; }
void Light::off() { cout << "You turn me off :(" << endl; }
