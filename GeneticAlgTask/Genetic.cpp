#include "Genetic.hpp"

#include "random"
#include "set"

size_t Estimation::NeighborReaction(area &gen, std::pair<size_t, size_t> pos){
    size_t reaction = 0;
    int pos_x, pos_y;
    for (int i=-1; i<=1; i++)
        for (int j=-1; j<=1; j++) {
            pos_x = pos.first + i;
            pos_y = pos.second + j;
            if (i == 0 and j == 0)
                //we are just stepped on the same field
                continue;
            if (pos_x >= 0 and pos_y >= 0 and pos_x < AREA_SIZE and pos_y < AREA_SIZE) {
                //check if we are in area of life game
                if (gen[pos_x][pos_y])
                    //checked that neighbour is alive
                    reaction++;
            }
        }
    if (reaction<=1 or reaction>=4)
        //died
        return 0;
    else if (reaction == 2)
        //keep living or still died
        return 1;
    else if (reaction == 3)
        //alived or keep living
        return 2;
}

int Estimation::LifeStart(area &gen, size_t step_amount, bool is_last) {
    area old_generation;
    bool changed = false;
    for (size_t it = 0; it < step_amount; it++) {
        old_generation = gen;
        for (size_t x = 0; x < AREA_SIZE; x++)
            for (size_t y = 0; y < AREA_SIZE; y++) {
                std::pair<size_t, size_t> pos = {x, y};
                size_t neighbor_reaction = NeighborReaction(old_generation, pos);
                auto old_elem = gen[x][y];
                if ((gen[x][y] and neighbor_reaction) or (neighbor_reaction == 2))
                    gen[x][y] = 1;
                else
                    gen[x][y] = 0;
                if (is_last and !changed and gen[x][y] != old_elem)
                    changed = true;
            }

    }

    return int(changed);
}


std::vector <std::pair<area,int>> Estimation::GetEstimation(std::vector <area> &generation) {
    std::vector <area> new_generation = generation;
    std::vector <std::pair<area,int>> result;
    std::vector<int> vector_of_is_changed_flags; // 0 or 1

    for (size_t i=0; i<POPULATION_SIZE; i++){
        LifeStart(new_generation[i], AMOUNT_OF_STEPS - 1);
    }

    for (size_t i=0; i<POPULATION_SIZE; i++){
        vector_of_is_changed_flags.emplace_back(LifeStart(new_generation[i], 1, true));
    }

    int current_alived_fields;
    for (size_t num=0; num<POPULATION_SIZE; num++){
        current_alived_fields = 0;
        for (size_t i = 0; i < new_generation[num].size(); i++) {
            for (size_t j = 0; j < new_generation[num][0].size(); j++) {
                if (new_generation[num][i][j])
                    current_alived_fields++;
            }
        }
        result.emplace_back(std::make_pair(generation[num], !vector_of_is_changed_flags[num] ? -2*AREA_SIZE*AREA_SIZE + current_alived_fields : current_alived_fields));
    }

    return result;
}

std::vector<area> Selection::GetSelection(std::vector <std::pair<area,int>> solution, size_t tournament_size,
                                        size_t amount) {
    std::set <int> random_solutions;
    std::vector <area> result;
    size_t sol_num;
    int best;
    for (size_t tour=0; tour < amount; tour++) {
        random_solutions.clear();
        while (random_solutions.size() != tournament_size) {
            sol_num = rand() % solution.size();
            random_solutions.emplace(sol_num);
        }
        best = -1;
        for (auto &r_s: random_solutions) {
            if (best == -1) {
                best = r_s;
            } else {
                best = solution[best].second > solution[r_s].second ? best : r_s;
            }
        }
        result.emplace_back(solution[best].first);
    }
    return result;
}


void Crossing::GetCrossing(std::vector <area> &solution) {
    size_t first, second, sex_position;
    area new_sol;
    while (solution.size() < POPULATION_SIZE) {
        first = rand() % solution.size();
        do {
            second = rand() % solution.size();
        } while (first != second);
        sex_position = rand() % solution[first].size();
        std::copy(solution[first].begin(), solution[first].begin() + sex_position, std::back_inserter(new_sol));
        std::copy(solution[second].begin() + sex_position, solution[second].end(), std::back_inserter(new_sol));
        solution.emplace_back(new_sol);
        new_sol.clear();
    }
}

void Mutation::GetMutation(std::vector<area> &solution, float probability_of_mutation) {
    float mut;
    for (auto &solution_solo : solution) {
        for (size_t x = 0; x < AREA_SIZE; x++)
            for (size_t y = 0; y < AREA_SIZE; y++) {
                mut = (rand() % 100) / (100 * 1.0);
                if (mut > probability_of_mutation)
                    solution_solo[x][y] = !solution_solo[x][y];
            }
    }
}
