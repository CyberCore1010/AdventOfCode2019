//
// Created by Playstation 5 on 12/12/2019.
//

#include <Computer.h>
#include <fstream>
#include <sstream>

Computer::Computer(const std::string& memoryFile) {
    std::ifstream file{memoryFile};
    std::string stringOfFile;
    file >> stringOfFile;
    std::istringstream stringStream{stringOfFile};

    std::vector<int> input;
    std::string tokenInt;
    while(std::getline(stringStream, tokenInt, ',')) {
        int intValue;
        std::istringstream tokenIntStream{tokenInt};
        tokenIntStream >> intValue;
        input.emplace_back(intValue);
    }

    this->memory = input;
    defaultMemory = memory;
}

Computer::Computer(std::vector<int> memory) {
    this->memory = memory;
    defaultMemory = memory;
}

void Computer::replace(int index, int value) {
    memory[index] = value;
}

std::vector<int> Computer::getMemoryDump() {
    return memory;
}

std::string Computer::memoryToString() {
    std::string output = "{";
    for(int number : memory) {
        output += std::to_string(number);
        output += ",";
    }
    output[output.length()-1] = '}';

    return output;
}

void Computer::resetMemory() {
    memory = defaultMemory;
}

int Computer::run() {
    int currentAddress = 0;

    int operatorCode = memory[currentAddress];
    while(operatorCode != 99) {
        int firstParameter = memory[currentAddress + 1];
        int secondParameter = memory[currentAddress + 2];
        int thirdParameter = memory[currentAddress + 3];

        switch(operatorCode) {
            case 1: //Addition
                memory[thirdParameter] = (memory[firstParameter] + memory[secondParameter]);
                break;

            case 2: //Multiplication
                memory[thirdParameter] = (memory[firstParameter] * memory[secondParameter]);
                break;

            default: //ERROR
                return currentAddress;
        }

        currentAddress += 4;
        operatorCode = memory[currentAddress];
    }

    return 0;
}
