/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 1
Question: 2
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int in,n,temp;
    
    printf("How many integers do you wish to enter? ");
    scanf("%d",&n);//scans the initial amount of numbers
    
    printf("Please enter a positive integer ");
    scanf("%d",&temp);//grabs the first number
    
    for(int i=0;i < (n-1);i++)//loops through the amount of terms
    {    
          
        printf("Please enter a positive integer ");
        scanf("%d",&in);//gets the next number
    
        if(in >= 0)//checks if positive number
        {
            if(in < temp)//compares the next number to previous to see which is lower
                temp = in;//if the current number is lower than the previous it saves it
        }
        else//if its not positive
            printf("That integer was not positive");
    }
    printf("The smallest integer entered was %d.",temp);
    return 0;
}

