#include <iostream>
#include <vector>
#include "Functions/FuncFactory.h"
#include "NewOperators.h"
#include "Root.h"

using namespace std;

int main() {
    vector<double> v{0, 1};
    vector<double> u{-1, 0, 1};

    vector<double> t = {1, -2, 1};
    vector<double> t1 = {0, 0, 1};
    vector<double> t2 = {0, 0,0,0,1};
    vector<double> t3 = {0, 0, 0, 1};
    vector<double> t4 = {0, -3, 3};
    auto factory = FuncFactory();
    auto a = factory.create("exp", -1.23);
    auto b = factory.create("polynomial", v);
    auto c = factory.create("polynomial", u);

    auto d = factory.create("polynomial", {1, -2, 1});
    auto r = getRoot(d, 10, 0.1, 220);
       std::cout <<  r << std::endl;
       return 0;

    auto d1 = factory.create("polynomial", t1);
    auto d2 = factory.create("polynomial", t2);
    auto d3 = factory.create("polynomial", t3);
    auto d4 = factory.create("polynomial", t4);


    std::cout <<(d1 / d2) -> GetDerivativeAtPoint(1) << std::endl;
   

   std::cout <<  getRoot(d, 10, 0.1, 220) << std::endl;
   std::cout << getRoot(d3, 5, 0.1, 220) << std::endl;
   std::cout << getRoot(d4, 5, 0.1, 220) << std::endl;
  std::cout << (d1 / d2 / d1) -> GetDerivativeAtPoint(1) << std::endl;

    cout << c -> ToString() << "     " << c->GetDerivativeAtPoint(2) << endl
         << a -> ToString() << "     " << a->GetDerivativeAtPoint(1) << endl << (c / a) -> GetDerivativeAtPoint(0) << endl;
}
