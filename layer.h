#ifndef TESTPROJ_LAYER_H
#define TESTPROJ_LAYER_H

/**
 * Create a layer structure. The members
 */
typedef struct Layer
{
    matrix *weights;
    matrix *bias;
    void (*activationFunction)(double*);
    struct Layer *prev;
    struct Layer *next;
}layer;

#endif //TESTPROJ_LAYER_H
