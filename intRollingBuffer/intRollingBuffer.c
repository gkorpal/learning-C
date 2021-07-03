// file: intRollingBuffer.c
// author: Gaurish Korpal
// Purpose: understanding malloc()

#include <stdio.h>
#include <stdlib.h> // malloc(), exit()

void dumpInts (int *array, int count, int hex) // function to print well spaced array
{
    int j;
    if (hex == 0) {
        for (j = 0; j < count; j++) { // decimal array
            if (j == 0)
                printf(" %10d", array[j]);
            else 
                printf(" %11d", array[j]);
        }
    } else {
        for (j = 0; j < count; j++) { // hex array
            if (j == 0)
                printf(" 0x%08x", array[j]);
            else
                printf("  0x%08x", array[j]);
        }
    }
   // printf("\n");
}


int main(void)
{
    int first; // size of the buffer much be at least 1
    int size; // actual array size
    int *a; // array pointer for dynamic memory allocation
    int i; // for loops
    int other; // other integers for filling array
    int m; // OOPS messages
    char c; // to aviod stdin infinte loop and print OOPS
    int k = 0; // keep track of OOPS
    int l, n; // for insertion sort

   
    if (scanf("%d", &first) != 1) {
        fprintf(stderr, "ERROR: Cannot read the buffer length.\n");
        exit(1);
    } else if (first < 1) { 
        fprintf(stderr, "ERROR: len is less than 1.\n");
        exit(1);
    } else {
        size = first + 2;
        a = malloc(size * sizeof(int)); // array [-559038737 ..... -1059786739]

        if (a == NULL) { // king p. 415
            fprintf(stderr, "Could not malloc() the 'nums' array.\n");
            exit(1);
        } else {
            a[0] = -559038737;
            a[size-1] = -1059786739;
            for (i = 1; i < size-1; i++) {
                a[i] = i;
            }
            
            dumpInts(a, size, 0); // decimal
            printf("\n");
            dumpInts(a, size, 1); // hex
            printf("\n");
            //printf("\n");

            while ((m=scanf("%d", &other)) != EOF) {
                if (m != 1) {
                    scanf("%c", &c);
                    printf("\n");
                    printf("OOPS: Non-integer input!  0x%02x='%c'\n", c, c);
                    k++;
                } else {
                    a[1] = other; // remove the first non-fixed element of the array

                    for (i = 2; i < size-1; i++) { // insertion sort algorithm for a[1] to a[size-2]
                        l = a[i];
                        n = i - 1;

                        while (l < a[n] && n >= 1){
                            a[n+1] = a[n];
                            --n;
                        }
                        a[n+1] = l;
                    }

                    printf("\n");
                    dumpInts(a, size, 0); // decimal
                    printf("\n");
                    dumpInts(a, size, 1); // hex
                    printf("\n");
                }
            }
            if (k == 0)
                return 0;
            else
                return 1;
        }
    }
}
