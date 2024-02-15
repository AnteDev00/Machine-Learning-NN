#include <iostream>
#include <vector>
#include <math.h>

extern double RandomParam(); // Defined in "Shared.h"

// Data structure
struct dataPair
{
    int input;
    int output;
};

// Training data
std::vector<dataPair> t_data = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
    {5, 10},
};

double ModelCost(double param, double bias)
{
    double cost = 0.00;
    for (int i = 0; i < t_data.size(); i++)
    {
        // Calculating model ouput
        double t_out = t_data[i].input * param + bias;
        // Calculating model error
        double diff = t_out - t_data[i].output;
        // Adding it to calculate avg
        cost += diff * diff;
    }
    cost /= t_data.size(); // Avg model cost
    return cost;
}

void TrainModel(double& param, double &bias, const int& itterations)
{
    double eps = 1e-3; // Rate of parametar change
    double rate = 1e-3; // Rate of training

    for (int it= 0; it < itterations; it++)
    {
        if (!(it % 10)) std::cout << ".\n"; // "Visualisation" of training

        double c = ModelCost(param, bias);

        double dparam = (ModelCost(param + eps, bias) - c ) / eps;
        double dbias = (ModelCost(param , eps + bias) - c ) / eps;

        param -= rate * dparam;
        bias  -= rate * dbias;
    }
    std::cout << "Parametar value is: " << param << ", Bias value: " << bias << std::endl << std::endl;
    std::cout << "Cost function: " << std::fixed << ModelCost(param,bias) << std::endl << std::endl;
}

void TestModel(double& param, double& bias)
{
    double cost = 0.00;
    for (int i = 0; i < t_data.size(); i++)
    {
        double t_out = t_data[i].input * param + bias;
        double diff = t_out - t_data[i].output;
        cost += diff * diff;
        std::cout << "Model Prediction: " << t_out << " , Actuall value: " << t_data[i].output << std::endl;
    }
    std::cout << "--------------------------------------------------------------------" << std::endl;
}


void Main_Perceptron()
{
    double param = RandomParam();
    double bias = RandomParam();
    
    int itterations = 1;
    std::cout << "Before training:\n " << std::endl;

    while (itterations)
    {
        TrainModel(param, bias, itterations);
        TestModel(param, bias);
        std::cout << "\nEnter training itteration amount (200+, or 0 to EXIT): ";
        std::cin >> itterations;
    }

    std::cout << "\n\n\n\n\n\nPERCEPTRON EXAMPLE OVER.\n---------------------------------" << std::endl;
}



