#include <stdio.h>
int main() {
    float a;
    float b = 3.641;
    float c; //changed to float, as int is whole numbers

    a = 2.897;
    c = a + b;

    printf ("The sum of adding %f and %f is %f\n", a, b, c); //must change from d to f, as float data type

    return 0;
}