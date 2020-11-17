//
// Created by voland on 10.11.2020.
//

#ifndef SIMULATED_ANNEALING_MUTATION_H
#define SIMULATED_ANNEALING_MUTATION_H

#include "../Structures.h"
#include <random>



class BaseMutation {
protected:
    std::vector <size_t> input;
public:
    BaseMutation(std::vector<size_t> input_data = {}) {
        input = input_data;
    }

    virtual Solution* InitSolution(size_t cores) = 0;

    virtual BaseSolution* GetSolution(BaseSolution *solution) = 0;

    virtual ~BaseMutation() = default;
};


class Mutation : public BaseMutation {

public:
    Mutation(std::vector <size_t> input_data = {}) : BaseMutation(input_data) {}

    virtual BaseSolution* GetSolution(BaseSolution *solution);

    virtual Solution* InitSolution(size_t cores);
};

#endif //SIMULATED_ANNEALING_MUTATION_H
