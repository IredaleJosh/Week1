#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d\n", &a);
    
    for (int i = 2; i < a; i++)
    {
        if(a % i == 0)
        {
            printf("Prime");
        }
        else
        {
            printf("Not Prime");
        }
    }
}