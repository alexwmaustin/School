/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 1
Question: 3
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int in=1;
    
    while(in != 0)//keeps looping until user inputs a 0
    {
        printf("Please input an integer (0 to end): ");
        scanf("%d",&in);//scans the number
        
        if((in > 99 && in < 1000)||(in < -99 && in > -1000))//checks if its between a range in order to be 3 numbers
            printf("Your input is a three-digit number: %d \n",in);       
    }
    return 0;
}

