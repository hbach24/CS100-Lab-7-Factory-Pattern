#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
using namespace std;

class Op : public Base {
    protected:
	double v;

    public:
        Op(double value) : Base() { v = value; }
        virtual double evaluate() { return v; }
        virtual std::string stringify() { return to_string(v); }
};

#endif //__OP_HPP__
