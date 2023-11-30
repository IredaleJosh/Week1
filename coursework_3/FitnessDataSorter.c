#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) 
{
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

//Sort data from highest step at top to lowest
//in tab seperated values (.tsv) format - make space via \t

//1.2) check file is valid, AND data is correct format, then print out msg and return 1
//2) read file into an array, and sort data into descending order (if same step count, be
//consecutive but order doesn't matter)
//3) write data to filename of same name, with file extenstion .tsv and return 0

int main() 
{
    //Variables
    #define buffer_size 100
    char line [buffer_size];
    char filename [buffer_size];
    FitnessData read [100];
    char char_steps [5];
    int counter, int_steps;
    char del [] = ",";

    //Get filename
    printf("Enter filename: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);
    //Open file
    FILE *file = fopen(filename, "r");
    //Check if valid
    if(file == NULL)
    {
        printf("Error: Incorrect File\n");
        return 1;
    }
    //Check if correct format
    while(fgets(line, buffer_size, file))
    {
        tokeniseRecord(line, *del , read[counter].date, read[counter].time, &read[counter].steps);
        //Check if date and time is empty
        if (read[counter].date == " " || read[counter].time == " ")
        {
            printf("Error: Incorrect File\n");
            return 1;
        }
        counter++;
    }

    //Read file into array

    //Sort into new file with .tsv

}
