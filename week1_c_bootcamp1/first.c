#include <stdio.h> //library
int main() {
    int age;

    printf("Hello, please enter your age: ");
    scanf("%d", &age); // scanf takes user inputs, & -> address of operator, check slides
    printf("Your age is %d\n", age); // \n is the "newline" character
    
    return 0;
}