/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
/*bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n<0){
        return false;
    }
    
    for(int i = 0; i < n; i++){
        if(values[i] == value){
            return 1;
        }
        
    }
    return 0;
}*/
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n<0){
        return false;
    }
    
    int start = 0, end =0,mid;
    while(start <= end){
         mid = (start+end)/2;
        //run if value equals middle value of array
        if(value == values[mid])
            return true;
        
        else if(value < values[mid])
        
             end = mid - 1;
        
        else 
              start = mid + 1;
        
    }
    
    return 1;
        
    
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    while(1){
        int swap = 0,cache;
        
        for(int i = 0; i < n-1; i++){
            //swapping
            if(values[i]>values[i+1]){
                
                cache = values[i];
                values[i] = values[i+1];
                values[i+1] = cache;
                
                swap = 1;
                
            }
        }
        //break out of loop if swap equal 0
        if(swap == 0){
            break;
        }
    
    
    }
}