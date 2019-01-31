#include "gtest/gtest.h"
#include "ListContainer.hpp"
#include "sort.hpp"
#include "bubble.hpp"
#include "base.h"
#include "Pow.cpp"
#include "Mult.cpp"
#include "Div.cpp"
#include "Add.cpp"
#include "Sub.cpp"
#include "Rand.cpp"
#include "Op.cpp" 
#include "RandMock.cpp"
#include "VectorContainer.hpp"
#include "SelectionSort.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

TEST(StrategyTest, BubbleTest) {

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

	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), 28);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 4);
}

int main(int argc, char**argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
