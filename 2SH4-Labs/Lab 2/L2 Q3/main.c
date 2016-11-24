/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 2
Question: 3
*/
//Lab2_Q3_001424250
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

int is_toeplitz(int a[][N], int m);

int main(void) 
{
    int result;
    
    const int mat[4][N] =
   {{9, 2, 1, 0, 4},
    {7, 9, 2, 1, 0},
    {3, 7, 9, 2, 1},
    {6, 3, 7, 9, 2}};

    result = is_toeplitz(mat,4);
    
    printf("%s\n", result == 1?"The Matrix is toeplitz":"The Matrix is not toeplitz");

    return 0;           
}

int is_toeplitz(int a[][N], int m)
{
    for (int i=0;i<(m-1);i++)
    {
        for (int j=0;j<(N-1);j++)
        {
            if((a[i][j])==(a[i+1][j+1]))
                continue;
            return 0;
        }
    }
return 1;    
}
