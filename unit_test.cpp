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

TEST(StrategyTest, PopulateList) {

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
TEST(StrategyTest, BubbleList) {
	
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

	container->set_sort_function(new Bubble());
	container->sort();

	ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 28);

}
TEST(StrategyTest, EmptyList) {
	ListContainer* container = new ListContainer();
	ASSERT_EQ(container->size(), 0);
	EXPECT_EQ(container->at(0), nullptr); 
}
TEST(StrategyTest, NegativeBubbleList) {
	Op* two = new Op(2);
	Op* four = new Op(4);
	Mult* TreeA = new Mult(two, four);

	Op* five = new Op(5);
	Op* one = new Op(1);
	Sub* TreeB = new Sub(five, one);
	
	Op* seven = new Op(-7);
	Op* three = new Op(-3);
	Add* TreeC = new Add(seven, three);

	ListContainer* container = new ListContainer();

	container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
	
	container->set_sort_function(new Bubble());
	container->sort();
	
	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), -10);
	EXPECT_EQ(container->at(1)->evaluate(), 4);
	EXPECT_EQ(container->at(2)->evaluate(), 8); 
}
TEST(StrategyTest, SelectionSortList) {

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
	
	container->set_sort_function(new SelectionSort());
	container->sort();

	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), 4);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 28);	
}
TEST(StrategyTest, SelectionSortNegativeList) {
	Op* seven = new Op(7);
        Op* negOne = new Op(-1);
        Mult* TreeA = new Mult(seven, negOne);

        Op* negThree = new Op(-3);
        Op* negFive = new Op(-5);
        Add* TreeB = new Add(negThree, negFive);

        Op* six = new Op(6);
        Op* eight = new Op(8);
        Sub* TreeC = new Sub(six, eight);

	ListContainer* container = new ListContainer();

        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), -8);
        EXPECT_EQ(container->at(1)->evaluate(), -7);
        EXPECT_EQ(container->at(2)->evaluate(), -2);
}

TEST(Strategy, SelectionSortNegativeVector) {
	Op* seven = new Op(7);
        Op* negOne = new Op(-1);
        Mult* TreeA = new Mult(seven, negOne);

        Op* negThree = new Op(-3);
        Op* negFive = new Op(-5);
        Add* TreeB = new Add(negThree, negFive);

        Op* six = new Op(6);
        Op* eight = new Op(8);
        Sub* TreeC = new Sub(six, eight);

        VectorContainer* container = new VectorContainer();

        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), -8);
        EXPECT_EQ(container->at(1)->evaluate(), -7);
        EXPECT_EQ(container->at(2)->evaluate(), -2);
}
TEST(Strategy, SelectionSortVector) {
        Op* seven = new Op(7);
        Op* One = new Op(1);
        Mult* TreeA = new Mult(seven, One);

        Op* Three = new Op(3);
        Op* Five = new Op(5);
        Add* TreeB = new Add(Three, Five);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Sub* TreeC = new Sub(three, two);

        VectorContainer* container = new VectorContainer();

        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 1);
        EXPECT_EQ(container->at(1)->evaluate(), 7);
        EXPECT_EQ(container->at(2)->evaluate(), 8);
}
TEST(StrategyTest, EmptyVector) {
        VectorContainer* container = new VectorContainer();
        ASSERT_EQ(container->size(), 0);
        EXPECT_EQ(container->at(0), nullptr);
}
TEST(StrategyTest, BubbleVector) {
	Op* seven = new Op(7);
        Op* four = new Op(4);
        Mult* TreeA = new Mult(seven, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Sub* TreeC = new Sub(ten, six);

        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 28);

}
TEST(StrategyTest, NegativeBubbleVector) { 
	Op* seven = new Op(7);
        Op* negOne = new Op(-1);
        Mult* TreeA = new Mult(seven, negOne);

        Op* negThree = new Op(-3);
        Op* negFive = new Op(-5);
        Add* TreeB = new Add(negThree, negFive);

        Op* six = new Op(6);
        Op* eight = new Op(8);
        Sub* TreeC = new Sub(six, eight);

        VectorContainer* container = new VectorContainer();

        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        container->set_sort_function(new Bubble());
        container->sort();

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), -8);
        EXPECT_EQ(container->at(1)->evaluate(), -7);
        EXPECT_EQ(container->at(2)->evaluate(), -2);
}
TEST(StrategyTest, PopulateVector) {
	Op* seven = new Op(7);
        Op* negOne = new Op(-1);
        Mult* TreeA = new Mult(seven, negOne);

        Op* negThree = new Op(-3);
        Op* negFive = new Op(-5);
        Add* TreeB = new Add(negThree, negFive);

        Op* six = new Op(6);
        Op* eight = new Op(8);
        Sub* TreeC = new Sub(six, eight);

        VectorContainer* container = new VectorContainer();

        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), -7);
        EXPECT_EQ(container->at(1)->evaluate(), -8);
        EXPECT_EQ(container->at(2)->evaluate(), -2);
}
int main(int argc, char**argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
