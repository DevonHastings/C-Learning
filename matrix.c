#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
// My libraries
#include "matrix.h"

/**
 * Generate a random double between 0 and 1.
 * @return 0 < number < 1
 */
double randomNumber()
{
    return ((double) rand() / (double) RAND_MAX) ;
}

matrix *newMatrix(int rows, int cols)
{
    // If the matrix has no rows and/or no columns then we can't have a matrix
    if (rows <= 0 || cols <= 0) return NULL;
    // Free memory for a matrix structure
    matrix *new_matrix = (matrix*)malloc(sizeof(matrix));
    // Set the rows and columns
    new_matrix->rows = rows;
    new_matrix->cols = cols;
    // Create an single array that will act like a 2D array
    new_matrix->data = (double*)malloc(rows*cols*sizeof(double));
    // Initialize the values to 0.0
    for (int i = 0; i < (rows * cols); i++)
    {
        new_matrix->data[i] = 0.0;
    }
    return new_matrix;
}

matrix *newRandomMatrix(int rows, int cols)
{
    srand(time(NULL));
    // If the matrix has no rows and/or no columns then we can't have a matrix
    if (rows <= 0 || cols <= 0) return NULL;
    // Free memory for a matrix structure
    matrix *new_matrix = (matrix*)malloc(sizeof(matrix));
    // Set the rows and columns
    new_matrix->rows = rows;
    new_matrix->cols = cols;
    // Create an single array that will act like a 2D array
    new_matrix->data = (double*)malloc(rows*cols*sizeof(double));
    // Initialize the values to 0.0
    for (int i = 0; i < (rows * cols); i++)
    {
        new_matrix->data[i] = randomNumber();
    }
    return new_matrix;
}

int setElement(matrix *mtx, int row, int col, double val)
{
    if (!mtx) return -1;
    // We are going to test to make sure the matrix has data?
    assert (mtx->data);
    if (row <= 0 || row > mtx->rows || col <= 0 || col > mtx->cols)
        return -2;

    ELEM(mtx, row, col) = val;
    return 0;
}

int getElement(matrix * mtx, int row, int col, double * val)
{
    if (!mtx || !val) return -1;
    assert (mtx->data);
    if (row <= 0 || row > mtx->rows || col <= 0 || col > mtx->cols)
        return -2;

    *val = ELEM(mtx, row, col);
    return 0;
}

int nRows(matrix *mtx, int *n)
{
    if (!mtx || !n) return -1;
    *n = mtx->rows;
    return 0;
}

int printMatrix(matrix *mtx)
{
    if (!mtx) return -1;

    int row, col;
    for (row = 1; row <= mtx->rows; row++)
    {
        for (col = 1; col <= mtx->cols; col++)
        {
            // Print the floating-point element with
            //  - either a - if negative or a space if positive
            //  - at least 3 spaces before the .
            //  - precision to the hundredths place
            printf("% 6.2f ", ELEM(mtx, row, col));
        }
        // separate rows by newlines
        printf("\n");
    }
    return 0;
}

int sum(matrix *mtx1, matrix *mtx2, matrix *sum)
{
    if (!mtx1 || !mtx2 || !sum) return -1;

    if (mtx1->rows != mtx2->rows ||
        mtx1->rows != sum->rows ||
        mtx1->cols != mtx2->cols ||
        mtx1->cols != sum->cols)
        return -2;

    int row, col;
    for (col = 1; col <= mtx1->cols; col++)
        for (row = 1; row <= mtx1->rows; row++)
            ELEM(sum, row, col) = ELEM(mtx1, row, col) + ELEM(mtx2, row, col);
    return 0;
}

int elementProduct(matrix *mtx1, matrix *mtx2, matrix *prod)
{
    if (!mtx1 || !mtx2 || !prod) return -1;

    if (mtx1->rows != mtx2->rows ||
        mtx1->rows != prod->rows ||
        mtx1->cols != mtx2->cols ||
        mtx1->cols != prod->cols)
        return -2;

    int row, col;
    for (col = 1; col <= mtx1->cols; col++)
        for (row = 1; row <= mtx1->rows; row++)
            ELEM(prod, row, col) = ELEM(mtx1, row, col) * ELEM(mtx2, row, col);
    return 0;
}

int product(matrix *mtx1, matrix *mtx2, matrix *prod)
{
    if (!mtx1 || !mtx2 || !prod) return -1;
    // Check to see if we can do the classic matrix product
    if (mtx1->cols != mtx2->rows ||
        mtx1->rows != prod->rows ||
        mtx2->cols != prod->cols)
        return -2;

    int row, col, k;
    for (col = 1; col <= mtx2->cols; col++)
        for (row = 1; row <= mtx1->rows; row++)
        {
            double val = 0.0;
            for (k = 1; k <= mtx1->cols; k++)
                val += ELEM(mtx1, row, k) * ELEM(mtx2, k, col);
            ELEM(prod, row, col) = val;
        }
    return 0;
}

int dotProduct(matrix *v1, matrix *v2, double *prod)
{
    // If none of the matrices exist
    if (!v1 || !v2 || !prod) return -1;
    // Check to see if has columns
    if (v1->cols != 1 || v2->cols != 1) return -2;
    // Check to see if there are rows and that they are the same
    if (v1->rows != v2->rows) return -3;

    *prod = 0;
    int i;
    for (i = 1; i <= v1->rows; i++)
        *prod += ELEM(v1, i, 1) * ELEM(v2, i, 1);
    return 0;
}

// TODO: Keep an eye out for this function, it may need to be reworked
int apply(matrix *mtx, void (*function)(double*))
{
    // If no matrix exists
    if (!mtx) return -1;

    int row, col;
    for (row = 1; row <= mtx->rows; row++)
    {
        for (col = 1; col <= mtx->cols; col++)
        {
            function( &ELEM(mtx, row, col) ); // WHY????? Does this work
        }
    }
    return 0;
}
