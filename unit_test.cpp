#include "gtest/gtest.h"
#include "base.h"
#include "Pow.cpp"
#include "Mult.cpp"
#include "Div.cpp"
#include "Add.cpp"
#include "Sub.cpp"
#include "Rand.cpp"
#include "Op.cpp" 
#include "RandMock.cpp"
#include <iostream>
#include <string>

using namespace std;

TEST(CompositeTest, OpEvaluateInt) {
	Op* Op1 = new Op(1);
	EXPECT_EQ(1.0, Op1->evaluate());
}
TEST(CompositeTest, RandEvaluate) {
	RandMock* x = new RandMock();
	EXPECT_EQ(2.0, x->evaluate());
}
TEST(CompositeTest, OpEvaluateDouble) {
	Op* Op1 = new Op(1.0);
	EXPECT_EQ(1.0, Op1->evaluate());
}
TEST(CompositeTest, OpEvaluateNegative) {
	Op* Op1 = new Op(-1); 
	EXPECT_EQ(-1.0, Op1->evaluate());
} 
TEST(CompositeTest, OpStringifyInt) {
	Op* Op1 = new Op(1);
	EXPECT_EQ("1.000000", Op1->stringify());
} 
TEST(CompositeTest, RandStringify) {
	RandMock* x = new RandMock(); 
	EXPECT_EQ("2.000000", x->stringify());
}
TEST(CompositeTest, OpStringifyDouble) {
	Op* Op1 = new Op(1.0);
	EXPECT_EQ("1.000000", Op1->stringify());
}
TEST(CompositeTest, OpStringifyNegative) {
	Op* Op1 = new Op(-1.0);
	EXPECT_EQ("-1.000000", Op1->stringify());
}
TEST(CompositeTest, PowDoubleOpEvaluate) {
	Op* x = new Op(2.0);
	Op* y = new Op(2.0); 
	Pow* Pow1 = new Pow(x, y); 
	EXPECT_EQ(4.0, Pow1->evaluate()); 
}
TEST(CompositeTest, PowRandOpEvaluate) {
	RandMock* x = new RandMock();
	Op* y = new Op(2.0);
	Pow* Pow1 = new Pow(x, y); 
	EXPECT_EQ(4.0, Pow1->evaluate());
}
TEST(CompositeTest, PowDoubleRandEvaluate) {
	RandMock* x = new RandMock();
	RandMock* y = new RandMock();
	Pow* Pow1 = new Pow(x, y);
	EXPECT_EQ(4.0, Pow1->evaluate()); 
}
TEST(CompositeTest, PowDoublOpStringify) {
	Op* x = new Op(2.0);
        Op* y = new Op(2.0);
        Pow* Pow1 = new Pow(x, y);     
	EXPECT_EQ("2.000000 ^ 2.000000", Pow1->stringify());
}
TEST(CompositeTest, PowRandOpStringify) {
	RandMock* x = new RandMock();
        Op* y = new Op(2.0);
        Pow* Pow1 = new Pow(x, y);
        EXPECT_EQ("2.000000 ^ 2.000000", Pow1->stringify());
}
TEST(CompositeTest, PowDoubleRandStringify) {
	RandMock* x = new RandMock();
        RandMock* y = new RandMock();
        Pow* Pow1 = new Pow(x, y);
        EXPECT_EQ("2.000000 ^ 2.000000", Pow1->stringify());
}
TEST(CompositeTest, MultEvaluate) {
	Op* x = new Op(2.0); 
	Op* y = new Op(2.0); 
	Mult* Mult1 = new Mult(x, y);
	EXPECT_EQ(4.0, Mult1->evaluate());
}
TEST(CompositeTest, MultStringify) {
	Op* x = new Op(2.0);
        Op* y = new Op(2.0);
        Mult* Mult1 = new Mult(x, y);
	EXPECT_EQ("2.000000 * 2.000000", Mult1->stringify()); 
}
TEST(CompositeTest, MultPowOpEvaluate) {
	Op* Op1 = new Op(2.0);
	Op* Op2 = new Op(2.0);
	Pow* Pow1 = new Pow(Op1, Op1); 
	Op* Op3 = new Op(2.0);
	Mult* Mult1 = new Mult(Pow1, Op3);
	EXPECT_EQ(8.0, Mult1->evaluate()); 
}
TEST(CompositeTest, MultPowOpStringify) {
	Op* Op1 = new Op(2.0);
        Op* Op2 = new Op(2.0);
        Pow* Pow1 = new Pow(Op1, Op1);
        Op* Op3 = new Op(2.0);
        Mult* Mult1 = new Mult(Pow1, Op3);
        EXPECT_EQ("4.000000 * 2.000000", Mult1->stringify());	
}
TEST(CompositeTest, MultNegativeOpEvaluate) {
	Op* Op1 = new Op(2.0);
	Op* Op2 = new Op(-2.0);
	Mult* Mult1 = new Mult(Op1, Op2);
	EXPECT_EQ(-4.0, Mult1->evaluate()); 
}
TEST(CompositeTest, MultNegNegEvaluate) {
	Op* Op1 = new Op(-2.0); 
	Op* Op2 = new Op(-2.0); 
	Mult* Mult1 = new Mult(Op1, Op2);
	EXPECT_EQ(4.0, Mult1->evaluate()); 
}
TEST(CompositeTest, MultNegativeOpStringify) {
        Op* Op1 = new Op(2.0);
        Op* Op2 = new Op(-2.0);
        Mult* Mult1 = new Mult(Op1, Op2);
        EXPECT_EQ("2.000000 * -2.000000", Mult1->stringify());
}
TEST(CompositeTest, MultNegNegStringify) {
        Op* Op1 = new Op(-2.0);
        Op* Op2 = new Op(-2.0);
        Mult* Mult1 = new Mult(Op1, Op2);
        EXPECT_EQ("-2.000000 * -2.000000", Mult1->stringify());
}
TEST(CompositeTest, DivOpEvaluate) {
	Op* x = new Op(2.0);
	Op* y = new Op(2.0); 
	Div* Div1 = new Div(x, y);
	EXPECT_EQ(1.0, Div1->evaluate());
}
TEST(CompositeTest, DivOpStringify) {
	Op* x = new Op(2.0);
        Op* y = new Op(2.0);
        Div* Div1 = new Div(x, y);
        EXPECT_EQ("2.000000 / 2.000000", Div1->stringify());
}
TEST(CompositeTest, DivMultOpEvaluate) {
	Op* x = new Op(2.0);
	Op* y = new Op(2.0);
	Mult* Mult1 = new Mult(x, y);
	Op* z = new Op(2.0);
	Div* Div1 = new Div(Mult1, z); 
	EXPECT_EQ(2.0, Div1->evaluate());
}
TEST(CompositeTest, DivMultOpStringify) {
	Op* x = new Op(2.0);
        Op* y = new Op(2.0);
        Mult* Mult1 = new Mult(x, y);
        Op* z = new Op(2.0);
        Div* Div1 = new Div(Mult1, z);
        EXPECT_EQ("4.000000 / 2.000000", Div1->stringify());
}
TEST(CompositeTest, AddEvaluate){
	Op* x = new Op(2.0);
	Op* y = new Op(2.0);
	Add* Add1 = new Add(x,y);
	EXPECT_EQ(4.0, Add1->evaluate());
}
TEST(CompositeTest, AddStringify){
	Op * x = new Op(2.0);
	Op * y = new Op(2.0);
	Add* Add1 = new Add(x,y);
	EXPECT_EQ("2.000000 + 2.000000", Add1->stringify());
}
TEST(CompositeTest, AddNegEvaluate){
	Op* x = new Op(-2.0);
	Op* y = new Op(1.0);
	Add* Add1 = new Add(x,y);
	EXPECT_EQ(-1.0, Add1->evaluate());
}
TEST(CompositeTest, AddNegStringify){
	Op* x = new Op(-2.0);
	Op* y = new Op(1.0);
	Add* Add1 = new Add(x,y);
	EXPECT_EQ("-2.000000 + 1.000000", Add1->stringify());	
}
TEST(CompositeTest, AddPowEvaluate){
	Op * x = new Op(2.0);
	Op * y = new Op(2.0);
	Pow * Pow1 = new Pow(x,y);
	Op * z = new  Op(2.0);
	Add * Add1 = new Add(Pow1, z);
	EXPECT_EQ(6.0, Add1->evaluate());
}
TEST(CompositeTest, AddPowStringify){
	Op* x = new Op(2.0);
	Op* y = new Op(2.0);
	Pow* Pow1 = new Pow(x,y);
	Op* z = new  Op(2.0);
	Add* Add1 = new Add(Pow1, z);
	EXPECT_EQ("4.000000 + 2.000000" , Add1->stringify());
}
TEST(CompositeTest, AddMultEvaluate){
	Op * x = new Op(2.0);
	Op * y = new Op(5.0);
	Mult * Mult1 = new Mult(x,y);
	Op * z = new Op(2.0);
	Add * Add1 = new Add(Mult1, z);
	EXPECT_EQ(12.0, Add1->evaluate());
}
TEST(CompositeTest, AddMultStringify){
	Op* x = new Op(2.0);
	Op* y = new Op(5.0);
	Mult * Mult1 = new Mult(x,y);
	Op* z = new Op(2.0);
	Add* Add1 = new Add(Mult1, z);
	EXPECT_EQ("10.000000 + 2.000000" , Add1->stringify());
}
TEST(CompositeTest, SubEvaluate){
	Op * x = new Op(2.0);
	Op * y = new Op(2.0);
	Sub * Sub1 = new Sub(x,y);
	EXPECT_EQ(0.0, Sub1 -> evaluate());
}
TEST(CompositeTest, SubStringify){
	Op * x = new Op(2.0);
	Op * y = new Op(2.0);
	Sub * Sub1 = new Sub(x,y);
	EXPECT_EQ("2.000000 - 2.000000" , Sub1 -> stringify());	
}
TEST(CompositeTest, SubPowEvaluate){
	Op* x = new Op(2.0);
	Op* y = new Op(2.0);
	Pow* Pow1 = new Pow(x,y);
	Op* z = new  Op(2.0);
	Sub* Sub1 = new Sub(Pow1, z);
	EXPECT_EQ(2.0, Sub1->evaluate());
}

TEST(CompositeTest, SubPowStringify){
	Op* x = new Op(2.0);
	Op* y = new Op(2.0);
	Pow* Pow1 = new Pow(x,y);
	Op* z = new  Op(2.0);
	Sub* Sub1 = new Sub(Pow1, z);
	EXPECT_EQ("4.000000 - 2.000000" , Sub1->stringify());
}



int main(int argc, char**argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
