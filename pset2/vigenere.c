#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 

int main(int argc, string argv[])
{
    
    int cipher;
    int cache;
 
    //conditions to be met before code executes;
   if (argc !=2  ){
        printf("command should be more than one\n");
        return 1;
    }
    
    string key = argv[1];
    //loop thru key
    for(int i = 0, j = strlen(argv[1]); i < j ; i++){
         //make sure only alphabets are.....
        if(!isalpha(key[i])){
        
            printf("only Alphabets allowed\n");
            return 1;
        
    }
    }
    //self explanatory...
    //printf("Your message:");
    string p = GetString();   
 
    //loop thru text
    for(int i = 0, j = 0, len = strlen(p); i < len; i++, j++)
    {
        
        if (j >= strlen(key))
        {
            j = 0;
        }
 
        
        cache = key[j]; 
 
       
        if (!isalpha(p[i]))
        {
            j = (j - 1);
        }  
 
        //alphabets
        if ((cache >= 'A') && (cache <=  'Z'))
        {
            cache = (cache -  'A');
        }
 
        if ((cache >= 'a') && (cache <= 'z'))
        {
            cache = (cache - 'a');
        }
 
        
        cipher = (p[i] + cache);
 
        // upper and lower case, similar to caesar
        if (isupper(p[i]) && (cipher > 'Z'))
        {
            cipher = (cipher - 26);
        }
 
       
        if (islower(p[i]) && (cipher > 'z'))
        {
            cipher = (cipher - 26);
        }
 
        
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
        }
    
        else
        {
            printf("%c", cipher);
        }
 
    }  
    printf("\n");
    return 0;
}
