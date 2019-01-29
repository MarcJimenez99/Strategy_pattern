#ifndef OP_H
#define OP_H

#include "base.h"

class Op : public Base {

	private: 
		double value = 0;
	public:
		Op(int num) {
			value = static_cast<double>(num);
		}
		Op(double num) {
			value = num;
		}
		double evaluate() {
			return value; 
		}
		string stringify() {
			return to_string(value);
		}

};

#endif
