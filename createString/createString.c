// file: createString.c
// author: Gaurish Korpal (template by Lorenzo Fusaro)
// purpose: the function takes two characters as parameters and 
//          returns a pointer to an allocated string that consists
//          of the characters in the alphabet from the first to character
//          to the last character (inclusive).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * CreateString(char one, char two){
    //author: Gaurish Korpal
    char *pointer;
    int n;

    if (two < one) {
        pointer = NULL;
    } else {
        n = two - one + 2; // to store \0 null also
        pointer = malloc(n * sizeof(char));
        while (one < two+1) {
            strcat(pointer, &one);
            one++;
        }
        
    }
    return pointer;
}

// Author: Lorenzo Fusaro
int main(void){
    char first;
    char last;
    char *str;
    
    scanf(" %c",&first);
    scanf(" %c",&last);
    
    str=CreateString(first,last);
    
    if (str!=NULL){
        printf("%s",str);
         free(str);
    }
    
    return 0;
} 
