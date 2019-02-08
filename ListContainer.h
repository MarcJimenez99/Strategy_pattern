#ifndef LISTCONTAINER_H
#define LISTCONTAINER_H

#include <list>

#include "container.hpp"

class ListContainer : public Container {
	protected:
		//Sort* sort_function;
		list<Base*> TreeList; 
	public: 
		void set_sort_function(Sort* sort_function);
		void add_element(Base* element); 
		void print();
		void sort();
		void swap(int i, int j);
		Base* at(int i);
		int size();
};
#endif 
