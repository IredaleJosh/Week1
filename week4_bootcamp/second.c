#include <stdio.h>

int main()
{
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w"); //opens file for writing, with w, other file handling stuff: a, w+, a+
    if(file == NULL) //this part is good practice, but not necessary
    {
        perror(""); // returns error message if anything happens
        return 1;
    }

    int number, num_lines = 10;
    printf("Type %d numbers: ", num_lines); 
    for(int i = 0; i < num_lines; i++) 
    {
        scanf("%d", &number);
        fprintf(file, "%d\n", number); //goes into the file, and adds the number entered, then moves onto a new line
    }

    fclose(file); //closes file immediately after, must have last doing whatever we want to the file, so file doesnt close and cant use
    return 0;
}