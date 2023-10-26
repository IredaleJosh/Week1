#include <stdio.h>

int str_len(char *str_1, char *str_2)
{
    int count = 0;
    while(str_1 [count] != '\0')
    {
        count++;
    }
    return count;

    while(str_2 [count] != '\0')
    {
        count++;
    }
    return count;
}

char conc(char *str_1, char *str_2, int total)
{
    char str_3 [total];
    int count = 0;

    for(int i = 0; i < total; i++)
    {
        if(str_1[i] == '\0')
        {
            str_3[i] = str_2[count];
            count ++;
        }
        else
        {
            str_3[i] = str_1[i];
        }
    }

    return *str_3;
}

int main ()
{
    char str_1 [] = "Hell";
    char str_2 [] = "World";

    int len_1 = str_len(str_1, str_2);
    int len_2 = str_len(str_2, str_2);
    int total = len_1 + len_2;
    char str_4 [total];

    str_4 = conc(str_1, str_2, total);
}