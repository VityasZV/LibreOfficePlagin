#include "gtest/gtest.h"
#include "../Functions/BaseFunc.h"
#include "../Functions/FuncFactory.h"

class PolynomialTests: public ::testing::Test {
public:
    std::shared_ptr<BaseFunc> a, b, c, d, e;
    void SetUp( ) {
        FuncFactory factory;
        a = factory.create("polynomial", 0);
        b = factory.create("polynomial", {0, 1});
        c = factory.create("polynomial", {-1, -1, 2, -2, 0, 1});
        d = factory.create("ident", {1, 0, 1});
        e = factory.create("const", 1.456);
    }

    void TearDown( ) {
        // code to run after each test;
        // can be used instead of a destructor,
        // but exceptions can be handled in this function only
    }

};

TEST_F(PolynomialTests, ToStringTest) {
    EXPECT_STREQ(a->ToString().c_str(), "0");
    EXPECT_STREQ(b->ToString().c_str(), "x");
    EXPECT_STREQ(c->ToString().c_str(), "-1-x+2x^2-2x^3+x^5");
    EXPECT_STREQ(d->ToString().c_str(), "x");
    EXPECT_STREQ(e->ToString().c_str(), "1.456");
}

TEST_F(PolynomialTests, OperatorParenthesesTest) {
    EXPECT_DOUBLE_EQ((*a)(1), 0);
    EXPECT_DOUBLE_EQ((*a)(123), 0);
    EXPECT_DOUBLE_EQ((*b)(1), 1);
    EXPECT_DOUBLE_EQ((*b)(123), 123);
    EXPECT_DOUBLE_EQ((*c)(1), -1);
    EXPECT_DOUBLE_EQ((*c)(0), -1);
    EXPECT_DOUBLE_EQ((*c)(-1), 3);
    EXPECT_DOUBLE_EQ((*d)(-1), -1);
    EXPECT_DOUBLE_EQ((*d)(-123), -123);
    EXPECT_DOUBLE_EQ((*e)(-1), 1.456);
    EXPECT_DOUBLE_EQ((*e)(-123), 1.456);
}

TEST_F(PolynomialTests, DerivativesTest) {
    EXPECT_DOUBLE_EQ(a->GetDerivativeAtPoint(0), 0);
    EXPECT_DOUBLE_EQ(a->GetDerivativeAtPoint(34), 0);
    EXPECT_DOUBLE_EQ(b->GetDerivativeAtPoint(34), 1);
    EXPECT_DOUBLE_EQ(b->GetDerivativeAtPoint(34), 1);
    EXPECT_DOUBLE_EQ(c->GetDerivativeAtPoint(1), 2);
    EXPECT_DOUBLE_EQ(c->GetDerivativeAtPoint(0), -1);
    EXPECT_DOUBLE_EQ(c->GetDerivativeAtPoint(-1), -6);
}