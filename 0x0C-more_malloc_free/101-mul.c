#include "main.h"

int _putchar(char c);
int string_length(char *str);
int string_to_int(char *str);
void print_number(int num);
void print_error();

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Exit status of the program
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
        print_error();

    char *num1_str = argv[1];
    char *num2_str = argv[2];

    int num1_length = string_length(num1_str);
    int num2_length = string_length(num2_str);

    // Validate num1_str consists of digits
    for (int i = 0; i < num1_length; i++) {
        if (num1_str[i] < '0' || num1_str[i] > '9')
            print_error();
    }

    // Validate num2_str consists of digits
    for (int i = 0; i < num2_length; i++) {
        if (num2_str[i] < '0' || num2_str[i] > '9')
            print_error();
    }

    int num1 = string_to_int(num1_str);
    int num2 = string_to_int(num2_str);

    int result = num1 * num2;

    print_number(result);
    _putchar('\n');

    exit(0);
}

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: On success, the character written. On error, -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * string_length - Calculates the length of a string
 * @str: Pointer to the string
 *
 * Return: Length of the string
 */
int string_length(char *str)
{
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

/**
 * string_to_int - Converts a string representation of an integer to an actual integer value
 * @str: Pointer to the string representation of the integer
 *
 * Return: Integer value of the string
 */
int string_to_int(char *str)
{
    int num = 0;
    while (*str != '\0') {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

/**
 * print_number - Prints an integer digit by digit
 * @num: Integer to be printed
 */
void print_number(int num)
{
    if (num == 0) {
        _putchar('0');
        return;
    }
    if (num < 0) {
        _putchar('-');
        num = -num;
    }
    if (num / 10 != 0)
        print_number(num / 10);
    _putchar(num % 10 + '0');
}

/**
 * print_error - Prints the error message and exits with a status of 98
 */
void print_error()
{
    char error_message[] = "Error\n";
    char *ptr = error_message;
    while (*ptr != '\0') {
        _putchar(*ptr);
        ptr++;
    }
    exit(98);
}
