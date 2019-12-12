//
// Created by Playstation 5 on 12/12/2019.
//

#ifndef ADVENTOFCODE_COMPUTER_H
#define ADVENTOFCODE_COMPUTER_H

#include <vector>
#include <string>

class Computer {
public:
    explicit Computer(std::vector<int> memory);
    explicit Computer(const std::string& memoryFile);

    void replace(int index, int value);
    std::vector<int> getMemoryDump();
    std::string memoryToString();
    void resetMemory();

    int run();

private:
    std::vector<int> memory;
    std::vector<int> defaultMemory;
};

#endif //ADVENTOFCODE_COMPUTER_H
