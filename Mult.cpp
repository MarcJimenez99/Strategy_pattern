#ifndef MULT_H
#define MULT_H

#include "base.hpp"
#include "Op.cpp"
#include "Rand.cpp"
#include "Pow.cpp"
#include <iostream>
#include <string>

using namespace std;

class Mult : public Base {

	private:
		Base* left;
		Base* right;
	public:
		Mult(Base* v1, Base* v2) {
			left = v1;
			right = v2;
		}
		double evaluate() {
			return ((left->evaluate()) * (right->evaluate()));
		}
		string stringify() {
			string sent = to_string(left->evaluate()) + " * " + to_string(right->evaluate());
			return sent;
		}  

};

#endif
