// File: powers.c
// Author: Gaurish Korpal
// Purpose: print out powers of a number and check which of them are multiples of another number


#include <stdio.h>

int main(void) 
{
    int n, c, m; // three intgers for input
    int i; // for-loop variable
    int j = 1; // for printing the powers
    int k = 0; // for counting the multiples of m

    if(scanf("%d%d%d", &n, &c, &m) == 3){ // check for all three inputs
        if(n > 1 && m > 1) { 
            for(i = 0; i < c; i++) { // multiplication loop
                if(j%m == 0) { // checking for the multiples of m
                    printf("%d is a multiple of %d\n", j, m);
                    k++;
                } else {
                    printf("%d\n", j);
                }
                j = j * n;
            }
            printf("TOTAL: %d multiples of %d\n", k, m);
            return(0);
        } else if(n <= 1) { // print error if num less than 2
            fprintf(stderr, "ERROR: The base number is less than or equal to 1. num=%d\n", n);
            return(1);
        } else if(m <= 1) { // print error if modulo less than 2
            fprintf(stderr, "ERROR: The modulo number is less than or equal to 1. modulo=%d\n", m);
            return(1);
        }
    } else { // error if unable to read three integers
        fprintf(stderr, "ERROR: Cannot read three integers from input.\n");
        return(1);
    }
}
                
