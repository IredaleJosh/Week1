#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char filename[], char mode[])
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        perror("");
        exit(1);
    }
    return file;
}

int main()
{
    //does stuff with file function
    char filename [] = "data.txt";
    char mode [] = "r";
    FILE *file = open_file(filename, mode);

    int buffer_size = 2; //read in the whole of the line in file, this called buffer - at 100 now, as we guessed its that long
    char line_buffer[buffer_size]; //create char array of the size of the buffer
    while(fgets(line_buffer, buffer_size, file) != NULL) //fgets, gets from file, goes thru each line and gets a 100 char of the line, and puts them in the array, repeats until the array will be empty if it gets from file
    {
        printf("%s", line_buffer); //print the line from the file just got      atoi - converts from string to int
    }
}