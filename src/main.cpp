#include <iostream>
#include "Automata.h"

int main() {
    Automata Machine;

    Machine.on();
    Machine.getMenu();
    Machine.coin(100);
    Machine.choice("flat white");
    std::cout << std::endl;
    Machine.coin(100);
    Machine.choice("flat white");
    std::cout << std::endl;
    Machine.cancel();
    Machine.off();
  return 0;
}
