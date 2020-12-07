#ifndef MAINFUNCTIONS_BASEFUNC_H
#define MAINFUNCTIONS_BASEFUNC_H

#include <string>
#include <memory>


class BaseFunc {
public:
    virtual auto ToString() const -> std::string = 0;
    virtual auto GetDerivativeAtPoint(double) const -> double = 0;
    virtual auto operator()(double) const -> double = 0;

    virtual auto copy() const -> std::shared_ptr<BaseFunc> = 0;
};


#endif //MAINFUNCTIONS_BaseFunc_H
