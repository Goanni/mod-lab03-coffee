// Copyright 2024 Goanni
#include "Automata.h"
#include <string>
#include <map>
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = Off;
    prices["latte"] = 160;
    prices["cappuccino"] = 160;
    prices["americano"] = 170;
    prices["flat white"] = 190;
    prices["black tea"] = 80;
    prices["green tea"] = 90;
    prices["hot chocolate"] = 170;
    prices["cacao"] = 150;
}

Automata::~Automata() {}

void Automata::on() {
    if (state == Off) {
        state = Wait;
        std::cout << "ON" << std::endl;
    } else{
    std::cout << "The machine is already turned on" << std::endl;
  }
}

void Automata::off() {
    if (state == Wait) {
        state = Off;
        std::cout << "\nMachine is off" << std::endl;
    } else{
    std::cout << "\nWait for the machine to complete the process" << std::endl;
  }
}

void Automata::coin(int money) {
    if (state == Wait || state == Accept) {
        cash += money;
        state = Accept;
        std::cout << "\nMoney is accepted" << cash << std::endl;
    } else{
    std::cout << "\nOperation cannot be performed" << std::endl;
  }
}

void Automata::getMenu() {
    std::cout << "/nMenu" << std::endl;
    if (state == Wait || state == Accept) {
        for (const auto& element : prices)
            std::cout << element.first << "\t" << element.second << std::endl;
    } else{
    std::cout << "\nOperation cannot be performed" << std::endl;
  }
}

states Automata::getState() {
    return state;
}

void Automata::choice(std::string name) {
    if (state == Accept) {
        if (prices.count(name) == 0) {
            std::cout << "\nMistake!";
        } else {
            state = Check;
            if (check(name))
                cook(name);
            }
        } else{
    std::cout << "\nOperation cannot be performed" << std::endl;
  }
}

bool Automata::check(std::string name) {
    if ((state == Check || state == Accept)
        && cash >= prices.find(name)->second)
        return true;
    state = Accept;
    return false;
}

void Automata::cancel() {
    if (state == Accept || state == Check) {
        cash = 0;
        state = Wait;
        std::cout << "\nThe order is cancelled" << std::endl;
    } else{
    std::cout << "\nOperation cannot be performed" << std::endl;
  }
}

void Automata::cook(std::string name) {
  if (state == Check)
  {
    cash -= prices.find(name)->second;
    state = Cook;
    std::cout << "\nThe drink is cooked" << std::endl;
    finish(name);
  } else{
    std::cout << "\nOperation cannot be performed" << std::endl;
  }
}

void Automata::finish(std::string name) {
  if(state == Cook)
  {
    std::cout << "\nYour change" << cash << std::endl;
    std::cout << "\nYour drink " << name << " is ready!" << std::endl;
    cash = 0;
    state = Wait;
  } else{
    std::cout << "\nOperation cannot be performed" << std::endl;
  }
}
