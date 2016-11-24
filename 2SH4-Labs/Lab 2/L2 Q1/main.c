/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 2
Question: 1
*/
//Lab2_Q1_001424250
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_vector(double array[], int size);
void add_vectors( double vector1[],double vector2[],double vector3[], int n);
double scalar_prod(double vector1[],double vector2[]);
double norm2(double vector1[]);

#define N 5

int main(void) 
{
    int vec1L,vec2L;//variable initialization
    double scalProd,norm;
    
    double x[] = {23,-52,24,5,536};//create arrays
    double y[] = {4,34,1,24,3};
    printf("Vector 1: ");
    print_vector(x,N);
    printf("Vector 2: ");
    print_vector(y,N);
   
    vec1L= (sizeof x/sizeof x[0]);//determining the size of the array by dividing the total bit size by one index's bit size
    vec2L= (sizeof y/sizeof y[0]);
    if(vec1L == vec2L)//determining the if the vectors are the same length
    {
        double z[vec1L];//creating a third vector to store the sum of the two vectors
        add_vectors(x,y,z,vec1L);
    }
    else
    {
        printf("The two vectors are not the same length\n");
    }
    scalProd = scalar_prod(x,y);
    printf("Scalar Product: %f\n",scalProd);
    
    norm = norm2(x);
    printf("norm: %f\n",norm);
    
    
    return 0;
}
void print_vector(double array[], int size)
{
    //use a for loop to print each char?
    for (int i=0;i<size;i++)
        printf("%f, ",array[i]);
    printf("\n");
}
void add_vectors( double vector1[],double vector2[],double vector3[], int n)
{
    //pass an empty third array to then fill with numbers. have to check the arrays that they are the proper size.to then determine the size of the third array.
    for (int i=0;i<n;i++)
        vector3[i]=(vector1[i]+vector2[i]);
    
    print_vector(vector3,n);
}
double scalar_prod(double vector1[],double vector2[])
{
    double scalProd=0;
    for (int i=0; i < N; i++)
        scalProd += (vector1[i]*vector2[i]);
    
    return scalProd;
}
double norm2(double vector1[])
{
    double norm,scalProd=scalar_prod(vector1,vector1);
    norm = sqrt(scalProd*scalProd);
    return norm;
}
