#include <stdio.h>
int main() {
    double a;
    double new_a;
    double dis;
    printf("Enter number of days: ");
    scanf("%d", &a);
    new_a = a * 8640;
    dis = 300000000 * new_a;
    printf("The distance is %d\n", dis);
    return 0;
}