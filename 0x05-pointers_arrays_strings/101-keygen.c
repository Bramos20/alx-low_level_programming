#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 6

void generate_password(char *password, int length);

int main(void)
{
    char password[PASSWORD_LENGTH + 1];
    int attempts = 0;

    srand(time(NULL));

    do
    {
        generate_password(password, PASSWORD_LENGTH);
        printf("Attempt #%d: %s\n", attempts + 1, password);
        attempts++;
    } while (strcmp(password, "A-<8t4") != 0);

    printf("Password cracked after %d attempts!\n", attempts);

    return 0;
}

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
