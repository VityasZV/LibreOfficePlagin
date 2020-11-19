#ifndef SIMULATED_ANNEALING_SOLUTION_H
#define SIMULATED_ANNEALING_SOLUTION_H

#include <iostream>
#include <time.h>
#include <variant>
#include "../Temperature/Temperature.h"
#include "../Mutation/Mutation.h"
#include "../Structures.h"
#include <memory>

template <class T, class S, class M>
class Simulating {
private:
    std::shared_ptr<BaseSolution> best;
    std::shared_ptr<BaseSolution> solution;
    std::shared_ptr<BaseMutation> result;
    size_t it = 0;
    std::shared_ptr<Temperature> temp_module;
public:
    Simulating(std::vector<size_t> data, size_t cores, size_t start_temp, std::shared_ptr<BaseSolution> sol = nullptr) {
        result = std::make_shared<M>(data);
        if (not sol)
            solution = result->InitSolution(cores);
        else
            solution = sol->GetCopy();
        best = solution->GetCopy();
        temp_module = std::make_shared<T>(start_temp);
    }
    ~Simulating() {
    }

    auto SolutionFind() -> std::shared_ptr<BaseSolution> {
        while (it < 100) {
            double new_temp = temp_module->getTemp();
            for (size_t i = 0; i < 10; i++) {
                auto tst = result->GetSolution(solution);
                double diff = tst->CriterionGet() - solution->CriterionGet();
                if (diff < 0) {
                    solution = tst->GetCopy();
                    if (solution->CriterionGet() < best->CriterionGet()) {
                        it=0;
                        best = solution->GetCopy();
                    }
                } else {
                    float x = (rand() % 100) / (100 * 1.0);
                    if (exp(-diff / new_temp) > x) {
                        solution = tst->GetCopy();
                    }
                }
            }
            it++;
            solution = best->GetCopy();
        }
        return best;

    }


};

#endif //SIMULATED_ANNEALING_SOLUTION_H
