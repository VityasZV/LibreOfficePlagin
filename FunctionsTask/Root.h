#ifndef MAINFUNCTIONS_ROOT_H
#define MAINFUNCTIONS_ROOT_H

#include "Functions/BaseFunc.h"

float getRoot(const std::shared_ptr<BaseFunc>& func, double start, double step, size_t numberOfIteration) {
    double x2 = 0;
    double x1 = start;
    for (size_t i = 0; i < numberOfIteration; ++i) {
        auto temp = x1;
        x1 = x1 - step * abs(x1 - x2)
                / abs(2 * (*func)(x1) * func->GetDerivativeAtPoint(x1) - 2 * (*func)(x2) * func->GetDerivativeAtPoint(x2))
                * 2 * (*func)(x1) * func->GetDerivativeAtPoint(x1);
        x2 = temp;
    }
    return x1;
}

#endif //MAINFUNCTIONS_ROOT_H
