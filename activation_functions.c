#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// My libraries
#include "activation_functions.h"

void sigmoid(double *x)
{
    *x = 1.0 / (1.0 + exp(-*x));
}

void sigmoidDeriv(double *x)
// This is kinda gross
{
    //return sigmoid(&x) * (1 - sigmoid(&x));
    double sig = 1.0 / (1.0 + exp(-*x));
    *x = sig * (1 - sig);
}

void ReLU(double *x)
{
    *x = (*x > 0.0) ? *x : 0;
}

void ReLUDeriv(double *x)
{
    *x = (*x > 0.0) ? 1 : 0;
}

