#include <stdio.h>
int main() {
    int a;
    int b;
    int c;
    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("Enter another integer: ");
    scanf("%d", &b);
    c = a + b;
    printf("the sum of %f and %f is %d\n", a, b, c);

}