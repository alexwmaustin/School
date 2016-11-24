/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 1
Question: 4
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    float n;
    
    printf("Please input an average: ");
    scanf("%f",&n);//grabs the average given

    if(n >= 90)//the series of if statements compare it to pre determined values and outputs a corresponding integer based on the average
        printf("4");
            
    else if(n >= 80 && n <= 89)
        printf("3");
            
    else if(n >= 70 && n <= 79)
        printf("2");
            
    else if(n >= 60 && n <= 69)
        printf("1");
            
    else if(n <= 59)
        printf("0");
            
    else
        printf("invalid input");

    return 0;
}

