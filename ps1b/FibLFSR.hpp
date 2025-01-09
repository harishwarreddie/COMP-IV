//  CopyRight 2024 Harishwar Reddy Erri

#pragma once

#include <iostream>
#include <string>
namespace PhotoMagic {

class FibLFSR {
 public:
    explicit FibLFSR(const std::string& seed);
    int step();
    int generate(int k);
    friend std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr);

 private:
    std::string rs;
    int get(char a);
    int xOP(int y, int z);
};
}  //  namespace PhotoMagic
