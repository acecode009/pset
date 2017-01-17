#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int picked_height;
    
    do{
        printf("Pick a height: ");
        picked_height = GetInt();
    }
    //loop until a number greater than one but less than 23 is picked
    while(picked_height < 1 || picked_height > 23);
    
       //parts of the pyramid
        int length,width,base; 
        base = picked_height + 1;
        
        for(length = 0; length < picked_height; length++)
        {
          for(width = 0; width < base; width++){  
               if(width <= base - 3 - length) {
                   printf(" ");
               }
               else{
                printf("#");
               }
               
          }
          printf("\n");
        
        }
}