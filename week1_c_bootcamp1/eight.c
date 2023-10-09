#include <stdio.h>
int main()
{
    float money;
    float percentage;
    float years;
    float interest;
    printf("Enter money: ");
    scanf("%f", &money);
    printf("Enter percentage: ");
    scanf("%f", &percentage);
    printf("Enter years: ");
    scanf("%f", &years);
    interest = money * percentage * years;
    printf("The simple interest is %.2f\n", interest);
    return 0;
}