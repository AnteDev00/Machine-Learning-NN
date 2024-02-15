# Machine Learning Project with Neural Networks

## Project Description
The project explores the domain of machine learning through the implementation of neural networks. The project consists of two key examples.

---

## Example 1: Simplest neural network (Perceptron)

The first example introduces the perceptron, the simplest neural network with a single neuron. This network enables the recognition of simple patterns, such as connections between sets of numbers. Visualizations before and after the learning process clearly demonstrate how the model adapts over time.

![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/a1350c8e-3352-4088-a6d1-83f348767fa1)

The goal is for the perceptron to learn the connection between the first set (0,1,2,3,4,5) and the second set (0,2,4,6,8,10), which is essentially multiplying by 2 (and adding nothing).

#
### Before training:
![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/396e103b-4b23-4415-93da-dad3c9e5ca02)
#

As seen, initially, the model multiplies by 3.91 and adds -0.14. Consequently, its predictions are incorrect.
#
### After training:
![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/ba43ed70-9f99-45dc-9481-a74c71a12f4b)

During the learning process, the model reduces the values from 3.91->2 and -0.14->0. 

This is achieved through the Cost function, and the entire goal of the learning process is to minimize the Cost function value, adjusting parameters and improving the model's predictions.
#

### Cost function:
![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/eb179e96-2072-4cec-adfd-660bfcfa7b7b)


---

## Example 2: More Complex Neural Network with more Neurons (Truth tables)

The second example involves connecting multiple neurons to create a more intelligent system.

### Model Structure:
![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/8c72c3ac-6f21-4861-bd39-739e4ac3f38d)

This model, with three connected neurons, demonstrates the ability to recognize more complex patterns and rules, such as truth tables (XOR).

### XOR Truth Table:
![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/8de4238b-45e3-4a27-ba6e-8a019b904dc1)

As seen in the table, the model must accurately predict the output value (0/1) when given two inputs (e.g., 0 and 0).
#
### Before training:
![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/fae590a5-9d39-4973-8655-85b8e8baca41)
#
### After training:
![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/deb1ec5d-1960-42ee-8dd1-a3a33ee2e1f0)
#
This model controls a total of nine values, and after the training process, predictions become more precise. 

It involves more complex Cost and Forward functions to achieve this.
#
### Cost and Forward functions:
![image](https://github.com/AnteDev00/Machine-Learning-NN/assets/151842550/b61d6fbf-70f8-4ab3-b89c-fc72cf5f803c)

--- 

## Support
If you have any questions, reach out at [ante-piskovic@hotmail.com](mailto:ante-piskovic@hotmail.com)


## Credits
Thanks to [TSoding youtube channel](https://www.youtube.com/@TsodingDaily) for streaming informative Neural Networks content. 

