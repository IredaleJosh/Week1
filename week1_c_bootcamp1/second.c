#include <stdio.h>

int is_prime(int a)
{
    int found = 0;
    for (int i = 2; i < a; i++)
    {
        if(a % i == 0)
        {
            return 0;
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        return 1;
    }
}

int main()
{
    int a, b;
    printf("Enter number:");
    scanf("%d", &a);
    b = is_prime(a);
    printf("%d\n", b);

}