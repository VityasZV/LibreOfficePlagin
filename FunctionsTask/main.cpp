#include <iostream>
#include <vector>
#include "Functions/FuncFactory.h"
#include "NewOperators.h"
#include "Root.h"

using namespace std;

int main() {
    vector<double> v{0, 1};
    vector<double> u{-1, 0, 1};
    auto factory = FuncFactory();
    auto a = factory.create("exp", -1.23);
    auto b = factory.create("poly", v);
    auto c = factory.create("poly", u);

    cout << c -> ToString() << "     " << (*b).GetDerivativeAtPoint(2) << endl
         << a -> ToString() << "     " << (*a).GetDerivativeAtPoint(1) << endl << (c / b) -> GetDerivativeAtPoint(0) << endl;
    cout << getRoot(c, 10, 0.1, 100);
}
