/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 1
Question: 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int num=0,num2=0,num3=0,i=10,x=10,z=10;
    
    for(i;i<=100;i++)//first for loop
    {
        if(i%3==0)//checks if multiple
        {
            num+=i;//adds to a sum of the multiples
            printf("1. %d\n",num);
        }
    }
    
    while(x <= 100)//while loop
    {
        if(x%3==0)
        {
            num2+=x;
            printf("2. %d\n",num2);
        }
        x++;
    }
    
    do//do while loop
    {
        if(z%3==0)
        {
            num3+=z;
            printf("3. %d\n",num3);
        }
        z++;
        
    }while(z <= 100);
    
   return 0; 
}