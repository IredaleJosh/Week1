#include <stdio.h>

//creates file
int main()
{
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w"); //opens file for writing, with w, other file handling stuff: a, w+, a+
    if(file == NULL) //this part is good practice, but not necessary
    {
        perror(""); // returns error message if anything happens
        return 1;
    }

    fclose(file); //closes file immediately after
    return 0;
}