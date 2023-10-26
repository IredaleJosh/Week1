#include <stdio.h>

typedef struct 
{
    char name [6];
    char student_id [5];
    unsigned mark;
} student;

int main()
{
    int number_of_students = 10;
    student students [] = {};
    for (int i = 0; i < number_of_students; i++)
    {
        printf("Enter student name: ");
        scanf("%s\n", students[i].name);
        printf("Enter student ID: ");
        scanf("%s\n", students[i].student_id);
        printf("Enter final mark: ");
        scanf("%u\n", &students[i].mark);
        printf("------------\n");
    }

    for (int i = 0; i < number_of_students; i++)
    {
        printf("-----------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final Mark: %u\n", students[i].mark);
    }
    printf("----------------\n");
    return 0;
}