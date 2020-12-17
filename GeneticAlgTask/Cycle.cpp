#include "Cycle.hpp"

#include "vector"
#include <unistd.h>
#include <fstream>
#include "string"

Cycle::Cycle() {
    //initializing origin population
    area generation;
    std::vector<int> line;
    estimation = std::make_unique<Estimation> ();
    selection = std::make_unique<Selection>();
    crossing = std::make_unique<Crossing>();
    mutation = std::make_unique<Mutation>();
    srand(static_cast<unsigned int>(time(nullptr)));
    for (size_t pop = 0; pop<POPULATION_SIZE; pop++){
        for (size_t i=0; i<AREA_SIZE; i++) {
            for (size_t j = 0; j < AREA_SIZE; j++) {
                line.emplace_back(rand() % 2);
            }
            generation.emplace_back(line);
            line.clear();
        }
        population.emplace_back(generation);
        generation.clear();
    }
}

void Cycle::Start(float mut, int numb, int launch) {

    std::pair <area, int> best = {{}, 0};
    int pos = 0;
    size_t best_it = 0;
    probability_of_mutation = mut;
    number_of_experiment = numb;
    number_of_launch = launch;
    while (best_it < 20) { //our criterion - 20 iterations (changes of populations)
        pos = -1;
        std::vector<std::pair<area, int>> population_estimition = estimation->GetEstimation(population);
        for (size_t i = 0; i < population_estimition.size(); i++) {
            if (population_estimition[i].second > best.second) {
                best.second = population_estimition[i].second;
                pos = i;
            }
        }
        if (pos != -1) {
            best.first = population_estimition[pos].first;
            best_it = 0;
        } else {
            best_it++;
        }
        std::vector<area> new_gen = selection->GetSelection(population_estimition, 5, POPULATION_SIZE / 2);
        crossing->GetCrossing(new_gen);
        mutation->GetMutation(new_gen, probability_of_mutation);
        population = new_gen;
    }
    std::cout << "BEST=" << best.second <<" for" <<  std::endl;
    PrintResult(best.first);
}

void Cycle::WriteInFile(area &best, bool is_after100) {
    std::string filename = !is_after100 ? "series_" + std::to_string(number_of_experiment) + "_run_" + std::to_string(number_of_launch) + ".txt" :
        "series_" + std::to_string(number_of_experiment) + "_run_" + std::to_string(number_of_launch) + "_sol_after100.txt";
    std::ofstream file(filename.c_str());

    for (size_t i = 0; i < best.size(); i++) {
        for (size_t j = 0; j < best[i].size(); j++) {
            auto symb = best[i][j] == 1 ? "X" : "-";
            file << symb;
        }
        file << std::endl;
    }
    file.close();
}

void Cycle::PrintResult(area &best) {
    WriteInFile(best, false);
    for (size_t it = 0; it<100; it++) {
        estimation->LifeStart(best, 1);
    }
    WriteInFile(best, true);
}



