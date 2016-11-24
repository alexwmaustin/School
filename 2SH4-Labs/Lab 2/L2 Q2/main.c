/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 2
Question: 2
*/
//Lab2_Q2_001424250
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4

int is_diag_dom(int mat[][N]);

int main(void) 
{
    int result;
    
    const int mat[N][N] =
   {{9, 1, 2, 1},
    {1, 9, 1, 1},
    {1, 1, 9, 1},
    {1, 1, 1, 9}};
    
    result = is_diag_dom(mat);
    
    printf("%s\n", result == 1?"The Matrix is diagonally dominant":"The Matrix is not diagonally dominant");
    
    return 0;
}
int is_diag_dom(int mat[][N])
{
    int sum=0;
    
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            if(i==j)
                continue;
            sum += fabs(mat[i][j]);
        }
        if (sum > mat[i][i])
            return 0;
        sum=0;
    }
    return 1;
}


