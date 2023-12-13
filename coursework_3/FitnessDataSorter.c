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

//Swapping Functions
void int_swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void string_swap(char *a, char *b)
{
    char temp [10];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int main() 
{
    //Variables
    #define buffer_size 100
    char line [buffer_size];
    char filename [buffer_size];
    int counter = 0, counter_2 = 0, size = 0;
    FitnessData Store_Array [buffer_size];
    FitnessData Sort_Array [buffer_size];
    FitnessData read;

    //Get filename
    printf("Enter filename: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, "%s", filename);
    //Open file
    FILE *file = fopen(filename, "r");
    //Check if valid
    if(file == NULL)
    {
        printf("Error: Incorrect File\n");
        return 1;
    }

    //Check if correct format

    //Store into an array
    while(fgets(line, buffer_size, file))
    {
        tokeniseRecord(line, ',', read.date, read.time, &read.steps);
        Store_Array[counter] = read;
        counter++;
    }

    //Sort array
    int swapped = 1;
    for (int i = 0; i < counter - 1; i++)
    {
        swapped = 0; //Starts False
        for (int j = 0; j < (counter - i - 1); j++)
        {
            //if current element bigger than next one, swap all array stuff
            if(Store_Array[j].steps < Store_Array[j + 1].steps)
            {
                int_swap(&Store_Array[j].steps, &Store_Array[j+1].steps); //Swap step
                string_swap(Store_Array[j].time, Store_Array[j+1].time); //Swap time
                string_swap(Store_Array[j].date, Store_Array[j+1].date); //Swap date
                swapped = 1; //Set to True
            }
        }
        if(swapped == 0) //Never becomes true / no swap
        {
            break;
        }
    }

    //Sort into new file with .tsv
    strcat(filename, ".tsv");
    FILE *file_2 = fopen(filename, "w");
    if(file_2 == NULL)
    {
        perror("");
        return 1;
    }

    for(int i = 0; i < counter; i++)
    {
        fprintf(file_2, "%s\t%s\t%d\n", Store_Array[i].date, Store_Array[i].time, Store_Array[i].steps);
    }

    fclose(file_2);
    return 0;
}
