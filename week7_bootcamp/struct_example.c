#include <stdio.h>

typedef struct
{
    char date[20];
    float bloodIron;
} reading; 

//create a single instance called "today"
reading today;

//create array with 7 elements to store a weeks worth of readings
reading week[7];

//Asks for inputs and prints them
int main()
{
    reading new_reading = {};
    printf("Enter date: ");
    scanf("%s", new_reading.date);
    printf("Enter blood iron: ");
    scanf("%f", &new_reading.bloodIron); //need the "&" for numbers
    printf("Date: %s\n", new_reading.date);
    printf("Blood Iron: %f\n", new_reading.bloodIron);
    return 0;
}