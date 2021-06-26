// file: intConvert.c
// Author: Gaurish Korpal
// purpose: understanding pointers and arrays

#include <stdio.h>
#include <stdlib.h> // exit status
#include <ctype.h> // isprint, isdigit

int main(void)
{
    int n, m, i;
    int j = 0; // for counting the spaces
    int k = 0; // for counting the digits in the char form
    int l = 0; // for counting bad input

    while((m = scanf("%d", &n)) != EOF){ // read all input
        if(m == 1){
            int *p = &n;
            unsigned char *q = (unsigned char*) p; // accessing the int as 4 bytes
            printf("val=%d=0x%08x: as characters: ", n, n);
            for(i = 0; i < 4; i++) {
                if(q[i] == '\0') {
                    printf("0x%02x=<null>", q[i]);
                    if(i != 3)
                        printf(" ");
                } else if(isprint(q[i]) == 0) {
                    printf("0x%02x=?", q[i]);
                    if(i != 3)
                        printf(" ");

                } else {
                    printf("0x%02x='%c'", q[i], q[i]);
                    if(i != 3)
                        printf(" ");
                    if(q[i] == ' ')
                        j++;
                    else if(isdigit(q[i]))
                        k++;
                }
            } 
        } else { // read the character to avoid infinite loop due to wrong input format
            char loop;
            scanf("%c", &loop);
            printf("OOPS, the character 0x%02x='%c' is not part of an integer!", loop, loop);
            l++;
        }
        printf("\n");
    }
    printf("\n");
    printf("Totals: spaces=%d digits=%d bad=%d\n", j, k, l);
    if (l == 0) // exit without errors
        exit(0);
    else
        exit(1);
}
