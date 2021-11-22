#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Sub: public Base{
        public:
                Sub(Base* op1, Base* op2): Base() {
                        num1 = op1;
                        num2 = op2;
                }
                virtual double evaluate() {return num1->evaluate() - num2->evaluate();}
                virtual string stringify() {return "(" + num1->stringify() + " - " + num2->stringify() + ")";}

        private:
                Base* num1;
                Base* num2;
};

#endif
