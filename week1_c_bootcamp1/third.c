#include <stdio.h>

int main() 
{
    int a, b;
    for (a = 0; a < 10; a+=2)
    {
        b = a + 1;
        printf("%d\n", b);
    }
    return 0;
}


#include <stdio.h>

int main() 
{
    int a = 20;
    while (a >= 0)
    {
        printf("%d\n", a);
        a-=2;
    }
    return 0;
}

#include <stdio.h>

int main() 
{
    int a = 1, b;
    while (a != 11)
    {
        b = a * a;
        printf("%d\n", b);
        a++;
    }
    return 0;
}