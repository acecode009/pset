#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    // the remainder is set to 0, an incremented while a condition is true...
    int remainder = 0;
    float change_owed;
    do{
        
        printf("O hai! How much change is owed?:");
        change_owed = GetFloat();
    }
    
    while(change_owed<=0);
     // covert the changed_owed to an integer
        int sum = round(change_owed * 100);
    
    // this operation will be executed only if the sum is greater than 0.....
    while(sum>0){
        int quarters,dimes, nickels, pennies;
        quarters= 25;
        dimes = 10;
        nickels = 5;
        pennies = 1;
        
        if((sum-quarters)>=0){
            sum = sum - quarters;
            remainder++;
         }
        else if((sum-dimes)>=0){
            sum = sum - dimes;
            remainder++;
         }
         else if((sum-nickels)>=0){
            sum = sum - nickels;
            remainder++;
         }
         else if((sum-pennies)>=0){
            sum = sum - pennies;
            remainder++;
         }
    }
    printf("%d\n",remainder);
}