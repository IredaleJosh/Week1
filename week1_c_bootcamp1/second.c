#include <stdio.h>

int main()
{
    int a = 17, i = 2, found = 0;

    while(a != i || found == 1)
    {
        if (a % i == 0)
        {
            printf("Prime");
        }
    }

    if(found == 1)
    {
        printf("Not Prime");
    }

}