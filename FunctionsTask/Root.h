#ifndef MAINFUNCTIONS_ROOT_H
#define MAINFUNCTIONS_ROOT_H

#include "Functions/BaseFunc.h"
#include <cmath>

double getRoot(const std::shared_ptr<BaseFunc>& func, double start, double step, size_t numberOfIteration) {
    double x2 = 0;
    auto x1 = start;
    //std::cout << " root started: ";
    for (size_t i = 0; i < numberOfIteration; ++i) {
        auto temp = x1;
        //std::cout <<  temp << " ";
        //std :: cout << "Possibly 0 = " << abs(2 * (*func)(x1) * func->GetDerivativeAtPoint(x1) - 2 * (*func)(x2) * func->GetDerivativeAtPoint(x2)) << std::endl;
        x1 = x1 - step * fabs(x1 - x2)
                / fabs(2 * (*func)(x1) * func->GetDerivativeAtPoint(x1) - 2 * (*func)(x2) * func->GetDerivativeAtPoint(x2))
                * 2 * (*func)(x1) * func->GetDerivativeAtPoint(x1);
        x2 = temp;
    }
    //std::cout << std::endl;
    return x1;
}

#endif //MAINFUNCTIONS_ROOT_H
