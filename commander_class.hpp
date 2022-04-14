#ifndef COMMANDER_CLASS_HPP
#define COMMANDER_CLASS_HPP

#include <cstdlib>
#include <cxxabi.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// An attempt to apply more OOP good design principles to the Command Pattern in
// Head First Design Patterns. Instead of creating 2 classes to deal with an
// appliance (an ON command class and an OFF command class), we design the
// remote to put a Commander class in each of its slots and it just passes the
// button press to it, allowing the remote to not care about anything other than
// knowing that it is dealing wih a Commander class or subclass
namespace further_encapsulation {
enum class Button : bool { Off = false, On = true };

class Commander {
public:
  virtual void on() { cout << "On: Slot is empty" << endl; }

  virtual void off() { cout << "Off: Slot is empty" << endl; }

  virtual void undo(Button last_command) {
    if (bool(last_command))
      this->off();
    else
      this->on();
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

static unsigned short level = 0;
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
    cout << "Macro" << endl;
    level++;

    for (auto commander : commanders) {
      for (int i = 0; i < level; i++)
        cout << "     ";
      commander->printData();
    }

    level--;
  }
};

// For use with MacroCommander, allows a Macro that turns on one thing and
// turns something else off. Decorator Pattern Baby!!
class ReverseCommander : virtual public Commander {
private:
  shared_ptr<Commander> commander;

  // make default constructor private so people do not attempt it
  ReverseCommander() {}

public:
  ReverseCommander(shared_ptr<Commander> input) : commander(input) {}

  void on() { commander->off(); }
  void off() { commander->on(); }

  void printData() {
    cout << "!";
    commander->printData();
  }
};
} // namespace further_encapsulation

#endif
