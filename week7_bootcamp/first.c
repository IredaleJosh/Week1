#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int array_1[3][4];
    int array_2[3][4];
    int array_3[3][4];
    int i, j;

    //seed the random num gen
    srand(time(NULL));

    //fill array
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            array_1[i][j] = rand() % 11;
            array_2[i][j] = rand() % 11;
        }
    }

    //print array
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            array_3[i][j] = array_1[i][j] * array_2[i][j];
            printf("%d ", array_3[i][j]);
        }
        printf("\n");
    }
    return 0;
}