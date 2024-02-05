#include <iostream>
#include <vector>
#include <math.h>

double RandomParam(); // Defined in "Common.h"

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

double Cost(double param, double bias)
{
// ouput = input * parametar + bias
    double cost = 0.00;
    for (int i = 0; i < t_data.size(); i++)
    {
        double t_out = t_data[i].input * param + bias;
       
        double diff = t_out - t_data[i].output;
        cost += diff * diff;
    }
    cost /= t_data.size();
    return cost;
}

void Train(double& param, double &bias, const int& itterations)
{
    double eps = 1e-3;
    double rate = 1e-3;

    for (int it= 0; it < itterations; it++)
    {
        if (!(it % 10)) std::cout << ".\n"; // Visualisation of training

        double c = Cost(param, bias);

        double dparam = (Cost(param + eps, bias) - c ) / eps; 
        double dbias = (Cost(param , eps + bias) - c ) / eps;

        param -= rate * dparam;
        bias  -= rate * dbias;
    }
    std::cout << "Parametar value is: " << param << ", Bias value: " << bias << std::endl << std::endl;
    std::cout << "Cost function: " << std::fixed << Cost(param,bias) << std::endl << std::endl;
}

void Test(double& param, double& bias)
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
    
    // Train
    int itterations = 1;
    std::cout << "Before training:\n " << std::endl;

    while (itterations)
    {
        Train(param, bias, itterations);
        Test(param, bias);
        std::cout << "\nEnter training itteration amount (200+, or 0 to EXIT): ";
        std::cin >> itterations;
    }

    std::cout << "\n\n\n\n\n\nPERCEPTRON EXAMPLE OVER.\n---------------------------------" << std::endl;
}



