#ifndef COMMANDER_CLASS_HPP
#define COMMANDER_CLASS_HPP

#include <iostream>

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
} // namespace further_encapsulation

#endif
