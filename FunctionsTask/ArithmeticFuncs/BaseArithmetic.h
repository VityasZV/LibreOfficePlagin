#ifndef MAINFUNCTIONS_BASEARITHMETIC_H
#define MAINFUNCTIONS_BASEARITHMETIC_H

#include "../Functions/BaseFunc.h"

class BaseArithmetic: public BaseFunc {
protected:
    std::shared_ptr<BaseFunc> first_term;
    std::shared_ptr<BaseFunc> second_term;
};

#endif //MAINFUNCTIONS_BASEARITHMETIC_H
