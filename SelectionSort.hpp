#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include "VectorContainer.hpp"
#include "container.hpp"
#include "sort.hpp"
#include <iostream>
#include <vector> 

using namespace std;

class Container;

class SelectionSort : public Sort {
	public: 
		void sort(Container* container) {
			int first = 0;
			for (int i = container->size()-1; i > 0; i--) {
				first = 0;
				for (int j = 1; j <= i; j++) {
					if (container->at(j)->evaluate() > container->at(first)->evaluate()) {
						first = j;
					}
				} 
				container->swap(first, i);
			}
		}
};

#endif
