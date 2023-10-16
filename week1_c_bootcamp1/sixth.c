#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    while (a != -1)
    {
        printf("Enter a number: ");
        scanf("%d", &a);
        if((a < 0 || a > 100) && a != -1)
        {
            printf("The number must be between 0 and 100\n");
        }
    }
    printf("Terminate Program\n");
    return 0;
}