/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 1
Question: 9
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n,counter1,counter0,change=1,sum2,h,z,x;
    
    FILE *input_file=fopen("data.txt","r");//creates and opens all necessary files
    FILE *input_file2=fopen("data2.txt","r");
    FILE *output_file=fopen("output.txt", "w");
    FILE *output_file2=fopen("output2.txt", "w");
    
    
    fscanf(input_file,"%d",&n);//skips first number due to nature of my while loop
    
    while(fscanf(input_file,"%d",&n) != EOF)//loops until the end of page character so it knows where to stop
    {
        if(n == 1)//checks if its a 1
        {
            counter1++;//makes the 1 counter go up
            if(counter1 <= 1)//checks to make sure that the opposite counter will only printed once if there is a consecutive 1
            {
                fprintf(output_file,"%d ", counter0 );//prints the opposite counter in order to always start with 0's
            }
            counter0=0;//resets the counter
        }
        
        if(n == 0)//same thing as above but for 0's
        {
            counter0++;
            if(counter0 <= 1)
            {
               fprintf(output_file,"%d ",counter1 );
            }
            counter1=0;
        }
        
    }
    if(counter0 > 0)//makes sure that the last digit is printed
    {
        fprintf(output_file,"%d ",counter0 );

    }
    else
    {
        fprintf(output_file,"%d ",counter1 );
    }
    
    
    fscanf(input_file2,"%d",&h);//scans in the number of digits from the second input file
    
    
    while(fscanf(input_file2,"%d",&h) != EOF)//loops until the end of the file
    {
        sum2 += h;//adds up each number in order to know how many 1's and 0's there are when ouputting
    }
    fprintf(output_file2,"%d ",sum2);//prints the sum to file
    
    rewind(input_file2);//moves cursor back to beginning of second input file
    fscanf(input_file2,"%d",&h);//again, skips first number due to nature of my while loop
    
    while(fscanf(input_file2,"%d",&h) != EOF)//loops until end of file character
    {
        if(change == 1)//change is initialized to 1 in variable declerations in order to enter statement to that the 0's will be printed first
        {
            for(x;x < h;x++)//takes the first number and loops based on that
                fprintf(output_file2,"0 ");
            change=0;//flips the change variable in order to print the next amount of 1's required
            x=0;//resets x
        }
        else if(change == 0)//same thing as above but for the ones
        {
            for(z;z < h;z++)
                fprintf(output_file2,"1 ");
            change=1;
            z=0;
        }
    }
    fclose(input_file);//closes all the opened files
    fclose(input_file2);
    fclose(output_file);
    fclose(output_file2);

    return 0;
}

