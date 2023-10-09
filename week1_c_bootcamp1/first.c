#include <stdio.h>
int main() {
    float a;
    float new_a;
    float dis;
    printf("Enter number of days: ");
    scanf("%d", &a);
    new_a = a * 8640;
    dis = 300000000 * new_a;
    printf("The distance is %d\n", dis);
    return 0;
}