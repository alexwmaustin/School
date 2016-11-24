/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 1
Question: 6
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int s1=1,s2=1,h=1,count;
    
    for(s2;s2<=200;s2++)//loops the second side
    {
        for(s1;s1<=s2;s1++)//makes sure that the s1 loop doesn't get bigger than s2
        {
            for(h;h<=200;h++)//loops possible h values
            {
                if(((s1*s1)+(s2*s2))==(h*h))//checks if the triple is currently valid
                {
                    printf("%d, %d, %d\n",s1,s2,h);//prints each triple
                    count++;
                }
            }
            h = 1;//resets counter
        }
        s1 = 1;//resets counter
    }
    printf("There were %d triples found",count);

    return 0;
}

