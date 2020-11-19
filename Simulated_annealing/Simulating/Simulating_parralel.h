#ifndef SIMULATED_ANNEALING_SIMULATING_PARRALEL_H
#define SIMULATED_ANNEALING_SIMULATING_PARRALEL_H
#include "Simulating.h"
#include <thread>
#include <mutex>


template <class T, class S, class M>
class ParallelSimulating{
private:
    size_t num_procs;
    size_t temp;
    size_t cores_amount;
    std::vector<size_t> inform;
    std::vector<std::shared_ptr<BaseSolution>> worktask;
    std::mutex writelock;

public:
    ParallelSimulating(size_t procs, std::vector<size_t> data, size_t cores, size_t start_temp): num_procs(procs),
        temp(start_temp), cores_amount(cores), inform(data) {}

    void InitWorkTask(std::shared_ptr<BaseSolution> best){
        Simulating<T,S,M> sim(inform, cores_amount, temp, best);
        auto sol = sim.SolutionFind()->GetCopy();
        writelock.lock();
        worktask.emplace_back(sol);
        writelock.unlock();
    };

    std::shared_ptr<BaseSolution> ParralelSolution() {
        std::vector<std::thread> thread_vec(num_procs);
        std::shared_ptr<BaseSolution> best = nullptr;
        int it=0;
        while (it<10) {
            for (size_t i = 0; i < num_procs; i++)
                thread_vec[i] = std::thread(&ParallelSimulating::InitWorkTask, this, best);
            for (auto &th: thread_vec)
                if (th.joinable())
                    th.join();
            if (best) {
                auto new_solution = this->GetBestSolution();
                if (new_solution->CriterionGet() < best->CriterionGet()) {
                    best = new_solution->GetCopy();
                    it = 0;
                } else {
                    it++;
                }
            } else {
                best = this->GetBestSolution()->GetCopy();
                it=1;
            }
            thread_vec.clear();
            thread_vec.resize(num_procs);
            worktask.clear();
        }
        return best;
    }


    std::shared_ptr<BaseSolution> GetBestSolution() {
        std::vector <int> allcrit;
        std::shared_ptr<BaseSolution> tst = nullptr;
        for (auto &it: worktask)
            allcrit.emplace_back(it->CriterionGet());

        int max = *std::max_element(allcrit.begin(), allcrit.end());
        for (auto it: worktask) {
            if (it->CriterionGet() == max)
                tst = it->GetCopy();
        }
        return tst;
    }

};


#endif //SIMULATED_ANNEALING_SIMULATING_PARRALEL_H
