#ifndef SIMULATED_ANNEALING_TEMPERATURE_H
#define SIMULATED_ANNEALING_TEMPERATURE_H
#include <math.h>

class Temperature
{
protected:
    double temp;
    int it = 0;
public:
    Temperature(double temperature=0) : temp(temperature) {}

    virtual double getTemp() = 0;

    virtual ~Temperature() = default;
};

class Boltzman: public Temperature
{
public:
    Boltzman(double temp=0): Temperature(temp) {}

    virtual double getTemp();
};

class Cauchy: public Temperature
{
public:
    Cauchy(double temp=0): Temperature(temp) {}

    virtual double getTemp();
};

class Mixed: public Temperature //заменить на смешанный mixed
{
public:
    Mixed(double temp=0): Temperature(temp) {}

    virtual double getTemp();
};

#endif //SIMULATED_ANNEALING_TEMPERATURE_H
