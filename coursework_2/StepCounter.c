#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
int record_num, step_counter, counter, need_counter, temp_counter, average, int_steps, start, end;
float temp_mean, mean;

// Global variables for filename and FITNESS_DATA array
#define buffer_size 100
char line [buffer_size];
char filename[buffer_size];
FITNESS_DATA step_reading [100];
char char_steps[5];

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

//Seperate file, called after each option
FILE *openfile(char *filename)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Incorrect filename, try again");
        exit(1);
    }
    else
    {
        printf("File loaded successfully\n");
        return file;
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
        printf("Enter Choice: ");

        //Must use these, otherwise thinks two characters are inputted
        option = getchar();
        while (getchar() != '\n');

        //Options - make a function
        switch (option)
        {
            case 'A':
                //Get filename
                printf("Input Filename: ");
                fgets(line, buffer_size, stdin);
                sscanf(line, " %s ", filename);
                //Open file if possible
                FILE *file = openfile(filename);

                break;
            case 'B':
                record_num = 0;
                while(fgets(line, buffer_size, file))
                {
                    record_num = record_num + 1;
                }
                
                printf("Total records: %d\n", record_num);
                file = openfile(filename);
                break;
            case 'C':
                counter = 0;
                need_counter = 0; //stores the line of where the fewest steps are
                while(fgets(line, buffer_size, file))
                {
                    tokeniseRecord(line, ",", step_reading[counter].date, step_reading[counter].time, char_steps);
                    printf("%s\n", step_reading[counter].date);
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

                printf("Fewest steps: %s %s\n", step_reading[need_counter].date, step_reading[need_counter].time);
                file = openfile(filename);
                break;
            case 'D':
                counter = 0;
                need_counter = 0; //stores the line of where the fewest steps are
                while(fgets(line, buffer_size, file))
                {
                    tokeniseRecord(line, ",", step_reading[counter].date, step_reading[counter].time, char_steps);
                    int_steps = atoi(char_steps);
                    if (int_steps > step_counter)
                    {
                        need_counter = counter;
                        step_counter = int_steps;
                    }
                    counter++;
                }
                printf("Largest steps: %s %s\n", step_reading[need_counter].date, step_reading[need_counter].time);
                file = openfile(filename);
                break;
            case 'E':
                counter = 0;
                mean = 0;
                while(fgets(line, buffer_size, file))
                {
                    tokeniseRecord(line, ",", step_reading[counter].date, step_reading[counter].time, char_steps);
                    int_steps = atoi(char_steps);
                    mean = int_steps + mean;
                    counter++;
                }
                //Calc and round mean
                average = mean / counter;
                temp_mean = (mean/(float)counter) - average;
                if(temp_mean >= 0.5)
                {
                    average++;
                }

                printf("Mean step count: %d\n", average);
                file = openfile(filename);
                break;
            case 'F':
                counter = 0;
                need_counter = 0;
                temp_counter = 0;
                while(fgets(line, buffer_size, file))
                {
                    tokeniseRecord(line, ",", step_reading[counter].date, step_reading[counter].time, char_steps);
                    int_steps = atoi(char_steps);

                    if(int_steps > 500)
                    {
                        need_counter++;
                    }
                    else if (int_steps <= 500)
                    {
                        //Set pointers when new period > previous
                        if(need_counter > temp_counter)
                        {
                            temp_counter = need_counter;
                            //As previous one would be >500
                            end = counter - 1;
                            start = counter - need_counter;
                        }
                        need_counter = 0;
                    }
                    counter++;                    
                }

                printf("Longest period start: %s %s\n", step_reading[start].date, step_reading[start].time);
                printf("Longest period end: %s %s\n", step_reading[end].date, step_reading[end].time);
                file = openfile(filename);
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