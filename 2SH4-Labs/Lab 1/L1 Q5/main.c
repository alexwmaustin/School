/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 1
Question: 5
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int in,i,sign=1;
    double pi;
    
    printf("Enter the amount of terms: ");
    scanf("%f",&in);//grabs the amount of terms a use wants to calculate
    
    for(i;i <= in; i++ )//loops through the amount of terms
    {
        pi+=((4.0*sign)/((2.0*i)+1));//uses infinite series calculation 
        sign= -sign;//changes the sign every other term
    }
    printf("The approximation of pi is equal to %f ",pi);
    return 0;
}

