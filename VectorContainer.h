#ifndef __VECTORCONTAINER_H__
#define __VECTORCONTAINER_H__

#include <vector> 
//#include "base.h"
#include "container.hpp"
#include "sort.hpp"
//class SelectionSort;
//class Bubble;

class VectorContainer : public Container  {
	protected:
		vector<Base *> v1;
	public:
		void set_sort_function(Sort * sort_function);
		void add_element(Base* element);
		void print();
		void sort();
		void swap(int i, int j);
		Base * at(int i);
		int size();
};
#endif
