//  CopyRight 2024 Harishwar Reddy Erri

#pragma once
#include <string>
#include <algorithm>

class EDistance {
 public:
    EDistance(const std::string &str1, const std::string &str2);
    ~EDistance();
    static int computePenalty(char char1, char char2);
    static int findMin(int a, int b, int c);
    int calculateDistance();
    std::string computeAlignment();
    double calculateMemoryUsageMB();

 private:
    int **distanceMatrix;
    std::string str1;
    std::string str2;
    int len1, len2;
};
