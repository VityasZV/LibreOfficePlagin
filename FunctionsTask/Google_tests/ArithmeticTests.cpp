#include "gtest/gtest.h"
#include "../Functions/BaseFunc.h"
#include "../Functions/FuncFactory.h"
#include "../NewOperators.h"
#include "../Root.h"
#include <iostream>

class ArithmeticTests : public ::testing::Test {
public:
    FuncFactory factory;
    std::shared_ptr<BaseFunc> a, b, c, d;

    void SetUp() override 
    {
        a = factory.create("polynomial", {1, -2, 1});
        b = factory.create("polynomial", {0, 0, 0, 2});
        c = factory.create("polynomial", {0, 1, 0});
        d = factory.create("exp", -2);
    }
};


TEST_F(ArithmeticTests, SumTests) {
    EXPECT_STREQ((a + b) -> ToString().c_str(), "(+1-2x+x^2)+(+2x^3)");
    EXPECT_DOUBLE_EQ((a+b)->GetDerivativeAtPoint(1), 6);
    EXPECT_DOUBLE_EQ((a+b)->GetDerivativeAtPoint(0), -2);

    EXPECT_THROW(a+"abc", std::logic_error);
    EXPECT_THROW(1 + d, std::logic_error);
}

TEST_F(ArithmeticTests, ProdAndDivOnlyDerivatives) {
    EXPECT_DOUBLE_EQ((c*b)->GetDerivativeAtPoint(1), 8);

    EXPECT_DOUBLE_EQ((b/c)->GetDerivativeAtPoint(1), 4);
    EXPECT_THROW((b/c)->GetDerivativeAtPoint(0), std::logic_error);
}

TEST_F(ArithmeticTests, GetRootTests) {
    auto r = getRoot(a, 10, 0.1, 220);
    std::cout << r << std::endl;
    EXPECT_NEAR(getRoot(a, 10, 0.1, 220), 1, 0.1);
    EXPECT_NEAR(getRoot(b, 10, 0.1, 250), 0, 0.1);
    EXPECT_NEAR(getRoot(c, 10, 0.1, 220), 0, 0.1);

}