#ifndef GENETIC_ALGORITHM_GENETIC_HPP
#define GENETIC_ALGORITHM_GENETIC_HPP
#define AREA_SIZE 50
#define POPULATION_SIZE 16
#define AMOUNT_OF_STEPS 100

#include "iostream"
#include "vector"


using area = std::vector <std::vector <int>>;

class AbstractEstimation {
public:
    virtual int LifeStart(area &gen, size_t step_amount, bool is_last = false) = 0;
    virtual  std::vector <std::pair<area,int>> GetEstimation(std::vector <area> &gen) = 0;
    AbstractEstimation() = default;
    virtual ~AbstractEstimation() = default;
};

class AbstractSelection {
public:
    virtual std::vector <area> GetSelection(std::vector <std::pair<area,int>> solution,
                                          size_t tournament_size, size_t amount) = 0;
    AbstractSelection() = default;
    virtual ~AbstractSelection() = default;
};

class AbstractCrossing {
public:
    virtual void GetCrossing(std::vector <area> &solution) = 0;
    AbstractCrossing() = default;
    virtual ~AbstractCrossing() = default;
};

class AbstractMutation {
public:
    virtual void GetMutation(std::vector <area> &solution, float probability_of_mutation) = 0;
    AbstractMutation() = default;
    virtual ~AbstractMutation() = default;
};


class Estimation: public AbstractEstimation
{
private:
    size_t NeighborReaction(area &gen, std::pair<size_t, size_t> pos);
public:
    int LifeStart(area &gen, size_t step_amount, bool is_last = false);
    std::vector <std::pair<area,int>> GetEstimation(std::vector <area> &gen);
    Estimation() = default;
    ~Estimation() = default;
};

class Selection: public AbstractSelection {
public:
    std::vector <area> GetSelection(std::vector <std::pair<area,int>> solution, size_t tournament_size, size_t amount);
    Selection() = default;
    ~Selection() = default;
};

class Crossing: public AbstractCrossing {
public:
    void GetCrossing(std::vector <area> &solution);
    Crossing() = default;
    ~Crossing() = default;
};

class Mutation: public AbstractMutation {
public:
    void GetMutation(std::vector <area> &solution, float probability_of_mutation);
    Mutation() = default;
    ~Mutation() = default;
};

#endif //GENETIC_ALGORITHM_GENETIC_HPP
