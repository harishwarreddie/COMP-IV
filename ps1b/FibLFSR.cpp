// CopyRight 2024 Harishwar Reddy Erri

#include <math.h>
#include <iostream>
#include <string>
#include "FibLFSR.hpp"

namespace PhotoMagic {
std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr) {
    out << lfsr.rs;
    return out;
}

int FibLFSR::get(char s) {
    if (s == '1') {
        return 1;
    } else if (s == '0') {
        return 0;
    } else {
        return -1;
    }
}

FibLFSR::FibLFSR(const std::string& seed) {
    rs = seed;
}

int FibLFSR::xOP(int y, int z) {
    return y != z;
}

int FibLFSR::step() {
    std::string new_rs = rs.substr(1);
    int value = xOP(get(rs[0]), get(rs[2]));
    value = xOP(value, get(rs[3]));
    value = xOP(value, get(rs[5]));
    rs = new_rs;
    rs += std::to_string(value);
    return value;
}

int FibLFSR::generate(int k) {
    int res = 0;
    for (int i = 0; i < k; i++) {
        int x = step();
        res = (res * 2) + x;
    }
    return res;
}

}  //  namespace PhotoMagic
