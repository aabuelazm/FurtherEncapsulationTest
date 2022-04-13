#include "console_remote.hpp"

using namespace std;
using namespace further_encapsulation;

int main() {
  try {
    consoleRemote(make_unique<RemoteControl>());
  } catch (exception &e) {
    cout << e.what() << endl;
  }

  cout << "Thank You and Good Bye!!" << endl;
}
