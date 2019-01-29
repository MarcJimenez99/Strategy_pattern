#ifndef RAND_MOCK_H
#define RAND_MOCK_H

#include "base.h"

class RandMock : public Base {
	public:
		RandMock() { };

		virtual double evaluate() { return 2.0; }
		virtual string stringify() { return "2.000000"; }

};

#endif
