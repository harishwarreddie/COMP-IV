//  CopyRight 2024 Harishwar Reddy Erri
#include <iostream>
#include <string>
#include "EDistance.hpp"
#include <SFML/System.hpp>

int main(int argc, const char* argv[]) {
    sf::Clock clock;
    sf::Time t;

    std::string string1, string2;
    std::cin >> string1 >> string2;
    EDistance editDistance(string1, string2);
    int distance = editDistance.calculateDistance();
    std::cout << "Edit distance = " << distance << std::endl;
    std::string alignment = editDistance.computeAlignment();
    std::cout << alignment << std::endl;
    double memoryUsageMB = editDistance.calculateMemoryUsageMB();
    std::cout << "Memory used = " << memoryUsageMB
    << " MB" << std::endl;
    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds()
              << " seconds \n" << std::endl;

    return 0;
}
