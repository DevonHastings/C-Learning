#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
// My libraries
#include "matrix.h"
#include "layer.h"


// TODO: I need this layer function to generate the matrices for the weights and biases
// TODO: I think I will set it up so that I generate the weight based on the previous layer
// TODO: dimensions. The bias will be trivial.

layer *newInputLayer(struct Layer **startLayer, matrix *data)
{
    // Make sure there is some data to look at
    if (!data) return NULL;
    // Make sure the data is in a vector form
    if (data->cols > 1) return NULL;
    // Allocate memory or the layer
    layer *new_input_layer = (layer*)malloc(sizeof(layer));
    // Indicate the layer is an input layer
    new_input_layer->inputLayer = 1;
    // Output of this layer is the data
    new_input_layer->outputOfLayer = data;
    // The number of nodes in the input layer is the height (rows) of the input matrix
    new_input_layer->nodes = data->rows;
    // Return the layer
    return new_input_layer;
}

layer *newLayer(int numberOfNodes, void (*actFunc)(double*), layer *previousLayer)
{
    // Test to make sure the number of nodes is greater than 0
    if (numberOfNodes <= 0) return NULL;
    // Allocate memory for the layer
    layer *new_layer = (layer*)malloc(sizeof(layer));
    // We set the number of nodes for the layer
    new_layer->nodes = numberOfNodes;
    // Indicate the layer is a not an input layer
    new_layer->inputLayer = 0;
     // Columns for the weights are the current layer, the previous layer determines the rows
    new_layer->weights = newRandomMatrix(previousLayer->nodes, numberOfNodes);
    new_layer->bias = newRandomMatrix(numberOfNodes, 1);
    // Set the activation function
    new_layer->activationFunction = actFunc;
    // Allocate and calculate the linear output
    matrix *preOutput = (matrix*)malloc(sizeof(matrix));
    // TODO: Should I check to make sure the output of the previous layer is a vector?
    /* product();

    // Set the output of the layer: output = actFunc(WX+B)
    new_layer->outputOfLayer = apply(, actFunc);
    */

    return new_layer;
}
