#include <stdio.h>

int str_len(char *word)
{
    int count = 0;
    while(word [count] != '\0')
    {
        count++;
    }
    return count;
}

int main() 
{
    char word [] = "People";
    int length = str_len(word);
    printf("The length of the word is %d\n", length);
    return 0;
}