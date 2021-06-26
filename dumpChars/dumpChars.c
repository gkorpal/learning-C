// File: dumpChars.c
// Author: Gaurish Korpal
// Purpose: print out hex values of all the characters

#include <stdio.h>


int main(void)
{
    char a;
    int i = 1; // to keep track of the spacing condition

    while(scanf("%c", &a) != EOF){ // reading all inputs from stdin
        if(i%16 == 1)
            printf("%02x", a);
        else if(i%16 == 5 || i%16 == 9 || i%16 == 13)
            printf("  %02x", a);
        else if(i%16 == 0)
            printf(" %02x\n", a);
        else
            printf(" %02x", a);
        i++;
    }
    printf("\n");
    return 0;
}
