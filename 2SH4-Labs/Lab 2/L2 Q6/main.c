/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 2
Question: 6
*/
//Lab2_Q6_001424250
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void efficient( const int source[], int val[], int pos[], int size);
void reconstruct( int source[], int m, const int val[], const int pos[], int n);
void print_vector(int array[], int size);

int main(void) 
{
    const int n =11,k = 5;
    int vector[]={45, 0, 23, 0, -7, 0, 0, 48,9,0,0};
    int val[k];
    int pos[k];
    int recnsrt[n];

    efficient(vector,val,pos,n);
    reconstruct(recnsrt,n,val,pos,k);
    
    return 0;
}
void efficient( const int source[], int val[], int pos[], int size)
{
    int j=0;
    
    for(int i = 0;i<size;i++)
    {
        if(source[i]!=0)
        {
            val[j]=source[i];
            pos[j]=i;
            j++;
            continue;
        }
    }
    printf("val\t");
    print_vector(val,5);
    printf("pos\t");
    print_vector(pos,5);
    
 
    
}
void reconstruct( int source[], int m, const int val[], const int pos[], int n)
{
    int j=0;
    for(int i = 0;i<m;i++)
    {
        //printf("%d %d %d %d\n",i,j,pos[j],val[j]);
        if(pos[j]== i)
        {
            source[i]=val[j];
            j++;
        }
        else
            source[i]=0;
    }
    print_vector(source,m);
}
void print_vector(int array[], int size)
{
    //use a for loop to print each char?
    for (int i=0;i<size;i++)
        printf("%d\t",array[i]);
    printf("\n");
}
