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
            list<Base*>::iterator it1 = TreeList.begin();
            list<Base*>::iterator it2 = TreeList.begin();
            Base* temp1 = nullptr;
            Base* temp2 = nullptr;
            int counter = 0;
            while (it1 != TreeList.end() && it2 != TreeList.end()) {
                if (counter == i) {
                    temp1 = (*it1);
                }
                if  (counter == j) {
                    temp2 = (*it2);
                }
                ++counter;
                it1++;
                it2++;
            }
		for (list<Base*>::iterator it3 = TreeList.begin(); it3 != TreeList.end(); ++it3) {
			if (counter == i) {
				*it3 = temp2;
			}
			if (counter == j) {
				*it3 = temp1;
			}
			++counter;
		}
        }
        Base* at(int i) {
		int counter = 0;
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
