#ifndef LIST_CONTAINER_HPP
#define LIST_CONTAINER_HPP

#include "sort.hpp"
#include "base.h"
#include "container.hpp"
#include "bubble.hpp"
#include <iostream>
#include <list>
#include <stdio.h>

//class Sort;
//class Base;

using namespace std;

class ListContainer : public Container {
    protected:
        list<Base* > TreeList;
    public:
        void set_sort_function(Sort* sort_function) {
            this->sort_function = sort_function;
        }
        void add_element(Base* element) {
            TreeList.push_back(element);
        }
        void print() {
            for (list<Base*>::iterator it = TreeList.begin(); it != TreeList.end(); ++it) {
                (*it)->stringify();
            }
        }
        void sort() {
            sort_function->sort(this);
        }
        void swap(int i, int j) {
            list<Base*>::iterator ptr = TreeList.begin();
		auto ptr1 = ptr;
		auto ptr2 = ptr;
		for (unsigned int x = 0; x < i; ++x) {
			ptr1++;
		}
		for (unsigned int y = 0; y < j; ++y) {
			ptr2++;
		}
		std::swap(*ptr1, *ptr2);
        }
        Base* at(int i) {
		int counter = 0;
		if (TreeList.size() == 0) {
			Base* fail = nullptr;
			return fail;	
		}
		for (list<Base*>::iterator it = TreeList.begin(); it != TreeList.end(); ++it) {
			if (counter == i) {
				Base* temp1 = (*it);
				return temp1;
                	}
			counter++;
		}
        }
        int size() {
            int size = 0;
            for (list<Base*>::iterator it = TreeList.begin(); it != TreeList.end(); ++it) {
                ++size;
            }
            return size;
        }
};

#endif
