#include <iostream>
#include <vector>

#include "NN.h"
#include "NN_Utils.h"


double Forward(const Model& model, const double& inpBit1, const double& inpBit2)
{
    //input layer
    double outOr = Sigmoid(model.neurons[0].P1 * inpBit1 + model.neurons[0].P2 * inpBit2 + model.neurons[0].B); // First neuron
    double outNand = Sigmoid(model.neurons[1].P1 * inpBit1 + model.neurons[1].P2 * inpBit2 + model.neurons[1].B); // Second neuron

    //second layer 
    double outAnd = Sigmoid(model.neurons[2].P1 * outOr + model.neurons[2].P2 * outNand + model.neurons[2].B); // Third neuron

    //third (output) layer
    return outAnd;
}

double ModelCost(const Model& model)
{
    double cost = 0.00;

    for (int i = 0; i < t_dataXOR.size(); i++)
    {
        // Calculating model ouput
        double m_out = Forward(model, t_dataXOR[i].bit1, t_dataXOR[i].bit2);
        // Calculating model error
        double diff = m_out - t_dataXOR[i].outBit;
        // Adding it to calculate average
        cost += diff * diff; // Squaring it in case its negative
    }
    cost /= t_dataXOR.size(); // Avg model cost

    return cost;
}

void TrainModel(Model& model, int itterations)
{
    double eps = 1e-2; // Rate of parametar change
    double rate = 1e-1; // Rate of training

    for (int j = 0; j < itterations; j++)
    {
		if (!(j % 100)) std::cout << ".\n"; // Visualisation of training
        // this is called finite difference (simple version of derivation)
        for (int i = 0; i < NEURONS_COUNT; i++)
        {
            double c = ModelCost(model);
            model.neurons[i].P1 += eps;
            double learn = (ModelCost(model) - c) / eps;
            model.neurons[i].P1 -= eps;
            model.neurons[i].P1 -= learn * rate;

            c = ModelCost(model);
            model.neurons[i].P2 += eps;
            learn = (ModelCost(model) - c) / eps;
            model.neurons[i].P2 -= eps;
            model.neurons[i].P2 -= learn * rate;

            c = ModelCost(model);
            model.neurons[i].B += eps;
            learn = (ModelCost(model) - c) / eps;
            model.neurons[i].B -= eps;
            model.neurons[i].B -= learn * rate;
        }
    }
}

void TestModel(const Model& model)
{
    for (int i = 0; i < t_dataXOR.size(); i++)
    {
        double t_out = Forward(model, t_dataXOR[i].bit1, t_dataXOR[i].bit2);
        std::cout << "Model prediction: " << t_out << ", Correct value: " << t_dataXOR[i].outBit << std::endl;
    }
}


void Main_NeuralNet()
{
    std::cout << "NEURAL NET EXAMPLE\n" << std::endl;
    Model model;
    
    RandomiseModel(model);
    PrintModel(model);
    std::cout << "\nModels' Cost function: " << ModelCost(model) << "\n\n";
    TestModel(model);

    int itterations = 1;
    while (itterations)
    {
        std::cout << "\nEnter training itteration amount(1000+): ";
        std::cin >> itterations;
    
        TrainModel(model, itterations);
        PrintModel(model);
        std::cout << "\nModel's Cost function: " << std::fixed << ModelCost(model) << "\n\n";
        TestModel(model);  
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
