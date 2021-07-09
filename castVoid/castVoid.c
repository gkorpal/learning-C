// file: castVoid.c
// author: Gaurish Korpal (template by Lorenzo Fusaro)
// purpose: casting void* as int


#include <stdio.h>
#include <stdlib.h>

int Sum(void *a, void *b) {
    int sum;
    sum = *((int*) a) + *((int*) b);
    return sum;
}

// main by Lorenzo Fusaro
int main (void){
    int one;
    int two;
    int * intPtrOne;
    int * intPtrTwo;
    void * ptrOne;
    void * ptrTwo;
    
    scanf("%d",&one);
    scanf("%d",&two);
    
    intPtrOne=&one;
    intPtrTwo=&two;
    ptrOne=intPtrOne;
    ptrTwo=intPtrTwo;
    
    printf("%d", Sum(ptrOne,ptrTwo));
    
    return 0;
} 
