#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
#define buffer_size 100
char line [buffer_size];
char filename[buffer_size];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) 
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);
}

// Complete the main function
int main() 
{
    //Loop through forever until program exits
    while(1)
    {
        char option;
        //Display choices
        printf("Select one of the following options\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longes continous period where the step count is above 500 steps\n");
        printf("Q: Exit program\n");

        option = getchar();

        while (getchar() != '\n');

        //Options - make a function
        switch (option)
        {
            case "A":
                printf("Input Filename: ");
                fgets(line, buffer_size, stdin);
                sscanf(line, " %s ", filename);
                FILE *file = fopen(filename, "r");
                if(file == NULL)
                {
                    printf("Incorrect filename, try again");
                    return 1;
                }
                break;
            case "B":
                //record_number
                break;
            case "C":
                //fewest_steps
                break;
            case "D":
                //largest_steps
                break;
            case "E":
                //mean_steps
                break;
            case "F":
                //longest_period
                break;
            case "Q":
                return 0;
                break;
            default:
                printf("Invalid choice, try again");
                break;
        }
    }
}