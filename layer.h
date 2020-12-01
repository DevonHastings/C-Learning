#ifndef TESTPROJ_LAYER_H
#define TESTPROJ_LAYER_H

/**
 * Create a layer structure. The members
 */
typedef struct Layer
{
    int nodes;
    matrix *weights;
    matrix *bias;
    matrix *outputOfLayer;
    void (*activationFunction)(double*);
    struct Layer *prev;
    struct Layer *next;
    // Should I include an input style flag? To indicate if the layer is an input?
    int inputLayer;
}layer;

#endif //TESTPROJ_LAYER_H
