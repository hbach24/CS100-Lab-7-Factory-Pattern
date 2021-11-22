#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "op.hpp"

using namespace std;

class Div : public Base {
    private:
        Base* left;
	Base* right;

    public:
        Div(Base* l, Base* r) : Base() { 
		left = l;
		right = r;
	}

        virtual double evaluate() { 
		double a = left->evaluate();
		double b = right->evaluate();
	if(b == 0) {
	  return -1;
	}
	return a/b; 
	}

        virtual std::string stringify() { 
	return "(" + left->stringify() + " / " + right->stringify() + ")";
	}
	};

#endif //__DIV_HPP__
