// file: compareBytes.c
// author: Gaurish Korpal
// purpose: reading files


#include <stdio.h>
#include <stdlib.h> // exit()
#include <ctype.h> // isprint()


void dumpNext(char *filename, FILE *fp, unsigned char c);
void printChar(unsigned char c);


int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int ch1, ch2;
    int bytes = 0; // for keeping track of the byte of difference
    int flag = 0; // for stopping comparison at the first difference


    if (argc != 3) {
        fprintf(stderr, "SYNTAX: ./compareBytes <file1> <file2>\n");
        exit(1);
    }

    if ((fp1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Cannot open first file: No such file or directory\n");
        exit(1);
    }

    if ((fp2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "Cannot open second file: No such file or directory\n");
        fclose(fp1);
        exit(1);
    }

    while (((ch1 = getc(fp1)) != EOF) && ((ch2 = getc(fp2)) != EOF)) {
        //printf("%d = %d\n", ch1, ch2);
        if (ch1 == ch2) { // stop when end of file is reached
            flag = 0;
            bytes++;
        } else { // stop when difference is detected
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        if (ch1 == EOF && ch1 != EOF) {
            printf("The file '%s' was shorter than '%s'.\n", argv[1], argv[2]);
            dumpNext(argv[2], fp2, ch2);
            exit(1);
        } else if (ch1 != EOF && ch2 == EOF) {
            printf("The file '%s' was shorter than '%s'.\n", argv[2], argv[1]);
            dumpNext(argv[1], fp1, ch1);
            exit(1);
        } else {
            printf("No difference found.\n");
            exit(0);
        }
    } else {
        printf("Difference found at byte %d.\n", bytes);
        dumpNext(argv[1], fp1, ch1);
        dumpNext(argv[2], fp2, ch2);
        exit(1);
    }
}


void dumpNext(char *filename, FILE *fp, unsigned char c) // to report difference between two files
{   
    int left = 1; // at least one different character is there
    
    long file_pos = ftell(fp); // save current position

    while (getc(fp) != EOF) // count the characters after the current c; ftell is not used for text.
        left++;

    fseek(fp, file_pos-1, SEEK_SET); // return to the old positon at c
    
    if (left < 4) {
        printf("'%s' only has %d bytes left:", filename, left);
        
        char *a; // array of characters we want to print
        a = malloc(left * sizeof(char));
        
        int i; // dummy for loop

        for (i = 0; i < left; i++) {
             if (i != 0)
                printf(" ");
            a[i] = getc(fp);
            printChar(a[i]);
        }
        printf("\n");
    } else {
        printf("The next 4 bytes of '%s' are:", filename);

        char *b; // aray of characters to print
        b = malloc(4 * sizeof(char));

        int j; // dummy for loop

        for (j = 0; j < 4; j++) {
            if (j != 0)
                printf(" ");
            b[j] = getc(fp);
            printChar(b[j]);
        }
        printf("\n");
    }
}


void printChar(unsigned char c) // prints the next 4 bytes in hex 
{
    if (isprint(c))
        printf("0x%02x='%c'", c, c);
    else if (c == '\0')
        printf("0x%02x=<null>",c);
    else
        printf("0x%02x=<unprintable>", c);
}
