#ifndef GENETIC_ALGORITHM_CYCLE_HPP
#define GENETIC_ALGORITHM_CYCLE_HPP
#include "Genetic.hpp"
#include "memory"


class Cycle {
private:
    float probability_of_mutation;
    int number_of_experiment;
    int number_of_launch;

    std::vector<area> population;
    std::unique_ptr<AbstractEstimation> estimation;
    std::unique_ptr<AbstractSelection> selection;
    std::unique_ptr<AbstractCrossing> crossing;
    std::unique_ptr<AbstractMutation> mutation;
public:
    Cycle();
    void Start(float mut, int numb, int launch);
    void WriteInFile(area &best, bool is_after100);
    void PrintResult(area &best);
};




#endif //GENETIC_ALGORITHM_CYCLE_HPP
