#include <iostream>
#include "Genetic.hpp"
#include "Cycle.hpp"
#include "cmath"
#include <sstream>

int main(int argc, char *argv[]) {
    Cycle c;
    srand(time(0));
    int experiment_number, launch_number;
    experiment_number = std::stoi(argv[1]);
    launch_number = std::stoi(argv[2]);
    float mutation = (1/pow(AREA_SIZE,2))*(pow(1.5, experiment_number));
    c.Start(mutation, experiment_number, launch_number);
    return 0;
}