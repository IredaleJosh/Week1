#include <stdio.h>
int main() {
    int a;
    int new_a;
    int dis;
    printf("Enter number of days: ");
    scanf("%d", &a);
    new_a = a * 24 * 3600;
    dis = 300000000 * new_a;
    printf("The distance is %d\n", dis);
    return 0;
}