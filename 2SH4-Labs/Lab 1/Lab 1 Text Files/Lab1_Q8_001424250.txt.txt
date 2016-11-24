/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 1
Question: 8
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int in,temp,remain,num;
    
    printf("Please input an integer: ");
    scanf("%d",&in);//grabs the number

    while(in != 0)//loops until in is 0 so it can read a longer integer
    {
        remain = in%10;//finds the remainder
        num = num*10+remain;//puts the current remainder to a new variable in order to flip it
        in= in/10;//shortens the current number to the correct number
    }
    printf("the reverse is %d",num);
    return 0;
}

