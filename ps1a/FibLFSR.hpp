// Copyright 2024 Harishwar Reddy

#ifndef _MNT_F_UML_COMP_4_PS1A_FIBLFSR_HPP_
#define _MNT_F_UML_COMP_4_PS1A_FIBLFSR_HPP_

#include <string>
#include <iostream>

namespace PhotoMagic {

class FibLFSR {
 public:
    explicit FibLFSR(std::string seed);
    int step();
    int generate(int k);
    friend std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr);

 private:
    std::string register_bits;
};
std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr);
}  //  namespace PhotoMagic

#endif  //  _MNT_F_UML_COMP_4_PS1A_FIBLFSR_HPP_
