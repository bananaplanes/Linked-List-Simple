#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 128

typedef struct student_t
{
    int age;
    //char *name;
    char name[NAME_LENGTH]; //keeping name in stack for faster access in exchange for more memory if NAME_LENGTH isn't reached
    struct student *next;
}student_t;


typedef struct
{
   student_t *head;
} list_t;



void listInit(list_t *list)
{
    //make list in main and init by making head NULL
    list->head = NULL;
}

student_t *defStudent(const char *name, int age)
{
    //define a new student
    student_t *student = (student_t*) malloc(sizeof(student_t));
    if (!student)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    student->age = age;
    strncpy(student->name, name, NAME_LENGTH);
    student->name[NAME_LENGTH - 1]=  '\0'; //null terminates name
    student->next = NULL;

    return student;
}

void addStudent(list_t *list, student_t *student)
{
    //adds to start of list or starts list if list is empty
    if (list->head == NULL)
    {
        list->head = student;
        return;
    }

    student_t *second = list->head;

    list->head = student;
    student->next = second;
    return;
}

void removeStudent(list_t *list, const char *name)
{
    //find student by name in list and remove.
    //assuming there's only one instance of a student (no duplicates)
    student_t *temp = list->head;
    student_t *prev = NULL;


while (temp != NULL)
{
    if (strcmp(temp->name, name) == 0)
    {
        if (prev == NULL) //if name is first in list
        {
            list->head = temp->next;
            free(temp);
            return;
        }
        else
        {
            prev->next = temp->next;
        }

        free(temp);
        temp = NULL;
        return;

    }

    prev = temp;
    temp = temp->next;
}

printf("student %s not found", name);

}

void printStudents(list_t *list)
{
    //prints name and age of every student in list
    student_t *temp = list->head;
    int count = 1;

    while (temp != NULL)
    {
        printf("Student %d: %s of age %d\n", count, temp->name, temp->age);
        temp = temp->next;
        count++;
    }
}

void freeStudents(list_t *list)
{
    student_t *student = NULL;

    while (list->head != NULL)
    {
        student = list->head;
        list->head = student->next;
        free(student);
    }
    list->head = NULL;
}