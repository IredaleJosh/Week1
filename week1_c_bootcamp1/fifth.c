#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
int record_num, step_counter, counter, need_counter, mean, start, end;

// Global variables for filename and FITNESS_DATA array
#define buffer_size 100
char line [buffer_size];
char filename[buffer_size];
char line_count[24];

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

FILE *openfile(char *filename)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Incorrect filename, try again");
        return 1;
    }
    else
    {
        printf("File loaded successfully\n");
    }
    
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

        //Must use these, otherwise thinks two characters are inputted
        option = getchar();
        while (getchar() != '\n');

        //Options - make a function
        switch ( option)
        {
            case 'A':
                //Get filename
                printf("Input Filename: ");
                fgets(line, buffer_size, stdin);
                sscanf(line, " %s ", filename);
                //Open file if possible
                
                FILE *file = fopen(filename, "r");
                if(file == NULL)
                {
                    printf("Incorrect filename, try again");
                    return 1;
                }
                else
                {
                    printf("File loaded successfully\n");
                }

                while(fgets(array, 100, file))
                {
                    char strsteps[100];
                    FITNESS_DATA row = {};
                    tokeniseRecord(array, ",", row.date, row.time, strsteps);
                    row.steps = atoi(strsteps);
                    data[count] = row;
                    count++;
                }

                break;
            case 'B':
                record_num = 0;
                while(fgets(line_count, 24, file) != NULL)
                {
                    record_num = record_num + 1;
                }
                printf("Total Records: %d\n", record_num);
                break;
            case 'C':
                counter = 0;
                need_counter = 0; //stores the line of where the fewest steps are
                while(fgets(line, buffer_size, file))
                {
                    char char_steps [5];
                    int int_steps;
                    tokeniseRecord(line, ",", step_reading[counter].date, step_reading[counter].time, char_steps);
                    int_steps = atoi(char_steps);
                    if (counter == 0)
                    {
                        step_counter = int_steps;
                    }
                    else if (int_steps < step_counter)
                    {
                        need_counter = counter;
                        step_counter = int_steps;
                    }
                    counter++;
                }
                printf("Fewest Steps: %s %s\n", step_reading[need_counter].date, step_reading[need_counter].time);
                break;
            case 'D':
                counter = 0;
                need_counter = 0; //stores the line of where the fewest steps are
                while(fgets(line, buffer_size, file))
                {
                    char char_steps [5];
                    int int_steps;
                    tokeniseRecord(line, ",", step_reading[counter].date, step_reading[counter].time, char_steps);
                    int_steps = atoi(char_steps);
                    if (int_steps > step_counter)
                    {
                        need_counter = counter;
                        step_counter = int_steps;
                    }
                    counter++;
                }
                printf("Largest Steps: %s %s\n", step_reading[need_counter].date, step_reading[need_counter].time);
                break;
            case 'E':
                counter = 0;
                while(fgets(line, buffer_size, file))
                {
                    char char_steps [5];
                    int int_steps;
                    tokeniseRecord(line, ",", step_reading[counter].date, step_reading[counter].time, char_steps);
                    int_steps = atoi(char_steps);
                    mean = int_steps + mean;
                    counter++;
                }
                mean /= counter;
                printf("Mean Step Count: %d\n", mean);
                break;
            case 'F':
                counter = 0;
                int con = 1;
                while(fgets(line, buffer_size, file))
                {
                    char char_steps [5];
                    int int_steps;
                    tokeniseRecord(line, ",", step_reading[counter].date, step_reading[counter].time, char_steps);
                    int_steps = atoi(char_steps);

                    if (int_steps >= 500 && con == 1)
                    {
                        need_counter++;
                    }
                    else if (int_steps < 500 && con == 1)
                    {
                        if (end - start < need_counter)
                        {
                            end = counter;
                            start = counter - need_counter;
                        }
                        need_counter = 0;
                        con = 0;
                    }
                    else if (int_steps > 500 && con == 0)
                    {
                        con = 1;
                    }
                    counter++;
                }
                printf("Longest Period Start: %s %s\n", step_reading[start].date, step_reading[start].time);
                printf("Longest Period End: %s %s\n", step_reading[end].date, step_reading[end].time);
                break;
            case 'Q':
                return 0;
                break;
            default:
                printf("Invalid choice, try again");
                break;
        }
    }
}