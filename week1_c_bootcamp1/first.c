#include <stdio.h>
int main() {
    int a;
    int b;
    printf("Enter an integer: ");
    scanf("%d", &a);
    for (i = 0; i < a; i++){
        b = b * i;
    }
    printf("The factorial of %d is %d\n", a, b);
    return 0;
}