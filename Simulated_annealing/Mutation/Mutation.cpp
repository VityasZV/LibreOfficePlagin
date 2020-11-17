#include "../Structures.h"
#include "Mutation.h"
#include <random>


auto Mutation::InitSolution(size_t cores) -> Solution* {
    Solution *new_solution = new Solution(cores);
    for (auto &it: input)
        new_solution->Insertation(0, it);
    return new_solution;
}

auto Mutation::GetSolution(BaseSolution *solution) -> BaseSolution* {
    BaseSolution* new_sol = solution->GetCopy();
    size_t pos;
    size_t new_pos;
    do {
        pos = rand() % new_sol->CoresAmount();
    } while (new_sol->EmptyLine(pos));
    int command = new_sol->RandomPositions(pos);
    do {
        new_pos = rand() % new_sol->CoresAmount();
    } while (pos == new_pos);
    new_sol->Insertation(new_pos, command);
    return new_sol;
}