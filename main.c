#include <stdio.h>
#include "linked.c"

/*
create a single linked list of students in a classroom
each student has a name and age which can be accessed
*/



int main()
{
    list_t studentList;
    listInit(&studentList);

    student_t *studentOne = defStudent("Lucas", 21);
    student_t *studentTwo = defStudent("Fidel", 99);
    student_t *studentThree = defStudent("Antonio", 7);
    student_t *studentFour = defStudent("Martina", 21);

    addStudent(&studentList, studentOne);
    addStudent(&studentList, studentTwo);
    addStudent(&studentList, studentThree);
    addStudent(&studentList, studentFour);

    printStudents(&studentList);

    printf("\n\n");

    removeStudent(&studentList, "Lucas");

    printStudents(&studentList);

    freeStudents(&studentList); //free all students before terminating

}