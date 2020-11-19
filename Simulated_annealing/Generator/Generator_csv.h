#ifndef SIMULATED_ANNEALING_GENERATOR_CSV_H
#define SIMULATED_ANNEALING_GENERATOR_CSV_H
#include <iostream>
#include "../Structures.h"

void GenerateCSV(size_t number_of_processors, size_t number_of_works, std::pair<int, int> time_interval);
InputData ReadCSV();

#endif //SIMULATED_ANNEALING_GENERATOR_CSV_H
