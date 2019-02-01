#ifndef __VECTORCONTAINER_H__
#define __VECTORCONTAINER_H__

#include<iostream>
#include<vector>
using namespace std;

class Base;
class Sort;
class Container;

class VectorContainer : public Container{
	protected:
		Sort * sort_function;
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
