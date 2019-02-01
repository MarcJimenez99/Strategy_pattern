#include<iostream>
#include<vector>
#include "VectorContainer.h"


using namespace std;
	
void VectorContainer ::  set_sort_function(Sort * sort_function){
	this->sort_function = sort_function;
}
           
void VectorContainer :: add_element(Base * element){
                v1.push_back(element);
}
            
void VectorContainer :: print(){
	for(int i = 0; i < v1.size(); ++i){
        	(v1.at(i))->stringify();
         }
}
            
void VectorContainer :: sort(){
        sort_function->sort(this);
}
            
void VectorContainer ::  swap(int i, int j){
	 Base* first = v1.at(i);
	 Base* second = v1.at(j);
	 v1.at(i) = second;
	 v1.at(j) = first;
}
            
Base * VectorContainer ::  at(int i){
	if (v1.size() == 0) {
		return nullptr;
	}
	return v1.at(i);
}
            
int VectorContainer ::  size(){
	return v1.size();
}
            
           
