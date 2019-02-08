#include "ListContainer.h"       	
#include "sort.hpp"

        void ListContainer::add_element(Base* element) {
            TreeList.push_back(element);
        }
        void ListContainer::print() {
            for (list<Base*>::iterator it = TreeList.begin(); it != TreeList.end(); ++it) {
                (*it)->stringify();
            }
        }
        void ListContainer::sort() {
            sort_function->sort(this);
        }
        void ListContainer::swap(int i, int j) {
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
        Base* ListContainer::at(int i) {
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
        int ListContainer::size() {
            int size = 0;
            for (list<Base*>::iterator it = TreeList.begin(); it != TreeList.end(); ++it) {
                ++size;
            }
            return size;
        }
