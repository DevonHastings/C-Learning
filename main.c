#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
// My libraries
#include "matrix.h"
#include "activation_functions.h"

// TODO: Figure out how I want the structure of the networks to be.
// TODO: Maybe have a struct for a layer and a struct for the network?


typedef struct Layer
{


}layer;






int main(void)
{
    printf("<=-=-=-=-=-=-=>\n");

    matrix *A;
    int row = 3;
    int col = 3;
    A = newRandomMatrix(row, col);

    printMatrix(A);
    apply(A, sigmoid);
    printf("\n");
    printMatrix(A);










//    matrix *A, *B, *C, *R;
//    A = newMatrix(2, 2);
//    B = newMatrix(2, 2);
//    C = newMatrix(2, 2);
//    R = newRandomMatrix(2, 2);
//
//    setElement(A, 1, 1, 0);
//    setElement(A, 1, 2, 1);
//    setElement(A, 2, 1, 2);
//    setElement(A, 2, 2, 3);
//    printMatrix(A);
//
//    printf("\n");
//
//    setElement(B, 1, 1, 2);
//    setElement(B, 1, 2, 2);
//    setElement(B, 2, 1, 2);
//    setElement(B, 2, 2, 2);
//    printMatrix(B);
//
//    printf("\n");
//
//    printMatrix(R);

    printf("<=-=-=-=-=-=-=>\n");
    return 0;
}







