#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
    (void)argc; /* Unused parameter */

    /* Print the program name */
    printf("%s\n", argv[0]);

    return 0;
}
