// file: rollingStrings.c
// author: Gaurish Korpal
// purpose: File I/O and memory management; valgrind --leak-check=full --show-leak-kinds=all -s --log-file=log.txt ./rollingStrings input_foo


#include <stdio.h>
#include <stdlib.h> // exit(), malloc()
#include <string.h> // strlen(), strcpy(), strcmp() -- not working for my arrayOfStrings[n] entries


#define SIZE 16

char *readOneStr(FILE *fp, int *err);


int main(int argc, char *argv[])
{
    printf("There are %d command-line arguments\n", argc-1);
    
    int i, j, k, l; // for loop
    FILE *currentFile;
    int ch;
    char *arrayOfStrings[SIZE];
    int error = 0;
    char *m;
    int n; // dummy
    
    // Initialize the array
    arrayOfStrings[0] = "HEAD";
    arrayOfStrings[SIZE - 1] = "TAIL";
    for (j = 1; j < SIZE - 1; j++)
        arrayOfStrings[j] = NULL;
    
    for (i = 1; i < argc; i++) {
        printf("--- FILE: %s (argv[%d]) ---\n", argv[i], i);
        currentFile = fopen(argv[i], "r");
        if (currentFile == NULL) { // canot open the file
            fprintf(stderr, "ERROR: Cannot open the file '%s'\n", argv[i]);
            error = 1; // error occured
        } else {
            while ((ch=getc(currentFile)) != EOF) { // read file till end
                fseek(currentFile, -1, SEEK_CUR); // unread the one byte read
                char *stringThatGotRead = readOneStr(currentFile, &error);
                if (stringThatGotRead == NULL)
                    printf("--- END OF FILE ---\n");
                else {
                    printf("Current strings:\n");
                    
                    arrayOfStrings[1] = stringThatGotRead; // if no NULL then remove the first element

                    for (l = 2; l < SIZE-1; l++) { // insertion sort algorithm for [1] to [SIZE-2]
                        m = arrayOfStrings[l];
                        n = l - 1;
                         
                        while (m < arrayOfStrings[n]  && n >= 1){
                            arrayOfStrings[n+1] = arrayOfStrings[n];
                            --n;
                        }
                        arrayOfStrings[n+1] = m;
                    }
                }

                    for (k = 0; k < SIZE; k++)
                        printf("  %d: %s\n", k, arrayOfStrings[k]);
                    
                    // free(stringThatGotRead); // need to free the malloc but don't know where
            }
        }
            fclose(currentFile);
    }   
    
    if (error == 1)
        exit(1);
    else
        exit(0);
}


char *readOneStr(FILE *fp, int *err)
{
    int n = 1;
    char *str;
    int j = 1;
    int k; // dummy
    char c; // dummy
    
    while (((j=fscanf(fp, "%d", &n)) == 0) || n < 1) {
        if (j == 0) {
            fscanf(fp, "%c", &c);
            printf("OOPS: Non-numeric input detected.  The byte was: 0x%02x='%c'.\n", c, c);
        } else if (n < 1) {
            printf("OOPS: The length read from input, %d, was zero or negative.\n", n);
        }
        
    }

    str = malloc((n+1) * sizeof(char)); // I need to free this in main()
    char format[n+1];
    sprintf(format, "%%%ds", n); // sprintf automatically add \0 at the end.
    k = fscanf(fp, format, str); // to read in the proper format
    
    if (k == EOF)
        return NULL;
    else 
        return str;
}
