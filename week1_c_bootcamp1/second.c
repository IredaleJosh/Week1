#include <stdio.h>
#include <stdlib.h> //to use atoi
#include <string.h> //use strlen

int main()
{
    //open files
    char filename [] = "numbers.dat";
    FILE *file = fopen(filename, "a+");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    //Read from the "square.dat" file
    int buffer_size = 10;
    float sum;
    int total;
    char line_buffer[buffer_size];
    while(fgets(line_buffer, buffer_size, file) != NULL)
    {
        sum = sum + atof(line_buffer); //convert string to integer
        total++;
        //gets the lenght of the array holding the number and checks
        //when no more numbers, then adds new line to stop while loop
        if (line_buffer[strlen(line_buffer)-1] != '\n')
        {
            fprintf(file, "\n");
        }
    }
    fprintf(file, "%f", sum / total);

    //closes file
    fclose(file);
    return 0;
}