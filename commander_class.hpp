#ifndef COMMANDER_CLASS_HPP
#define COMMANDER_CLASS_HPP

#include <iostream>
#include <vector>

namespace further_encapsulation {
enum class Button : bool { Off = false, On = true };

class Commander {
public:
  virtual void on() { std::cout << "On: Slot is empty" << std::endl; }

  virtual void off() { std::cout << "Off: Slot is empty" << std::endl; }

  virtual void undo(Button last_command) {
    std::cout << "Undo: Slot is empty" << std::endl;
  }
};

class MacroCommander : virtual public Commander {
public:
  std::vector<Commander *> commanders;

  void on() {
    for (auto commander : commanders) {
      commander->on();
    }
  }

  void off() {
    for (auto commander : commanders) {
      commander->off();
    }
  }

  void undo(Button last_command) {
    for (auto commander : commanders) {
      commander->undo(last_command);
    }
  }
};
} // namespace further_encapsulation

#endif
