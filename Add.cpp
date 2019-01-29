#ifndef ADD_H
#define ADD_H

#include "base.h"
#include "Op.cpp"
#include "Rand.cpp"
#include "Pow.cpp"
#include "Mult.cpp"
#include "Div.cpp"

class Add : public Base {
	private:
		Base* left;
		Base* right;
	public:
		Add(Base* v1, Base* v2){
		left = v1;
		right = v2;
	}
	double evaluate() {
		return left->evaluate() + right->evaluate();
	}
	string stringify(){
		string sent;
		sent = to_string(left->evaluate()) + " + " + to_string(right->evaluate());
		return sent;
	}
};

#endif
