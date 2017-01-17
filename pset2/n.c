#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    string p;
    int k=0, store;
    int cipher; 
     
    string key = argv[1];
    if (argc !=2  ){
        printf("command should be more than one\n");
        return 1;
    }
    
    for(int i=0,j=strlen(key);i<j;i++){
        
        if(!isalpha(key[i])){
        printf("only Alphabets allowed\n");
        return 1;
        
    }
    }
    printf("Your message:");    
     p = GetString();
     
    
    for(int i=0,n,  len=strlen(p); i<len;i++,n++){
        
        if(n >= strlen(key)){
            n=0;
        }
        
        store = key[n];
        
        
        if(!isalpha(strlen(p))){
             n = n-1;
        }
        cipher = (int) (p[i] + key);
        //make A and a =0, Z and z =25;
        if(isalpha(p[i])){
            if( isupper(key[i]) && isupper(p[i])){
                cipher =cipher-65;
                p[i] = (((p[i]-65)+(key[k]-65))%26)+65;
        }
        
            if(islower(key[i]) && islower(p[i])){
                cipher = cipher-97;
                p[i] = (((p[i]-97)+(key[k]-97))%26)+97;
           
        }
        k++;
        }
        
        
        
          
     
        if(isalpha(p[i])){
          printf("%c",cipher);  
        }
        
     
   
    }    
    printf("\n");
     
}