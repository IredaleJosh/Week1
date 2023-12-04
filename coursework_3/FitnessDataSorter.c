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
//2) and sort data into descending order (if same step count, be
//consecutive but order doesn't matter)
//3) write data to filename of same name, with file extenstion .tsv and return 0



// int comparator(const void *a, const void *b)
// {
//     FitnessData *FitnessData_A = (FitnessData *)a;
//     FitnessData *FitnessData_B = (FitnessData *)b;
//     return (FitnessData_A-> steps - FitnessData_B-> steps);
// }

    void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
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
            //if current element bigger than next one
            if(Store_Array[j].steps > Store_Array[j + 1].steps)
            {
                swap(&Store_Array[j].steps, &Store_Array[j+1].steps); //Swap steps
                //Swap Time
                //Swap Date
                swapped = 1; //Set to True
            }
        }
        if(swapped == 0) //Never becomes true / no swap
        {
            break;
        }
    }

    for(int i; i < counter; i++)
    {
        printf("%s %s %d\n", Store_Array[i].date, Store_Array[i].time, Store_Array[i].steps);
    }



    //Sort into new file with .tsv

    return 0;

}
