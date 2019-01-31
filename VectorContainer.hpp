#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include<iostream>
using namespace std;
#include<vector>
#include "container.hpp"
#include "base.h"
#include "sort.hpp"

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
                Base* k  =  v1.at(i);
                v1.at(i) = v1.at(j);
                v1.at(j) = k;
            }
            
            Base * at(int i){
                return v1.at(i);
            }
            
            int size(){
                return v1.size();
            }
            
            
};

#endif