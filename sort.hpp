#ifndef _SORT_HPP_
#define _SORT_HPP_


#include "container.hpp"

class Container;
class Sort {
    public:
        /* Constructors */
        Sort() {};

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

#endif //__SORT_HPP__
