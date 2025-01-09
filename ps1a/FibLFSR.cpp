// Copyright 2024 Harishwar Reddy

#include "FibLFSR.hpp"

namespace PhotoMagic {

FibLFSR::FibLFSR(std::string seed) : register_bits(seed) {
    if (seed.length() != 16) {
        throw std::invalid_argument("Seed must be 16 bits long");
    }
    for (char c : seed) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Seed must contain only 0s and 1s");
        }
    }
}

int FibLFSR::step() {
    int new_bit = (register_bits[0] - '0') ^ (register_bits[2] - '0') ^
                  (register_bits[3] - '0') ^ (register_bits[5] - '0');
    register_bits = register_bits.substr(1) + std::to_string(new_bit);
    return new_bit;
}

int FibLFSR::generate(int k) {
    int result = 0;
    for (int i = 0; i < k; ++i) {
        result = (result << 1) | step();
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr) {
    os << lfsr.register_bits;
    return os;
}
}  // namespace PhotoMagic
