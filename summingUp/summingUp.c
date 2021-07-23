// file: summingUp.c
// author: Gautish Korpal (template by Lorenzo Fusaro)
// purpose: add integer members to a link list and sum every other member


#include <stdio.h>
#include <stdlib.h>


typedef struct Number{
    int num;
    struct Number * next;
}Number;


int Sum(Number * elements){
    // Gaurish Korpal 
    Number *current = elements;
    int n = 0;
    
    while (current != NULL) { // add every other number i.e. skip one
        n = n + current->num;
        if (current->next != NULL) { // check if there is next, then move
            current = current->next;
        } else {
            break;
        }
        if (current->next != NULL) { // check if there is next, then move
            current = current->next;
        } else {
            break;
        }
    }
    return n;
}


Number * Add(Number * elements, int input){
    // Gaurish Korpal
    Number *new = malloc(sizeof(Number));
    new->num = input;
    new->next = elements; // pushing list forward
    
    return new; // the new head of the list, King p. 429
}


// Lorenzo Fusaro
int main(void){
    int  numElements;
    int input, i;
    Number *head=NULL;
    
    scanf("%d", &numElements);
    
    for(i=0; i<numElements; i++){
        scanf("%d", &input);
        head=Add(head, input);
    }
    
   printf("%d\n", Sum(head));
    
    Number * temp;
    while (head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}
