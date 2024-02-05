#pragma once

const int NEURONS_COUNT = 3;
// MODEL
// Neuron structure
struct Neuron
{
    double P1;
    double P2;
    double B;
};

// Model structure
struct Model
{   
    // First neuron is OR gate, Second NAND, Third AND (or at least we hope so)
    Neuron neurons[NEURONS_COUNT]; 
};


// DATA
// Training Data Structure
struct DataRow
{
    int bit1;
    int bit2;
    int outBit;
};

// Training Data 
std::vector<DataRow> t_dataXOR =
{
    { 0, 0, 0},
    { 0, 1, 1},
    { 1, 0, 1},
    { 1, 1, 0}
};

