#include <stdio.h>

int main()
{
    int length = 0;
    char b[] = "Hello";

    while (b[length] != '\0')
    {
        length++;

    }

    for (int i = length; i >= 0; i--)
    {
        if(b[i] == '\0')
        {
            printf("\\0   ");
        }
        else
        {
            printf("%c   ", b[i]);
        }
    }

    return 0;
}