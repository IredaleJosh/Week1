#include "utilities.h"

int option_menu(char *filename)
{
    while (1)
    {
        char choice;
        int counter = 0;
        float lowest_blood, highest_blood, mean;
        // array of daily readings
        reading daily_readings[100];
        //Call open file function
        FILE *input = open_file(filename);

        printf("Select an option to perform on the file\n");
        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            display_file(daily_readings, counter, input);
            break;

        case 'B':
        case 'b':
            mean = find_mean(daily_readings, counter, input);
            break;

        case 'C':
        case 'c':
            highest_blood = find_highest(daily_readings, counter, input);
            break;

        case 'D':
        case 'd':
            lowest_blood = find_lowest(daily_readings, counter, input);
            break;

        case 'E':
        case 'e':
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

int main()
{
    // get filename from the user
    printf("Please enter the name of the data file: ");
    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    //Function that performs the options
    option_menu(filename);
}