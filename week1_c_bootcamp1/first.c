#include <stdio.h>
int main() {
    int a;
    int new_a;
    int dis;
    printf("Enter number of days: ");
    scanf("%d", &a);
    new_a = a * 8640;
    dis = 3 * 10^8 * new_a;
    printf("The distance is %d\n", dis);
    return 0;
}