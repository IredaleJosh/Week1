#include <stdio.h>

int main(){
    float a;
    float b;
    printf("Enter farenheit: ");
    scanf("%f", &a);
    b = (a - 32) * 5/9;
    printf("The temperature in celcius is %.2f\n", b);
    return 0;
}