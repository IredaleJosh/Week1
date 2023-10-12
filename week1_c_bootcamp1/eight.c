#include <stdio.h>
int main()
{
    float money;
    float temp_p;
    float percentage;
    float years;
    float interest;
    printf("Enter money: ");
    scanf("%f", &money);
    printf("Enter percentage: ");
    scanf("%f", &percentage);
    printf("Enter years: ");
    scanf("%f", &years);
    temp_p = percentage / 100;
    interest = money * temp_p* years;
    printf("The simple interest is %.2f\n", interest);
    return 0;
}