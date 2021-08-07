// file: switchCase.c
// author: Gaurish Korpal (outline by Lorenzo Fusaro)
// purpose:  Changing case of each letter in a string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * SwitchCase(char * str){
    // Gaurish Korpal
    int n = strlen(str);
    char *STR = malloc((n+1) * sizeof(char)); // extra of \0
    
    for (int i = 0; i < n; i++) {
        if ((str[i] >= 65) && (str[i] <= 90)) { //using ASCII
            STR[i] = str[i]+32;
        } else if ((str[i] >= 97) && (str[i] <= 122)) {
            STR[i] = str[i]-32;
        } else {
            STR[i]=str[i];
        }
    }
    
    return STR;
}

// Lorenzo Fusaro
int main(){
    char str [20];
    
    scanf("%s", str);
    
    printf("%s\n",SwitchCase(str));
} 
