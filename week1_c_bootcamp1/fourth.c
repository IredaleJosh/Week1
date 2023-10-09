#include <stdio.h>

int main() {
    
    float radius;
    float pi = 3.14;
    float area;

    printf("Enter Radius: ");
    scanf("%f", &radius);

    area = radius * radius * pi;

    printf("Area is %.2f\n", area); // the .2 stops this at 2 decimal places

    return 0;
}