// file: conact.c
// author: Gaurish Korpal (template by Lorenzo Fusaro)
// purpose: dynamic storage allocation in string functions


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function by Gaurish Korpal
char *Concatenate( int numTimes ) {
    char *m = "Hello World! ";
    int i;
    
    if (numTimes < 1)
       return "";
    else {
        char *result;
        result = malloc(numTimes*strlen(m) + 1);
        strcpy(result, m);
        
        for (i = 0; i < numTimes-1; i++) {
            strcat(result, m);
        }
        return result;
    }
}

// main by Lorenzo Fusaro
int main(void){
    int num;
    scanf("%d",&num);
    printf("%s",Concatenate(num));
    return 0;
} 
