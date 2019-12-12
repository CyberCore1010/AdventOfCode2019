//
// Created by Playstation 5 on 12/12/2019.
//

#ifndef ADVENTOFCODE_DAY1_H
#define ADVENTOFCODE_DAY1_H

#include <string>
#include <vector>

class Day1 {
public:
    static std::string run();
    static std::string prettyRun();

private:
    static std::string part1(const std::vector<float>& input);
    static std::string part2(const std::vector<float>& input);
};

#endif //ADVENTOFCODE_DAY1_H
