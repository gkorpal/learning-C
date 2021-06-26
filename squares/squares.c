// File: squares.c
// Author: Gaurish Korpal
// Purpose: print out text squares

#include <stdio.h>
#include <ctype.h>// isprint()


void drawSquare(int n, char c) // square drawing function
{
    char box[n][n]; // use 2 dimensional array for printing square
    int i, j; // rows and columns

    if (isprint(c)==0) { // non-printable print character message
        printf("The input character is not a printable character.  Hex=0x%02x\n", c);
    } else if (n%2 != 0) { // square of odd size
        for(i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if(i == j && i != (n-1)/2) {
                    box[i][j] = '\\';
                    printf("%c", box[i][j]);
                } else if(i == n-1-j && i != (n-1)/2) {
                    box[i][j] = '/';
                    printf("%c", box[i][j]);
                } else if(i == j && i == (n-1)/2) {
                    box[i][j] = '*';
                    printf("%c", box[i][j]);
                } else if((i == 0 || i == n-1) && (j != 0 && j != n-1)) {
                    box[i][j] = '-';
                    printf("%c", box[i][j]);
                } else if((i != 0 && i != n-1) && (j == 0 || j == n-1)) {
                    box[i][j] = '|';
                    printf("%c", box[i][j]);
                } else {
                    box[i][j] = c;
                    printf("%c", box[i][j]);
                }
            }
            printf("\n");
        }
    } else if (n%2 == 0) { // square of even size
        for(i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if(i == j) {
                    box[i][j] = '\\';
                    printf("%c", box[i][j]);
                } else if(i == n-1-j) {
                    box[i][j] = '/';
                    printf("%c", box[i][j]);
                } else if((i == 0 || i == n-1) && (j != 0 && j != n-1)) {
                    box[i][j] = '-';
                    printf("%c", box[i][j]);
                } else if((i != 0 && i != n-1) && (j == 0 || j == n-1)) {
                    box[i][j] = '|';
                    printf("%c", box[i][j]);
                } else {
                    box[i][j] = c;
                    printf("%c", box[i][j]);
                }
            }
            printf("\n");
        }
    }
}


int main(void)
{
    int size; // size of the square
    char fill; // characters to fill the square
    int k = 0; // a veriable to keep track of blank lines

    if(scanf("%d", &size) != 1) {   // error if no size is provided 
        fprintf(stderr, "ERROR: Cannot read a size\n");
        return(1);
    } else if(size <= 0) {  // error if size is zero or negative
        fprintf(stderr, "ERROR: The size is not a positive integer.  size=%d\n", size);
        return(1);
    } else { // print out text squares
        while(scanf("%c", &fill) != EOF) { // take fill character inputs until ^D
           if(k != 0)  // don't print new line before the first square
               printf("\n");
           k++;
            drawSquare(size, fill);
        }
        return(0);
    } 
}
