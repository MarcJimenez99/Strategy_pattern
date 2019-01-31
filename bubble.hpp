#ifndef _BUBBLE_HPP_
#define _BUBBLE_HPP_

#include "container.hpp"
#include "sort.hpp"
#include "ListContainer.hpp"

//class Container;
//class Sort;

class Bubble : public Sort {
    private:
        Sort* sort_function = nullptr;
    public:
        void sort(Container* container) {
            int i, j, flag = 1;
            Base* temp;
            int numLength = container->size();
            for (i = 1; (i <=numLength) && flag; i++) {
                flag = 0;
                for (j = 0; j < (numLength - 1); j++) {
                    if (container->at(j+1) < container->at(j)) {
                        container->swap(j, j+1);
                        flag = 1;
                    }
                }
            }
            return;
        
        }        
};

#endif
