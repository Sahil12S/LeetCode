// #include "logger.h"
#include <iostream>
#include <vector>

void printVector(std::vector<int> vec)
{
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}