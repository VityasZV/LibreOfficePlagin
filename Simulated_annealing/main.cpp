#include "Temperature/Temperature.h"
#include "Mutation/Mutation.h"
#include "Structures.h"
#include "Simulating/Simulating.h"
#include "Simulating/Simulating_parralel.h"
#include "Generator/Generator_csv.h"
#include <chrono>

template <typename T>
auto SerialWork(std::vector<size_t> data, size_t cores, size_t start_temp, std::shared_ptr<BaseSolution> sol = nullptr) -> void {
    Simulating<T, Solution, Mutation> sim(data, cores, start_temp, sol);
    sim.SolutionFind()->PrintResults();
}

template <typename T>
auto ParallelWork(size_t procs, std::vector<size_t> data, size_t cores, size_t start_temp) -> void {
    ParallelSimulating<T, Solution, Mutation> sim(procs, data, cores, start_temp);
    sim.ParralelSolution()->PrintResults();
}

int main(int argc, char *argv[]) {
    try {
        srand(time(0));
        std::cout << "Select a working temperature_mode (0 - serial, 1 - work_mode)" << std::endl;
        int int_work_mode, int_temperature_mode;
        std::cin >> int_work_mode;
        std::cout << "Choose a temperature mode (0 - Boltzman, 1 - Cauchy, else Mixed)" << std::endl;
        std::cin >> int_temperature_mode;
        auto work_mode = IntToWorkMode[int_work_mode];
        auto temperature_mode = IntToTemperatureMode[int_temperature_mode];
        InputData data = ReadCSV();
        auto start_time = std::chrono::high_resolution_clock::now();
        switch (work_mode) {
            case WorkMode::Serial:
                switch (temperature_mode) {
                    case TemperatureMode::Boltzman:
                        SerialWork<Boltzman>(data.data, data.number_of_processors, 100);
                        break;
                    case TemperatureMode::Cauchy:
                        SerialWork<Cauchy>(data.data, data.number_of_processors, 100);
                        break;
                    case TemperatureMode::Mixed:
                        SerialWork<Mixed>(data.data, data.number_of_processors, 100);
                        break;
                    default:
                        throw std::runtime_error("incorrect temperature mode");
                }
                break;
            case WorkMode::Parallel:
                std::cout << "Please, set amount of threads:" << std::endl;
                int amount_of_threads;
                std::cin >> amount_of_threads;
                start_time = std::chrono::high_resolution_clock::now();
                switch (temperature_mode) {
                    case TemperatureMode::Boltzman:
                        ParallelWork<Boltzman>(amount_of_threads, data.data, data.number_of_processors, 100);
                        break;
                    case TemperatureMode::Cauchy:
                        ParallelWork<Cauchy>(amount_of_threads, data.data, data.number_of_processors, 100);
                        break;
                    case TemperatureMode::Mixed:
                        ParallelWork<Mixed>(amount_of_threads, data.data, data.number_of_processors, 100);
                        break;
                    default:
                        throw std::runtime_error("incorrect temperature mode");
                }
                break;
            default:
                throw std::runtime_error("incorrect work mode");
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> worktime = end_time - start_time;
        std::cout << "Program worktime - " << worktime.count() / 1000 << "s" << std::endl;
    }
    catch (const std::exception &er) {
        std::cout << "ERROR:";
        std::cout << er.what() << std::endl;
    }
    return 0;
}
