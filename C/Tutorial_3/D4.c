// A square matrix (2‐dimensional array of equal dimensions) can be reduced to upper‐
// triangular form by setting each diagonal element to the sum of the original elements in
// that column and setting to 0s all the elements below the diagonal.  For example, the 4‐
// by‐4 matrix:
//        4   3   8   6
//        9   0   6   5
//        5   1   2   4
//        9   8   3   7
// would be reduced to  
//        27   3   8   6
//         0   9   6   5
//         0   0   5   4
//         0   0   0   7
//         Write a function reduceMatrix2D() to reduce a matrix with dimensions of rowSize and
// colSize. The prototype of the function is:  
// void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);
// SIZE is a constant defined at the beginning of the program. For example, #define SIZE 10.
// The parameters rowSize and colSize are used to specify the dimensions of the 2‐
// dimensional array (e.g. 4x4) that the function should process.
// Write a program to test the function.

#include <stdio.h>
#define SIZE 5
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);

int main()
{
    int ar[SIZE][SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    reduceMatrix2D(ar,SIZE,SIZE);
}

void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize)
{
    for (int i = 0; i < colSize; i++)
    {
        for (int j = 1 + i; j < rowSize; j++)
        {
            ar[0 + i][i] += ar[j][i];
            ar[j][i] = 0;
        }
    }

    for (int i = 0; i < colSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            printf("%d ",ar[i][j]);
        }
        printf("\n");
    } 
}