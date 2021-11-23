#include "gtest/gtest.h"
#include "factory.hpp"
#include "base.hpp"
#include <iostream>
using namespace std;

TEST(FactoryTest, AddMult) {
	int argc = 6;
	char* argv[] = {"./calculator", "4", "+", "3", "*", "5"};
	Factory* factory = new Factory();
	Base* op = factory->parse(argv, argc);
	
	EXPECT_EQ("((4.000000 + 3.000000) * 5.000000)", op->stringify());
	EXPECT_EQ(35, op->evaluate());
}

TEST(FactoryTest, SubDiv) {
        int argc = 6;
        char* argv[] = {"./calculator", "13", "-", "3", "/", "5"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ("((13.000000 - 3.000000) / 5.000000)", op->stringify());
        EXPECT_EQ(2, op->evaluate());
}

TEST(FactoryTest, AddPow) {
        int argc = 6;
        char* argv[] = {"./calculator", "2", "+", "3", "**", "2"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ("((2.000000 + 3.000000) ** 2.000000)", op->stringify());
        EXPECT_EQ(25, op->evaluate());
}


TEST(FactoryTest, ConsecutiveOperator) {
        int argc = 7;
        char* argv[] = {"./calculator", "4", "+", "-", "3", "*", "5"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ(nullptr, op);
}

TEST(FactoryTest, StartWithOperator) {
        int argc = 7;
        char* argv[] = {"./calculator", "+", "4", "-", "3", "*", "5"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ(nullptr, op);
}

TEST(FactoryTest, EndWithOperator) {
        int argc = 5;
        char* argv[] = {"./calculator", "4", "+", "3", "*"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ(nullptr, op);
}

TEST(FactoryTest, OneNumber) {
        int argc = 2;
        char* argv[] = {"./calculator", "4"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ("4.000000", op->stringify());
	EXPECT_EQ(4, op->evaluate());
}

TEST(FactoryTest, OneOperator) {
        int argc = 7;
        char* argv[] = {"./calculator", "+"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ(nullptr, op);
}

TEST(FactoryTest, OnlyOperator) {
        int argc = 4;
        char* argv[] = {"./calculator", "+", "-", "*"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ(nullptr, op);
}

TEST(FactoryTest, OnlyNumbers) {
        int argc = 4;
        char* argv[] = {"./calculator", "4", "5", "6"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ(nullptr, op);
}

TEST(FactoryTest, UnknownOperator) {
        int argc = 4;
        char* argv[] = {"./calculator", "4", "$", "3"};
        Factory* factory = new Factory();
        Base* op = factory->parse(argv, argc);

        EXPECT_EQ(nullptr, op);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
