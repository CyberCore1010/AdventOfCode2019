//
// Created by Playstation 5 on 12/12/2019.
//

#include <Day2.h>
#include <Computer.h>

std::string Day2::run() {
    Computer computer{"Day2.txt"};

    computer.replace(1, 12);
    computer.replace(2, 2);

    std::string part1 = "Part 1: ";
    int exitCode = computer.run();
    if(exitCode)
        return "ERROR occurred at operator position ["+std::to_string(exitCode)+"]!";
    else {
        part1 += std::to_string(computer.getMemoryDump()[0]);
    }

    std::string part2{"Part 2: "};

    bool found = false;
    for(int noun = 0; noun < 100; noun++) {
        for(int verb = 0; verb < 100; verb++) {
            if(!found) {
                computer.resetMemory();
                computer.replace(1, noun);
                computer.replace(2, verb);
                if(!computer.run()) {
                    if(computer.getMemoryDump()[0] == 19690720) {
                        found = true;
                        part2 += "Found output! noun="+std::to_string(noun)+", verb="+std::to_string(verb)+", Answer = "+std::to_string((100 * noun + verb));
                    }
                }
            }
        }
    }

    return part1 + ", " + part2;
}

std::string Day2::prettyRun() {
    return std::string();
}
