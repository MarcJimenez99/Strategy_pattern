#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include<iostream>
#include<vector>
#include "container.hpp"
#include "base.h"
#include "sort.hpp"

using namespace std;

class VectorContainer : public Container {
        protected:
            Sort * sort_function;
            vector <Base *> v1;
        public:
            void set_sort_function(Sort * sort_function){
                this->sort_function = sort_function;
            }
            
            void add_element(Base * element){
                v1.push_back(element);
            }
            
            void print(){
                for(int i = 0; i < v1.size(); ++i){
                    (v1.at(i))->stringify();
                }
            }
            
            void sort(){
                sort_function->sort(this);
            }
            
            void swap(int i, int j){
                Base* first = v1.at(i);
		Base* second = v1.at(j);
		v1.at(i) = second;
		v1.at(j) = first;
            }
            
            Base * at(int i){
		if (v1.size() == 0) {
			return nullptr;
		}
                return v1.at(i);
            }
            
            int size(){
                return v1.size();
            }
            
            
};

#endif
