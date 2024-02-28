#include <iostream>

#include "library.h"

int main(int argc, char const *argv[]){
    int numberOfDivisions, numberOfDays;
    if (argc != 3) {
        std::cerr << "Must have 2 command line argument (numElectorates and numDays)\n";
        return 1;
    }
    try {
        numberOfDivisions = std::stoi(argv[1]);
        numberOfDays = std::stoi(argv[2]);
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    Generator::generate(numberOfDivisions, numberOfDays);
    Simulation::call().printInfo();
    Simulation::call().votingDay();
    return 0;
}