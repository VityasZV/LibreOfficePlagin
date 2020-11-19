#ifndef SIMULATED_ANNEALING_STRUCTURES_H
#define SIMULATED_ANNEALING_STRUCTURES_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <memory>

enum class WorkMode {
    Serial,
    Parallel
};

enum class TemperatureMode {
    Boltzman,
    Cauchy,
    Mixed
};

static auto IntToWorkMode = []() {
    std::vector<std::map<int, WorkMode>::value_type> values{
            std::map<int, WorkMode>::value_type(0, WorkMode::Serial),
            std::map<int, WorkMode>::value_type(1, WorkMode::Parallel),
    };
    return std::map<int, WorkMode>(values.begin(), values.end());
}();

static auto IntToTemperatureMode = []() {
    std::vector<std::map<int, TemperatureMode>::value_type> values{
            std::map<int, TemperatureMode>::value_type(0, TemperatureMode::Boltzman),
            std::map<int, TemperatureMode>::value_type(1, TemperatureMode::Cauchy),
            std::map<int, TemperatureMode>::value_type(2, TemperatureMode::Mixed),
    };
    return std::map<int, TemperatureMode>(values.begin(), values.end());
}();


struct InputData{
    size_t number_of_processors = 0;
    size_t number_of_works = 0;
    std::vector <size_t> data = {};
};

class SingleLoad {
private:
    std::vector<size_t> load;
public:
    SingleLoad() = default;

    SingleLoad(std::vector<size_t> data) {
        load.clear();
        load = data;
    }

    auto GetVec() const -> std::vector<size_t> {
        return load;
    }

    auto Out() -> void {
        for (auto& it: load) {
            std::cout << it << std::endl;
        }
    }

    auto GetLen() const -> size_t {
        size_t current = 0;
        for (auto & it : load)
            current += it;
        return current;
    }

    auto ShowElements() const -> void  {
        for (auto &it : load) {
            std::cout << it << " ";
        }
    }

    auto Clear() -> void{
        load.clear();
    }

    auto WorkloadAdd(size_t size) -> void{
        load.emplace_back(size);
    }

    auto WorkloadRandomDelete() -> size_t {
        size_t position = rand() % load.size();
        size_t command = load[position];
        load.erase(load.begin() + position);
        return command;
    }

    auto Empty() const -> bool {
        return load.empty();
    }

    ~SingleLoad(){};
};

class BaseSolution{
protected:
    std::unordered_map <size_t, SingleLoad> global_loading;
    size_t amount;
public:
    BaseSolution(size_t cores = 0) {
        amount=cores;
        for (size_t i=0; i<amount; i++)
            global_loading[i] = SingleLoad();
    }

    BaseSolution(size_t cores, const std::unordered_map<size_t, SingleLoad> &loading) {
        amount = cores;
        for (size_t i=0; i<amount; i++)
            global_loading[i] = SingleLoad(loading.at(i).GetVec());
    }

    auto virtual  Insertation(int position, int size) -> void = 0;


    auto virtual GetCriterion() -> int = 0;

    auto virtual CoresAmount() -> int = 0;

    auto virtual RandomPositions(int position) -> int = 0;

    auto virtual EmptyLine(int position) -> bool = 0;

    auto virtual PrintResults() -> void = 0;

    auto virtual GetCopy() -> std::shared_ptr<BaseSolution> = 0;

    virtual ~BaseSolution() = default;

};


class Solution: public BaseSolution{
public:
    Solution(size_t cores = 0) : BaseSolution(cores) {};

    Solution(size_t cores, std::unordered_map<size_t, SingleLoad> loading) : BaseSolution(cores, loading) {};


    auto virtual Insertation(int position, int size) -> void override {
        global_loading[position].WorkloadAdd(size);
    }

    auto virtual GetCriterion() -> int override {
        std::vector<int> loads_len;
        for (size_t i=0;  i<amount; i++)
            loads_len.emplace_back(global_loading[i].GetLen());
        return *max_element(loads_len.begin(), loads_len.end()) - *min_element(loads_len.begin(), loads_len.end());
    }

    auto virtual CoresAmount() -> int override {
        return amount;
    }

    auto virtual RandomPositions(int position) -> int override {
        return global_loading[position].WorkloadRandomDelete();
    }

    auto virtual EmptyLine(int position) -> bool override {
        return global_loading[position].Empty();
    }

    auto virtual  PrintResults() -> void override {
        std::cout << "Answer:" << std::endl;
        for (size_t i=0; i<amount; i++) {
            std::cout << "Process №"<< i << ": " << "Time=" << global_loading[i].GetLen() << " Works:";
            global_loading[i].ShowElements();
            std::cout << std::endl;
        }
        std::cout << "Deviation: " << this->GetCriterion() << std::endl;
    }

    auto virtual GetCopy() -> std::shared_ptr<BaseSolution> override {
        auto copy = std::make_shared<Solution>(amount, global_loading);
        return copy;
    }
};

#endif //SIMULATED_ANNEALING_STRUCTURES_H
