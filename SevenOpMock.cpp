#ifndef SEVEN_OP_MOCK_H
#define SEVEN_OP_MOCK_H

#include "base.h"

class SevenOpMock : public Base {

	public:
		OpMock() { };
		virtual double evaluate() { return 7.5; }
		virtual string stringify() { return "7.5"; }
};

#endif
