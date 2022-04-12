#ifndef COMMANDER_CLASS_HPP
#define COMMANDER_CLASS_HPP

#include <cstdlib>
#include <cxxabi.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace further_encapsulation {
enum class Button : bool { Off = false, On = true };

class Commander {
public:
  virtual void on() { cout << "On: Slot is empty" << endl; }

  virtual void off() { cout << "Off: Slot is empty" << endl; }

  virtual void undo(Button last_command) {
    cout << "Undo: Slot is empty" << endl;
  }

  virtual void printData() {
    string type = abi::__cxa_demangle(typeid(*this).name(), 0, 0, 0);

    auto itr = type.find_last_of(':');
    type.erase(0, itr + 1);

    itr = type.find("Commander");
    type.erase(itr);

    cout << type << endl;
  }
};

class MacroCommander : virtual public Commander {
public:
  vector<shared_ptr<Commander>> commanders;

  void on() {
    for (auto commander : commanders)
      commander->on();
  }

  void off() {
    for (auto commander : commanders)
      commander->off();
  }

  void undo(Button last_command) {
    for (auto commander : commanders)
      commander->undo(last_command);
  }

  void printData() {
    string type = abi::__cxa_demangle(typeid(*this).name(), 0, 0, 0);

    auto itr = type.find_last_of(':');
    type.erase(0, itr + 1);

    itr = type.find("Commander");
    type.erase(itr);

    cout << type << endl;

    for (auto commander : commanders) {
      cout << "   - ";
      commander->printData();
    }
  }
};
} // namespace further_encapsulation

#endif
