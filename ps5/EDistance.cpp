//  CopyRight 2024 Harishwar Reddy Erri

#include <iostream>
#include <string>
#include <algorithm>
#include "EDistance.hpp"

EDistance::EDistance(const std::string &str1, const std::string &str2) {
    this->str1 = str1;
    this->str2 = str2;
    if (str1.empty() || str2.empty()) {
        throw std::exception();
    } else {
        len1 = str1.size();
        len2 = str2.size();
        distanceMatrix = new int *[len1 + 1]();
        if (!distanceMatrix) {
            std::cout << "Not enough memory" << std::endl;
            exit(1);
        }
        for (int i = 0; i < len1 + 1; i++) {
            distanceMatrix[i] = new int[len2 + 1]();
        }
        for (int i = 0; i <= len1; i++) {
            distanceMatrix[i][len2] = 2 * (len1 - i);
        }
        for (int j = 0; j <= len2; j++) {
            distanceMatrix[len1][j] = 2 * (len2 - j);
        }
    }
}

int EDistance::calculateDistance() {
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            distanceMatrix[i][j] = findMin(
                distanceMatrix[i + 1][j + 1] +
                computePenalty(str1[i], str2[j]),
                distanceMatrix[i + 1][j] + 2,
                distanceMatrix[i][j + 1] + 2);
        }
    }
    return distanceMatrix[0][0];
}

std::string EDistance::computeAlignment() {
    std::string result;
    int i = 0, j = 0;
    while (i < len1 || j < len2) {
        if (i < len1 && j < len2 && str1[i] == str2[j] && distanceMatrix[i][j]
            == distanceMatrix[i + 1][j + 1]) {
            result += str1[i];
            result += " ";
            result += str2[j];
            result += " 0";
            i++;
            j++;
        } else if (i < len1 && j < len2 && str1[i] != str2[j] &&
            distanceMatrix[i][j] == distanceMatrix[i + 1][j + 1] + 1) {
            result += str1[i];
            result += " ";
            result += str2[j];
            result += " 1";
            i++;
            j++;
        } else if (i < len1 && distanceMatrix[i][j]
            == distanceMatrix[i + 1][j] + 2) {
            result += str1[i];
            result += " - 2";
            i++;
        } else if (j < len2 && distanceMatrix[i][j]
            == distanceMatrix[i][j + 1] + 2) {
            result += "- ";
            result += str2[j];
            result += " 2";
            j++;
        }
        if (i < len1 || j < len2) result += "\n";
    }
    return result;
}

int EDistance::computePenalty(char char1, char char2) {
    auto penaltyLambda = [=]() -> int {
        return (char1 == char2) ? 0 : 1;
    };
    return penaltyLambda();
}

int EDistance::findMin(int a, int b, int c) {
    int A = a, B = b, C = c;
    auto minLambda = [=]() -> int {
        if (A <= B && A <= C) {
            return A;
        } else if (B <= A && B <= C) {
            return B;
        } else {
            return C;
        }
    };
    return minLambda();
}

double EDistance::calculateMemoryUsageMB() {
    return ((len1 + 1) * (len2 + 1) * sizeof(int)) / (1024.0 * 1024.0);
}

EDistance::~EDistance() {
    for (int i = 0; i <= len1; i++) {
        delete[] distanceMatrix[i];
    }
    delete[] distanceMatrix;
}
