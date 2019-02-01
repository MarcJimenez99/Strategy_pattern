#include "base.h"
#include "Pow.cpp"
#include "Mult.cpp"
#include "Div.cpp"
#include "Add.cpp"
#include "Sub.cpp"
#include "Rand.cpp"
#include "Op.cpp"
#include "container.hpp"
#include "ListContainer.hpp"
#include "sort.hpp"
#include "bubble.hpp"
#include "VectorContainer.hpp"
#include "SelectionSort.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <string>

using namespace std; 

int main() {
	
	Op* seven = new Op(7);
	Op* four = new Op(4);
	Mult* TreeA = new Mult(seven, four);

	Op* three = new Op(3);
	Op* two = new Op(2);
	Add* TreeB = new Add(three, two);

	Op* ten = new Op(10);
	Op* six = new Op(6);
	Sub* TreeC = new Sub(ten, six);

	ListContainer* container = new ListContainer();

	container->add_element(TreeA);
	container->add_element(TreeB);
	container->add_element(TreeC);

	cout << "First Example: " << endl;
	cout << "First " << container->at(0)->evaluate() << endl;
	cout << "Second " << container->at(1)->evaluate() << endl;
	cout << "Third " << container->at(2)->evaluate() << endl;
	
	container->set_sort_function(new Bubble());
	container->sort();
	
	cout << "First " << container->at(0)->evaluate() << endl;
        cout << "Second " << container->at(1)->evaluate() << endl;
        cout << "Third " << container->at(2)->evaluate() << endl;

	cout << "Second Example: " << endl;
	
	Op* seven2 = new Op(7);
        Op* negOne = new Op(-1);
        Mult* TreeAA = new Mult(seven2, negOne);

        Op* negThree = new Op(-3);
        Op* negFive = new Op(-5);
        Add* TreeAB = new Add(negThree, negFive);

        Op* six6 = new Op(6);
        Op* eight = new Op(8);
        Sub* TreeAC = new Sub(six6, eight);

        VectorContainer* container2 = new VectorContainer();

        container2->add_element(TreeAA);
        container2->add_element(TreeAB);
	container2->add_element(TreeAC);

        cout << "First " << container2->at(0)->evaluate() << endl;
        cout << "Second " << container2->at(1)->evaluate() << endl;
        cout << "Third " << container2->at(2)->evaluate() << endl;

        container2->set_sort_function(new SelectionSort());
        container2->sort();

        cout << "First " << container2->at(0)->evaluate() << endl;
        cout << "Second " << container2->at(1)->evaluate() << endl;
        cout << "Third " << container2->at(2)->evaluate() << endl;
	

	return 0;
}
