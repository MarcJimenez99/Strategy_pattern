#ifndef RAND_H
#define RAND_H
#include "base.h"
 
class Rand : public Base {
	private:
		double value = 0;
	public:
		Rand() {
			value = static_cast<double>(rand() % 100); 
		}
		double evaluate () {
			return value;
		}
		string stringify() {
			to_string(value); 
		}
};

#endif
