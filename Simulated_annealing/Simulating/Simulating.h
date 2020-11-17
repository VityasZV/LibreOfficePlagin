//
// Created by voland on 10.11.2020.
//

#ifndef SIMULATED_ANNEALING_SOLUTION_H
#define SIMULATED_ANNEALING_SOLUTION_H

#include <iostream>
#include <time.h>
#include <variant>
#include "../Temperature/Temperature.h"
#include "../Mutation/Mutation.h"
#include "../Structures.h"


template <class T, class S, class M>
class Simulating {
private:
    BaseSolution *best;
    BaseSolution *solution;
    BaseMutation *result;
    size_t it = 0;
    Temperature *temp_module;
public:
    Simulating(std::vector <size_t> data, size_t cores, size_t start_temp, BaseSolution *sol = nullptr) {
        result = new M(data);
        if (not sol)
            solution = result->InitSolution(cores);
        else
            solution = sol->GetCopy();
        best = solution->GetCopy();
        temp_module = new T(start_temp);
    }
    ~Simulating() {
        delete(result);
        delete(solution);
        delete(temp_module);
        delete(best);
    }

    auto SolutionFind() -> BaseSolution*{
        while (it < 100) {
            double new_temp = temp_module->getTemp();
            for (size_t i = 0; i < 10; i++) {
                BaseSolution* tst = result->GetSolution(solution);
                double diff = tst->CriterionGet() - solution->CriterionGet();

                if (diff < 0) {
                    delete(solution);
                    solution = tst->GetCopy();
                    if (solution->CriterionGet() < best->CriterionGet()) {
                        it=0;
                        delete(best);
                        best = solution->GetCopy();
                    }
                } else {
                    float x = (rand() % 100) / (100 * 1.0);
                    if (exp(-diff / new_temp) > x) {
                        delete(solution);
                        solution = tst->GetCopy();
                    }

                }
                delete(tst);
            }
            it++;
            delete(solution);
            solution = best->GetCopy();
        }
        return best;

    }


};

#endif //SIMULATED_ANNEALING_SOLUTION_H
