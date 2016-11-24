/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 2
Question: 5
*/
//Lab2_Q5_001424250
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void string_copy(char source[],char destination[],int n);

int main(void) 
{
    const int n = 5;
    char word[]="banana";
    char dest[n];
    string_copy(word,dest,n);

    return 0;
}
void string_copy(char source[],char destination[],int n)
{

    int i=5,j=0,x=0;
    
    while(source[i]!='\0')
        i++;
    
    if(i>n)
    {
        for (j;j<n;j++)
        {
            destination[j]=source[j];
        }
        destination[j-1] = 0;
    }
    else if(i<n)
    {
        for (x;x<i;x++)
            destination[x]=source[x];
        destination[i] = 0;
    }
    printf("%s",destination);
}
