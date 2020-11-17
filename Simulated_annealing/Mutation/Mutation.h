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

    auto virtual InitSolution(size_t cores) -> std::shared_ptr<Solution> = 0;

    auto virtual GetSolution(std::shared_ptr<BaseSolution> solution) -> std::shared_ptr<BaseSolution> = 0;

    virtual ~BaseMutation() = default;
};


class Mutation : public BaseMutation {

public:
    Mutation(std::vector <size_t> input_data = {}) : BaseMutation(input_data) {}

    auto virtual GetSolution(std::shared_ptr<BaseSolution> solution) -> std::shared_ptr<BaseSolution> override;

    auto virtual InitSolution(size_t cores) -> std::shared_ptr<Solution> override;
};

#endif //SIMULATED_ANNEALING_MUTATION_H
