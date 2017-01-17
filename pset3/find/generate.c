/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    //condition(s) to be met before code executes: if argc doesn't equal 2 and 3, throw  a tantrum!, return error;
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    //convert argv[1] to integer, cache in n
    
    int n = atoi(argv[1]);

    /* if argc equals three run srand48,convert argv[2] to string and then to a long int,
       else using the time(null) function,pick random number (of seconds) since 1970.01.01 to date),
       convert to long int...
    */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // loop thru the value of argv[1] (n) and output 48 bit integer < limit
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}