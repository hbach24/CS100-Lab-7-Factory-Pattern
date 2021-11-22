#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"

using namespace std;

class Mult : public Base {
    private:
        Base* left;
	Base* right;

    public:
        Mult(Base* l, Base* r) : Base() { 
		left = l;
		right = r;
	}

        virtual double evaluate() { 
		double a = left->evaluate();
		double b = right->evaluate();
	return a * b; 
	}

        virtual std::string stringify() { 
		return "(" + left->stringify() + " * " + right->stringify() + ")";	
	}
	};

#endif //__MULT_HPP__
