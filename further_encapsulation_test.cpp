#include "console_remote.hpp"

using namespace std;
using namespace further_encapsulation;

// Clean code achieved?
int main() {
  try {
    runRemote(make_unique<RemoteControl>());
    cout << "Thank You and Good Bye!!" << endl;
  } catch (exception &e) {
    cout << e.what() << endl;
  }
}
