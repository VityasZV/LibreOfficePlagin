#include <math.h>
#include "Temperature.h"


double Boltzman::getTemp() {
    it++;
    return temp/log(1+it);
}

double Cauchy::getTemp() {
    it++;
    return temp/(1+it);
}

double Basic::getTemp() {
    it++;
    return temp * log(1+it)/(1+it);
}

