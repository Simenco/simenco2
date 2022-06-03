#include <stdio.h>

/**
 * _strlen - function to calculate string length.
 * @s: the string input
 *
 * Return: this return the length on success.
 */

int _strlen(char *s)
{
    int count = 0;
    int i;
    
    for (i = 0; (*(s + i)) != '\0'; i++)
    {
        count += 1;
    }
    return count;
    
}

/**
 * main - the test function
 *
 * Return 0 on success.
 */

int main(void) 
{
    char *str;
    int len;

    str = "My first strlen!";
    len = _strlen(str);
    printf("%d\n", len);
    return (0);
    
}
