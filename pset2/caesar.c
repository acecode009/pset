#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int k,cipher;
    if (argc !=2){
        printf("command should be more than one\n");
        return 1;
    }
    printf("");    
    string message = GetString();
    //convert string message to int
    k = atoi(argv[1]);
    
    if (k >=26){
        k = k%26;
    }
    //loop thru message
    for(int i = 0, n = strlen(message);i<n;i++)
    { 
        int len = message[i];
         //add k (key) to the message,  store in cipher....
        cipher = message[i]+k;
        
        //conditions: if cipher is greater than the 122nd char and is lower case, execute
        if (cipher >(char)122 && (islower(len)) ){
            cipher = cipher-26;
        }
        // do same
        if (cipher >(char)90  && (isupper(len))){
            cipher = cipher-26;
        } 
       // execute if cipher is not an alphabet...
       if(!isalpha (cipher))
        {
           printf("%c",len);
        }
        else
        {
         printf("%c",cipher);
        }
    }
    printf("\n");
    return 0;
}