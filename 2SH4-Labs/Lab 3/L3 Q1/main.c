/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 3
Question: 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat( const char * const str1, const char * const str2);

int main(void) 
{
    printf ( "%s\n", my_strcat( "HELOOO", "WERLDF" ));
    
    return 0;
}
char *my_strcat( const char * const str1, const char * const str2)
{
    int strlen1, strlen2, totlen, i = 0,j = 0;
    char *p = NULL;//sets pointer
    
    strlen1 = strlen(str1);//gets the length of the strings
    strlen2 = strlen(str2);
    totlen = strlen1 + strlen2 + 1;//gets the total length
    
    p = malloc(totlen*sizeof(char));//allocates memory based on the total size needed
    
    for ( i; i < strlen1; i++)//copies the first string into the array
        p[i]=str1[i];
    
    for ( j; j <= strlen2; i++,j++)//copies second string including the null character into the rest of the memory
        p[i]=str2[j];
    
    return p;
}
