#include <stdio.h>

int is_Prime(int a) //need * for passing pointers, more on slides
{
    int i = 2;
    int b = 0;
    while (i != 9)
    {
        if(a % i == 0)
        {
            b = 1;
        }
        else
        {
            i++;
        }
    }
    return b;
}

int main() 
{
    int a;
    printf("Enter an integer: ");
    scanf("%d\n", &a);
    int prime = is_Prime(a);
    if(prime == 1)
    {
        printf("The integer %d is prime", a);
    }
    else
    {
        printf("The integer %d is NOT prime", a);
    }
    return 0;
}