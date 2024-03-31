// Copyright 2024 Goanni
#include <gtest/gtest.h>
#include "Automata.h"
class AutomataTest : public testing::Test {
 protected:
    Automata Machine;
};

TEST(AutomataTest, test1) {
    Automata Machine;
    Machine.on();
    EXPECT_EQ(Wait, Machine.getState());
}

TEST(AutomataTest, test2) {
    Automata Machine;
    Machine.on();
    Machine.coin(100);
    EXPECT_EQ(Accept, Machine.getState());
}

TEST(AutomataTest, test3) {
    Automata Machine;
    Machine.on();
    Machine.off();
    EXPECT_EQ(Off, Machine.getState());
}

TEST(AutomataTest, test4) {
    Automata Machine;
    Machine.on();
    Machine.coin(90);
    Machine.choice("green tea");
    Machine.cook("green tea");
    Machine.finish("green tea");
    EXPECT_EQ(Wait, Machine.getState());
}

TEST(AutomataTest, test5) {
    Automata Machine;
    Machine.on();
    Machine.coin(80);
    Machine.choice("green tea");
    EXPECT_EQ(false, Machine.check("green tea"));
}

TEST(AutomateTest, test6) {
    Automata Machine;
    Machine.off();
    EXPECT_EQ(Off, Machine.getState());
}
