#include <stdio.h>

int main(){
    int a;
    int b;
    int tempa;
    int tempb;

    printf("Enter first integer: ");
    scanf("%d", &a);
    printf("Enter second integer: ");
    scanf("%d", &b);
    tempb = a;
    tempa = b;
    printf("The first integer is %d and the second integer is %d", tempa, tempb);
    return 0;
}