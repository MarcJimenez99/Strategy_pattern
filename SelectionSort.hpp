#ifndef _SELECTIONSORT_HPP_
#define _SELECTIONSORT_HPP_

#include "sort.hpp"
#include "VectorContainer.hpp"
#include "container.hpp"
#include<iostream>
using namespace std;

class Container;

class SelectionSort : public Sort{
    public:
        //selecti
        /* Pure Virtual Functions */
        void sort(Container* container){
           int i, j, first;
           Base * temp;
           int numLength = container->size();
            for (i= numLength - 1; i > 0; i--){
               first = 0;                 // initialize to subscript of first element
               for (j=1; j<=i; j++)   // locate smallest between positions 1 and i.
              {
                     if (container->at(j) < container->at(first))
                     first = j;
              }
              container->swap(i,first);
             
         }
         return;
    } 
};

#endif //__SORT_HPP__
