#include "Temperature/Temperature.h"
#include "Mutation/Mutation.h"
#include "Structures.h"
#include "Simulating/Simulating.h"
#include "Simulating/Simulating_parralel.h"
#include "Generator/Generator_csv.h"
#include <chrono>

#define b = Boltzman;
int main(int argc, char *argv[]) {
    try {
        srand(time(0));
        WorkMode work_mode;
        int th_am;
        TemperatureMode mode;
        std::vector<int> inf = {1, 2, 4, 6, 8, 10, 12, 14, 16};
        std::cout << "Select a working temperature_mode (0 - serial, 1 - work_mode)" << std::endl;
        int int_work_mode, int_temperature_mode;
        std::cin >> int_work_mode;
        std::cout << "Choose a temperature mode (0 - Boltzman, 1 - Cauchy, else Mixed)" << std::endl;
        std::cin >> int_temperature_mode;
        auto work_mode = IntToWorkMode.left[int_work_mode];
        auto temperature_mode = IntToTemperatureMode.left[int_temperature_mode];
        InputDate date = ReadCSV();
        auto start_time = std::chrono::high_resolution_clock::now();
        switch (work_mode) {
            case WorkMode::Serial:
                switch (temperature_mode) {
                    case TemperatureMode::Boltzman:
                        break;
                    case TemperatureMode::Cauchy:
                        break;
                    case TemperatureMode::Mixed:
                        break;
                    default:
                        throw std::runtime_error("incorrect temperature mode");
                }
                break;
            case WorkMode::Parallel:
                break;
            default:
                throw std::runtime_error("incorrect work mode")
        }
        if (not work_mode) {
            if (temperature_mode == 0) {
                Simulating<Boltzman, Solution, Mutation> sim(date.data, date.proc_num, 100);
                sim.SolutionFind()->PrintResults();
            } else if (temperature_mode == 1) {
                Simulating<Cauchy, Solution, Mutation> sim(date.data, date.proc_num, 100);
                sim.SolutionFind()->PrintResults();
            } else {
                Simulating<Mixed, Solution, Mutation> sim(date.data, date.proc_num, 100);
                sim.SolutionFind()->PrintResults();
            }
        } else {
            std::cout << "Please, print amoint of threads:" << std::endl;
            std::cin >> th_am;
            if (temperature_mode == 0) {
                ParallelSimulating<Boltzman, Solution, Mutation> sim1(th_am, date.data, date.proc_num, 100);
                sim1.ParralelSolution()->PrintResults();
            } else if (temperature_mode == 1) {
                ParallelSimulating<Cauchy, Solution, Mutation> sim1(th_am, date.data, date.proc_num, 100);
                sim1.ParralelSolution()->PrintResults();
            } else {
                ParallelSimulating<Mixed, Solution, Mutation> sim1(th_am, date.data, date.proc_num, 100);
                sim1.ParralelSolution()->PrintResults();
            }

            //

        }
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> worktime = end_time - start_time;
        std::cout << "Program worktime - " << worktime.count() / 1000 << "s" << std::endl;
    }
    catch (const std::exception &er) {
        std::cout << er.what();
    }
    return 0;
}
