#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

using namespace std;

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual string stringify() = 0;
};

#endif
