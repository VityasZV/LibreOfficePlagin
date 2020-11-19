#include <iostream>
#include <random>
#include <time.h>
#include <ctime>
#include <fstream>
#include <string>
#include "../Structures.h"
#include <exception>


void GenerateCSV(size_t number_of_processors, size_t number_of_works, std::pair<int, int> time_interval) {
    srand( time(0));
    std::ofstream input_date;
    input_date.open("input.csv");
    input_date << number_of_processors << ","<< number_of_works << std::endl;
    for (size_t i=0; i< number_of_works; i++)
        input_date << rand() % (time_interval.second - time_interval.first + 1) + time_interval.first << std::endl;
    input_date.close();
}

InputData ReadCSV() {
    std::ifstream input_date;
    std::string line;
    size_t delimeter;
    InputData Result;
    try {
        input_date.open("input.csv");
        getline(input_date, line);
        delimeter = line.find(",");
        Result.number_of_processors = std::stoi(line.substr(0,delimeter+1));
        Result.number_of_works = std::stoi(line.substr(delimeter+1, line.length() - delimeter - 1));
        while (getline(input_date, line)) {
            Result.data.emplace_back(std::stoi(line));
        }
        return Result;
    }
    catch (const std::exception &er){
        std::cout << "Error while reading csv file: " << er.what();
        throw er; 
    }
}