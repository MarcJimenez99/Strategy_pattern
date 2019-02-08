#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iosfwd>
#include <string>
#include <iostream>

using namespace std;

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};

#endif //__BASE_HPP__
