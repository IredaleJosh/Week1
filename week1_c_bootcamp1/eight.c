#include <stdio.h>
int main()
{
    float money, temp_p, percentage, years, interest; //can initialise variables of same type in 1 line 
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