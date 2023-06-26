#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 6

void generate_password(char *password, int length)
{
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;

    for (i = 0; i < length; i++)
    {
        int index = rand() % (sizeof(charset) - 1);
        password[i] = charset[index];
    }

    password[length] = '\0';
}
