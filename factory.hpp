#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__
#include <queue>
#include <stack>
#include <ctype.h>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

class Factory {
public:
    Base* parse(char** input, int length) {
	Base* op = nullptr;
	char c = *input[1];
	if(isdigit(c)) { //check if the first char in string is a digit
	   op = new Op(stod(input[1]));
	} else { return nullptr; }

	if(!isdigit(*input[length-1])) { //if we end with an operator in the string, return nullptr (Invalid input.) e.g. 3 + 5 - 
	       return nullptr;
	}

	for(int i = 2; i < length-1; i = i + 2) {
	    string ch = input[i];
	    if(!isdigit(*input[i+1])) { //if secOp is not a digit, return nullptr (Invalid input.)
		return nullptr;
	    }
	    if(ch == "+") {
		Base* secOp = new Op(stod(input[i+1]));
		Base* add = new Add(op, secOp);
		op = add;
	    }
	    else if(ch == "-") {
	    	Base* secOp = new Op(stod(input[i+1]));
		Base* sub = new Sub(op, secOp);
		op = sub;  		
	    }
	    else if(ch == "*") {
		Base* secOp = new Op(stod(input[i+1]));
		Base* mult = new Mult(op, secOp);
		op = mult;
	   }
	   else if(ch == "/") {
		Base* secOp = new Op(stod(input[i+1]));
		Base* div = new Div(op, secOp);
		op = div;
	  }
	  else if(ch == "**") {
		Base* secOp = new Op(stod(input[i+1]));
		Base* pow = new Pow(op, secOp);
		op = pow;
	  }
	 else {
		return nullptr; //if it is none of the above operators, return nullptr (Invalid input.)
	 }

	}//end of for
	return op; 
}//end of parse	
};

#endif //__FACTORY_HPP__
