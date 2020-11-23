#ifndef TESTPROJ_MATRIX_H
#define TESTPROJ_MATRIX_H

#define ELEM(mtx, row, col) \
mtx->data[(col-1) * mtx->rows + (row-1)]

typedef struct matrix
{
    int rows;
    int cols;
    double *data;
}matrix;

matrix *newMatrix(int rows, int cols);
matrix *newRandomMatrix(int rows, int cols);
int setElement(matrix *mtx, int row, int col, double val);
int getElement(matrix * mtx, int row, int col, double *val);
int nRows(matrix *mtx, int *n);
int printMatrix(matrix *mtx);
int sum(matrix *mtx1, matrix *mtx2, matrix *sum);
int elementProduct(matrix *mtx1, matrix *mtx2, matrix *prod);
int product(matrix *mtx1, matrix *mtx2, matrix *prod);
int dotProduct(matrix *v1, matrix *v2, double *prod);
// The 'apply' function is completely mine, so there may be errors
int apply(matrix *mtx, void (*function)(double*));


#endif
