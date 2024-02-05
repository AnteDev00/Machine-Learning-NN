#pragma once
#include <random>

// Returns random number between -5 and 5
double RandomParam()
{
    std::random_device rd; //seed
    std::mt19937 gen(rd()); // random engine gen(erator)
    std::uniform_real_distribution<double> dis(-5, 5);
    return dis(gen);
}
