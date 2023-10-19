Bronze

#include <stdio.h>

int circle_area(float radius)
{
    float area = radius * radius * 3.14;
    return area;
}

int main() 
{
    float radius = 6.45;
    float answer = circle_area(radius);
    printf("Answer is %.2f\n", answer);
    return 0;
}

#include <stdio.h>

int sphere_volume(float radius)
{
    float volume = radius * radius * radius * 3.14 * 4/3;
    return volume;
}

int main() 
{
    float radius = 6.45;
    float answer = sphere_volume(radius);
    printf("Answer is %.2f\n", answer);
    return 0;
}


Silver

#include <stdio.h>

int str_len(char word)
{
    int count = 0;
    while(word[count] != '\0')
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

