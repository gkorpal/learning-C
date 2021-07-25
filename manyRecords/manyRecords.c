// file: manyRecords.c
// author: Gaurish Korpal
// purpose: reading and writing an array of structs
// valgrind failure in all error cases; valgrind --leak-check=full --show-leak-kinds=all -s --log-file=log.txt ./rollingStrings


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Record {
    int m;
    int n;
    char p[16]; // for word with no more than 15 characters
} Record;


void printRecord(Record *array)
{
    printf("%d %d %s\n", array->m, array->n, array->p);
}


int main(void)
{
    int a, b; // input integers
    char c[16]; // input string
    int j;
    int count = 1;
    Record *buff = malloc(sizeof(Record));
    int i = 0;

    while ((j = scanf("%d %d %15s", &a, &b, c)) != -2) {
        if (j == 0) {
            printf("scanf() returned 0, so now we'll check to see if the string is \"END\"...\n");
            char d[4];
            scanf("%3s", d);

            if (strcmp("END", d) == 0) {
                printf("...\"END\" found.  Will now read the indices...\n");
                break;
            } else {
                fprintf(stderr, "ERROR: the string is not \"END\".  Ending the program!\n");
                return 1;
            }
        } else if (j == 1) {
            fprintf(stderr, "ERROR: scanf() rc=%d\n", j);
            return 1;
        } else if (j == EOF) { // EOF is same as -1, that's why used -2 above
            fprintf(stderr, "ERROR: scanf() rc=%d\n", j);
            return 1;
        } else {
            buff[i].m = a;
            buff[i].n = b;
            strcpy(buff[i].p, c);

            if (count <= i+1) {
                printf("Need to extend the array; the buffer is full (with %d records)\n", count);
                printf("  Before extending the array, element 0 is: ");
                printRecord(&(buff[0]));
                count = 2 * count;

                // realloc() substitute for this case
                Record *tempBuff = malloc(count * sizeof(Record));
                memcpy(tempBuff, buff, sizeof(Record) * (i+1)); // using i+1, not count/2, to avoid wastage
                free(buff);
                buff = tempBuff;

                printf("  After  extending the array, element 0 is: ");
                printRecord(&(buff[0]));
            }
            i++;
        }
    }


    int k, e; // input index

    while ((k = scanf("%d", &e)) != EOF) {
        if (k == 0) {
            fprintf(stderr, "ERROR: scanf() rc=%d\n", k);
        } else {
            printf("[%d] ", e);
            if (e > i-1 || e < 0) {
                printf("<invalid index>\n");
            } else {
                printRecord(&(buff[e]));
            }
        }
    }
    free(buff);
    return 0;
}
