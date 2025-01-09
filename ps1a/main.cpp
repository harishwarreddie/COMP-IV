// Copyright 2024 Harishwar Reddy

#include <iostream>
#include "FibLFSR.hpp"

using PhotoMagic::FibLFSR;

int main() {
    FibLFSR lfsr("1011011000110110");
    std::cout << "Beginning state: " << lfsr << std::endl;
    // Perform some steps
    for (int a = 0; a < 10; ++a) {
        std::cout << "Step " << (a + 1) << ": " << lfsr.step()
        << ", State: " << lfsr << std::endl;
    }
    std::cout << "Generate 10 bits: " << lfsr.generate(10) << std::endl;
    return 0;
}
