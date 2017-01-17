#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{

    //printf("Your name please:");    
    string initials = GetString();
    // print the first letter, since it is index...,then convert to uppercase...
    //printf("%c", toupper(initials[0]));
    
    for(int i = 0, n = strlen(initials);i<n;i++)
    { 
        if(initials[i] == initials[0])
        {
            printf("%c", toupper(initials[0]));
        }
        // space is 32 in the ASCII table..., print first letter after every space
        if(initials[i] == (char) 32 ){  
          printf("%c", toupper(initials[i+1]));
        }  
    }
    printf("\n");
     
}