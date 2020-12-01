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

// TODO: Perhaps
layer *newInputLayer(struct Layer **networkStart, int numberOfNodes)
{
    // Make sure the layer is nonzero or less
    if (numberOfNodes <= 0) return NULL;

    // Allocate memory or the layer
    layer *new_input_layer = (layer*)malloc(sizeof(layer));
    // Indicate the layer is an input layer
    new_input_layer->inputLayer = 1;


    // Set the previous pointer to a null
    new_input_layer->prev = NULL;

    // Hmmm



}


layer *newLayer(int numberOfNodes, void (*actFunc)(double*))
{
    // Test to make sure the number of nodes is greater than 0
    if (numberOfNodes <= 0) return NULL;
    // Allocate memory for the layer
    layer *new_layer = (layer*)malloc(sizeof(layer));
    // Indicate the layer is a not an input layer
    new_layer->inputLayer = 0;



}
