    int a;
    printf("Enter an mark: ");
    scanf("%d", &a);
    if(a >= 40)
    {
        printf("The mark of %d is a pass\n", a);
    }
    else
    {
        printf("The mark of %d is a fail\n", a);
    }
    return 0;

    int a = 2;
    switch (a)
    {
        case 2: printf ("Option 0 has been selected\n");
        break; 

        case 0: printf ("Option 1 has been selected\n");
        break;

        default: printf ("A different option has been selected\n");
    }


Bronze
#include <stdio.h>

int main()
{
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);
    if(a > 0)
    {
        printf("The integer %d is positive\n", a);
    }
    else if (a < 0)
    {
        printf("The integer %d is negative\n", a);
    }
    else
    {
        printf("The integer is zero\n");
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    if(a % 5 == 0 && a % 4 == 0)
    {
        printf("The number %d is divisble by both 4 and 5\n", a);
    }
    else
    {
        printf("The number is not divisible by both 4 and 5\n");
    }
    return 0;
}

Silver
#include <stdio.h>

int main()
{
    int a;
    printf("Enter a mark: ");
    scanf("%d", &a);
    if(a >= 70)
    {
        printf("The mark of %d means you earned distinction\n", a);
    }
    else if (a < 70 && a >= 50)
    {
        printf("The mark of %d means you earned a pass\n", a);
    }
    else
    {
        printf("The mark of %d means you failed\n", a);
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int a;
    printf("Enter a temperature in celcius: ");
    scanf("%d", &a);
    if(a >= -10 && a <= 40)
    {
        printf("The temperature of %d is valid\n", a);
    }
    else
    {
        printf("The temperature of %d is invalid\n", a);
    }
    return 0;
}

Gold
#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number between 1 and 5 to choose an option: ");
    scanf("%d", &a);
    switch (a)
    {
        case 1: printf("You chose option 1\n");
        break;

        case 2: printf("You chose option 2\n");
        break;

        case 3: printf("You chose option 3\n");
        break;

        case 4: printf("You chose option 4\n");
        break;

        case 5: printf("You chose option 5\n");
        break;

        default: printf("Invalid option chosen\n");
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    if(a == -1)
    {
        printf("Terminate Program\n");
    }
    else if(a < 0 || a > 100)
    {
        printf("Please enter a number between 0 and 100\n");
    }
    else
    {
        main();
    }

    return 0;
}

OR

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

Week 1 Wk 2
#include <stdio.h>

int main() 
{
    int a [5];
    int length = 0;
    int sum = 0;
    int i;
    int b;

    for(i = 0; i < 5; i++)
    {
        printf("Enter an integer: ");
        scanf("%d", &b);
        a[i] = b;
    }

    while(length != 5)
    {
        sum = sum + a[length];
        length++;
    }
    printf("The sum of the array is %d\n", sum);
    return 0;
}

#include <stdio.h>

int main() 
{
    int a [5];
    int length = 4;
    int reverse;
    int i;
    int b;

    for(i = 0; i < 5; i++)
    {
        printf("Enter an integer: ");
        scanf("%d", &b);
        a[i] = b;
    }

    while(length != -1)
    {
        reverse = a[length];
        printf("%d\n", reverse);
        length--;
    }
}

#include <stdio.h>

int main() 
{
    int a [5];
    int length = 0;
    int max;
    int i;
    int b;

    for(i = 0; i < 5; i++)
    {
        printf("Enter an integer: ");
        scanf("%d", &b);
        a[i] = b;
    }

    while(length != 5)
    {
        if(a[length] > max)
        {
            max = a[length];
        }
        length++;
    }
    printf("The largest number in the array is %d\n", max);
}

#include <stdio.h>

int main() 
{
    int a [5];
    int c [5];
    int length = 0;
    int temp;
    int i;
    int b;

    for(i = 0; i < 5; i++)
    {
        printf("Enter an integer: ");
        scanf("%d", &b);
        a[i] = b;
    }

    while(length != 5)
    {
        temp = a[length];
        if (length == 4)
        {
            c[0] = temp;
        }
        c[length + 1] = temp;
        length++;
    }
    printf("%d, %d, %d, %d, %d\n", c[0], c[1], c[2], c[3], c[4]);
}

#include <stdio.h>

int main() 
{
    int a [6];
    int length = 0;
    int width = 0;
    int value = 0;
    int i;
    int b = 0;

    for(i = 0; i < 6; i++)
    {
        printf("Enter an integer: ");
        scanf("%d", &b);
        a[i] = b;
    }

    while(length != 6)
    {
        width = 0;
        while (width != 6)
        {
            if(a[length] == a[width] && length != width)
            {
                printf("The values %d and %d match\n", a[length], a[width]);
                value = a[length];
                printf("%d\n", value);
            }
            width++;
        }
        length++;
    }
    printf("The value %d is repeated\n", value);
}

