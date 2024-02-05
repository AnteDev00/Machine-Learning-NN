#include <iostream>
#include <vector>

#include "NN.h"
#include "NN_Utils.h"

// Core functions
double Forward(const Model& model, const double& inpBit1, const double& inpBit2)
{
    //input layer 
    double outOr = Sigmoid(model.neurons[0].P1 * inpBit1 + model.neurons[0].P2 * inpBit2 + model.neurons[0].B);
    double outNand = Sigmoid(model.neurons[1].P1 * inpBit1 + model.neurons[1].P2 * inpBit2 + model.neurons[1].B);

    //second layer 
    double outAnd = Sigmoid(model.neurons[2].P1 * outOr + model.neurons[2].P2 * outNand + model.neurons[2].B);

    //third (output) layer
    return outAnd;
}

double Cost(const Model& model)
{
    double cost = 0.00;

    for (int i = 0; i < t_dataXOR.size(); i++)
    {
        double m_out = Forward(model, t_dataXOR[i].bit1, t_dataXOR[i].bit2);
        double diff = m_out - t_dataXOR[i].outBit;
        cost += diff * diff;
    }
    cost /= t_dataXOR.size();

    return cost;
}

void Train(Model& model, int itterations)
{
    double eps = 1e-2;
    double rate = 1e-1;

    // this is called finite difference (simple version of derivation)
    for (int j = 0; j < itterations; j++)
    {
        //if(!(j%10)) cout << ".\n";
        
        for (int i = 0; i < NEURONS_COUNT; i++)
        {
            double c = Cost(model);
            model.neurons[i].P1 += eps;
            double learn = (Cost(model) - c) / eps;
            model.neurons[i].P1 -= eps;
            model.neurons[i].P1 -= learn * rate;

            c = Cost(model);
            model.neurons[i].P2 += eps;
            learn = (Cost(model) - c) / eps;
            model.neurons[i].P2 -= eps;
            model.neurons[i].P2 -= learn * rate;

            c = Cost(model);
            model.neurons[i].B += eps;
            learn = (Cost(model) - c) / eps;
            model.neurons[i].B -= eps;
            model.neurons[i].B -= learn * rate;
        }
    }
}

// Utility function
void TestModel(const Model& model)
{
    for (int i = 0; i < t_dataXOR.size(); i++)
    {
        double t_out = Forward(model, t_dataXOR[i].bit1, t_dataXOR[i].bit2);
        std::cout << "Model prediction: " << t_out << ", Correct value: " << t_dataXOR[i].outBit << std::endl;
    }
}



// "Main" function
void Main_NeuralNet()
{
    std::cout << "NEURAL NET EXAMPLE\n" << std::endl;
    Model model;

    RandomiseModel(model);
    PrintModel(model);
    std::cout << "\nModels' Cost function: " << Cost(model) << "\n\n";
    TestModel(model);

    int itterations = 1;
    while (itterations)
    {
        std::cout << "\nEnter training itteration amount(1000+): " << std::endl;
        std::cin >> itterations;
        Train(model, itterations);
       
        PrintModel(model);

        TestModel(model);  

        std::cout << "Model's Cost function: " << std::fixed << Cost(model) << std::endl;
    }
}






// "Final" MODEL PARAMETER WEIGHTS

/*
* //Cost: 0.000001
model.neurons[0].P1 = 6.234007;
model.neurons[0].P2 = 6.228276;
model.neurons[0].B  = -9.541721;
model.neurons[1].P1 = 8.139920;
model.neurons[1].P2 = 8.115377;
model.neurons[1].B  = -3.774236;
model.neurons[2].P1 = -15.928453;
model.neurons[2].P2 = 15.280782;
model.neurons[2].B  = -7.346068;
*/
