#include "gtest/gtest.h"
#include "../Functions/BaseFunc.h"
#include "../Functions/FuncFactory.h"
#include "../NewOperators.h"
#include "../Root.h"


class ArithmeticTests : public ::testing::Test {
public:
    FuncFactory factory;
    std::shared_ptr<BaseFunc> a, b, c, d, e, f;

    void SetUp() override 
    {
        a = factory.create("polynomial", {1, -2, 1});
        b = factory.create("polynomial", {0, 0, 0, 2});
        c = factory.create("polynomial", {0, 1, 0});
        d = factory.create("exp", -2);
        e = factory.create("power", -3);
        f = factory.create("polynomial", {-1, 0, 1});
    }
};


TEST_F(ArithmeticTests, SumTests) {
    EXPECT_STREQ((a + b) -> ToString().c_str(), "(1-2x+x^2)+(2x^3)");
    EXPECT_STREQ((a + e) -> ToString().c_str(), "(1-2x+x^2)+(x^(-3))");
    EXPECT_STREQ((d + e) -> ToString().c_str(), "(exp(-2x))+(x^(-3))");

    EXPECT_DOUBLE_EQ((*(a+b))(1), 2);
    EXPECT_DOUBLE_EQ((*(a+b))(0), 1);
    EXPECT_DOUBLE_EQ((*(a+b))(2), 17);

    EXPECT_DOUBLE_EQ((a+b)->GetDerivativeAtPoint(1), 6);
    EXPECT_DOUBLE_EQ((a+b)->GetDerivativeAtPoint(0), -2);
    EXPECT_DOUBLE_EQ((a+b)->GetDerivativeAtPoint(2), 26);

    EXPECT_THROW(a+"abc", std::logic_error);
    EXPECT_THROW(1 + d, std::logic_error);
}

TEST_F(ArithmeticTests, ProdAndDivOnlyDerivatives) {
    EXPECT_DOUBLE_EQ((c*b)->GetDerivativeAtPoint(1), 8);
    EXPECT_DOUBLE_EQ((c*b)->GetDerivativeAtPoint(0), 0);
    EXPECT_DOUBLE_EQ((c*b)->GetDerivativeAtPoint(2), 64);

    EXPECT_DOUBLE_EQ((b/c)->GetDerivativeAtPoint(1), 4);
    EXPECT_THROW((b/c)->GetDerivativeAtPoint(0), std::logic_error);
    EXPECT_DOUBLE_EQ((b/c)->GetDerivativeAtPoint(2), 8);
}

TEST_F(ArithmeticTests, GetRootTests) {
    EXPECT_NEAR(getRoot(a, 10, 0.1, 220), 1, 0.1);
    EXPECT_NEAR(getRoot(b, 10, 0.1, 250), 0, 0.1);
    EXPECT_NEAR(getRoot(c, 10, 0.1, 220), 0, 0.1);
    EXPECT_NEAR(getRoot(f, 10, 0.1, 100), 1, 0.1);
    EXPECT_NEAR(getRoot(f, -10, 0.1, 100), -1, 0.1);

}