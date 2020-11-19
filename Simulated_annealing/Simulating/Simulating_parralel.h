#ifndef SIMULATED_ANNEALING_SIMULATING_PARRALEL_H
#define SIMULATED_ANNEALING_SIMULATING_PARRALEL_H
#include "Simulating.h"
#include <mutex>
#include <future>


template <class T, class S, class M>
class ParallelSimulating{
private:
    size_t processors_amount;
    size_t temp;
    size_t cores_amount;
    std::vector<size_t> inform;
    std::vector<std::shared_ptr<BaseSolution>> worktask;
    std::mutex writelock;

public:
    ParallelSimulating(size_t procs, std::vector<size_t> data, size_t cores, size_t start_temp): processors_amount(procs),
        temp(start_temp), cores_amount(cores), inform(data) {}

    void InitWorkTask(std::shared_ptr<BaseSolution> best){
        Simulating<T,S,M> sim(inform, cores_amount, temp, best);
        auto sol = sim.SolutionFind()->GetCopy();
        std::lock_guard<std::mutex> lk(writelock);
        worktask.emplace_back(sol);
    };

    std::shared_ptr<BaseSolution> ParralelSolution() {
        std::vector<std::future<void>> tasks(processors_amount);

        std::shared_ptr<BaseSolution> best = nullptr;
        int it=0;
        while (it<10) {
            for (size_t i = 0; i < processors_amount; i++)
                tasks[i] = std::async(std::launch::async, [&best, this](){
                    this->InitWorkTask(best);
                });
            for (auto &task: tasks)
                task.get();
            if (best) {
                auto new_solution = this->GetBestSolution();
                if (new_solution->GetCriterion() < best->GetCriterion()) {
                    best = new_solution->GetCopy();
                    it = 0;
                } else {
                    it++;
                }
            } else {
                best = this->GetBestSolution()->GetCopy();
                it=1;
            }
            tasks.clear();
            tasks.resize(processors_amount);
            worktask.clear();
        }
        return best;
    }


    std::shared_ptr<BaseSolution> GetBestSolution() {
        std::vector <int> allcrit;
        std::shared_ptr<BaseSolution> tst = nullptr;
        for (auto &it: worktask)
            allcrit.emplace_back(it->GetCriterion());

        int max = *std::max_element(allcrit.begin(), allcrit.end());
        for (auto it: worktask) {
            if (it->GetCriterion() == max)
                tst = it->GetCopy();
        }
        return tst;
    }

};


#endif //SIMULATED_ANNEALING_SIMULATING_PARRALEL_H
