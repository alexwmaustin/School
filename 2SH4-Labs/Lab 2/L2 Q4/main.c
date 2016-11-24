/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 2
Question: 4
*/
//Lab2_Q4_001424250
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void letter_freq(const char word[], int freq []);

int main(void) 
{
    const char word[]="A1B2C3D4E5F6G7H8I9J129K5L13N543OPQR2234ST34UVWXYZ abcde@fgh#$&ijklmnop@#(*qrstuv#@#wx#$yz";
    int freq[26]={0};

    letter_freq(word,freq);
    
    return 0;
}
void letter_freq(const char word[], int freq [])
{
    int i=0;
    
    while(word[i] != 0)
    {
        if(word[i]>='A' && word[i]<='Z')
            freq[('word[i]'-'A')]++;
        
        else if(word[i]>='a'&&word[i]<='z')
            freq[('word[i]'-'a')]++;
        
        i++;
    }
    for (int j=0;j<26;j++)
        printf("The count of %c and %c is %d\n",j+65,j+97,freq [j]);
}

