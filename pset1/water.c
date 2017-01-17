#include <cs50.h>
#include <stdio.h>

// function prototype
int multiply(int a);


int main(void){
    int n;
    // loop until get a positive integer
    do{
        printf("How many minutes in shower:");
        n = GetInt();
    }
    while(n<1);
         n = multiply(n);
         printf("bottles of water expended: %i\n", n);
     
     
   
}

int multiply(int n)
{ 
    int num_bottles = 12;
    return  n * num_bottles;
}
