#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "factory.hpp"

//using namespace std;

int main(int argc, char** argv) {
  Factory* factory = new Factory();
  Base* op = factory->parse(argv, argc);
  if(op == nullptr) { 
	cout << "Invalid input." << endl;
  }
  else {
  	cout << op->stringify() << " = " << op->evaluate() << endl;
  }
   return 0;
}
