// file: createStudent.c
// author: Gaurish Korpal (template by Lorenzo Fusaro)
// purpose: create a struct list


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Student {
    int id;
    char *name;
    float percent;
    struct Student *nextStudent;
} Student;


void CreateStudent(Student **head, int i, char *s, float p) { // using pointer we can get rid of return, king p. 439
    Student *link = malloc(sizeof(Student)); // create a student entry
	link->id = i;
    link->name = malloc(strlen(s));
	strcpy(link->name, s);
	link->percent = p;
	link->nextStudent = NULL;
	
	Student *current = *head; // create a temporary entry to place the new set of 
                              //data after the older set
	
	if(*head == NULL) {
		*head = link;
	} else {
		while(current->nextStudent != NULL) {
		current = current->nextStudent; // move away from the head
		}
	current->nextStudent = link;
	}
}


/* ALTER:  to put list in the reverse order: king p. 427 and 439.
void CreateStudent(Student **list, int i, char *s, float p) {
    Student *student = (Student *) malloc(sizeof(Student)); //create a student entry
    student->id = i; 
    student->name = malloc(strlen(s));
    strcpy(student->name, s);
    student->percent = p;
    student->nextStudent = *list; //link to the first student in the list
    *list = student; 
}
*/


// Author of main: Lorenzo Fusaro
int main (void){
    
    int  numStudents;
    int i;
    float percent;
    char name [20];
    Student * studentList=NULL;
    
    scanf("%d", &numStudents);
    
    //Creates a certain number of students
    for(i=0; i<numStudents; i++){
        scanf("%s", name);
        scanf("%f", &percent);
        CreateStudent(&studentList, i, name, percent);
    }
    
    //Prints list to check output
    while (studentList!=NULL){
        printf("%d %s %.2f ",studentList->id,studentList->name,studentList->percent);
        studentList=studentList->nextStudent;
    }
}
 
