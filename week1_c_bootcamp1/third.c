#include <stdio.h>

int main(){
    float length;
    float height;
    float area;

    printf("Enter Length: ");
    scanf("%f", &length);
    printf("Enter Height: ");
    scanf("%f", &height);

    area = length * height;

    printf("Area is %.2f\n", area); // the .2 stops this at 2 decimal places

    return 0;
}