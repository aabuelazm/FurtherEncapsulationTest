#include "console_remote.hpp"

using namespace std;
using namespace further_encapsulation;

int main() {
  auto remote = make_unique<RemoteControl>();

  try {
    consoleRemote(move(remote));
  } catch (exception &e) {
    cout << e.what() << endl;
  }

  cout << "Thank You and Good Bye!!" << endl;
}
