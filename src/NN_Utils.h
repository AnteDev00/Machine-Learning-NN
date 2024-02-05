#pragma once
#include "NN.h"
#include <iostream>

// Utilities
double RandomParam(); // Defined in Commmon.h

void RandomiseModel(Model& model)
{
    for (int i = 0; i < NEURONS_COUNT; i++)
    {
        model.neurons[i].P1 = RandomParam();
        model.neurons[i].P2 = RandomParam();
        model.neurons[i].B = RandomParam();
    }
}

void PrintModel(const Model& model)
{
    std::cout << "Model weights:\n";
    for (int i = 0; i < NEURONS_COUNT; i++)
    {
        printf("   model.neurons[%d].P1 = %f;\n", i, model.neurons[0].P1);
        printf("   model.neurons[%d].P2 = %f;\n", i, model.neurons[0].P2);
        printf("   model.neurons[%d].B  = %f;\n", i, model.neurons[0].B);
    }
}

inline double Sigmoid(const double& x)
{
    return 1.0 / (1.0 + std::exp(-x));
}
