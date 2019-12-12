//
// Created by Playstation 5 on 12/12/2019.
//

#include <Day1.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

std::string Day1::run() {
    std::ifstream file{"Day1.txt"};
    float load;
    std::vector<float> input;
    while(file >> load) {
        input.emplace_back(load);
    }

    return {"Part 1: "+part1(input)+", Part 2: "+part2(input)};
}

std::string Day1::prettyRun() {
    return std::string();
}

std::string Day1::part1(const std::vector<float>& input) {
    float total = 0;
    for(float currentMass : input) {
        total += (std::floor(currentMass/3)-2);
    }
    return std::to_string((int)total);
}

std::string Day1::part2(const std::vector<float>& input) {
    float total = 0;
    for(float mass : input) {
        float currentMass = mass;
        while(currentMass > 0) {
            float calculatedFuel = (std::floor(currentMass/3)-2);
            currentMass = calculatedFuel;
            if(calculatedFuel > 0) {
                total += calculatedFuel;
            }
        }
    }
    return std::to_string((int)total);
}
