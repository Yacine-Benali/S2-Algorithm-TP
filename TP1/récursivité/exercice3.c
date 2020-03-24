#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char str[], int index, int size)
{
    int middle;

    middle = (size / 2);

    if (index > middle)
    {
        return true;
    }
    else
    {
        if (str[index] != str[size - index])
        {
            return false;
        }
        else
        {
            index++;
            isPalindrome(str, index, size);
        }
    }
}

int main()
{

    char str[50];
    
    printf("enter the word:");
    int size = strlen(str);

    bool result = isPalindrome(str, 0, size - 1);

    if (result)
    {
        printf("the word is palindrome");
    }
    else
    {
        printf("the word is not palindrome");
    }
}