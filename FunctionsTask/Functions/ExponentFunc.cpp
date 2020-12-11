#include <math.h>
#include "ExponentFunc.h"

ExponentFunc::ExponentFunc(std::vector<double> v) {
    !v.empty() ? coefficient = v[0] : coefficient = 0;
}

auto ExponentFunc::ToString() const -> std::string {
    if (coefficient == 0) {
        return "1";
    }
    else {
        return "exp(" + std::to_string(coefficient) + "x)";
    }
}

auto ExponentFunc::GetDerivativeAtPoint(double point) const -> double {
    return coefficient * exp(coefficient * point);
}

auto ExponentFunc::operator()(double point) const -> double {
    return exp(coefficient * point);
}

auto ExponentFunc::copy() const -> std::shared_ptr<BaseFunc> {
    return std::make_shared<ExponentFunc>(*this);
}
