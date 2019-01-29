#ifndef POW_H
#define POW_H

#include "base.h"
#include "Op.cpp"
#include "Rand.cpp"

class Pow : public Base { 
    
	private:
		Base* left;
		Base* right;
	public:
	Pow(Base* v1, Base* v2){
		left = v1;
		right = v2;
	}
	double evaluate() {
		return left->evaluate() * right->evaluate();
	}
	string stringify(){
		string sent;
		sent = to_string(left->evaluate()) + " ^ " + to_string(right->evaluate());
		return sent;
	}	
        
};

#endif
