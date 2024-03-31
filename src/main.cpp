#include <iostream>
#include "Automata.h"

int main() {
    Automata Machine;

    Machine.on();
    Machine.getMenu();
    Machine.coin(100);

    Machine.off();
  return 0;
}
