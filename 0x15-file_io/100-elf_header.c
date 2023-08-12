#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verify_elf(unsigned char *magic_numbers);
void print_magic_numbers(unsigned char *magic_numbers);
void print_class_info(unsigned char *magic_numbers);
void print_data_info(unsigned char *magic_numbers);
void print_version_info(unsigned char *magic_numbers);
void print_abi_info(unsigned char *magic_numbers);
void print_osabi_info(unsigned char *magic_numbers);
void print_type_info(unsigned int e_type, unsigned char *magic_numbers);
void print_entry_point(unsigned long int e_entry, unsigned char *magic_numbers);
void close_elf_descriptor(int elf_descriptor);

/**
 * verify_elf - Checks if a file is in ELF format.
 * @magic_numbers: A pointer to an array containing ELF magic numbers.
 *
 * Description: Exits with code 98 if the file is not in ELF format.
 */
void verify_elf(unsigned char *magic_numbers)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (magic_numbers[index] != 127 &&
		    magic_numbers[index] != 'E' &&
		    magic_numbers[index] != 'L' &&
		    magic_numbers[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic_numbers - Prints the ELF magic numbers.
 * @magic_numbers: A pointer to an array containing ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic_numbers(unsigned char *magic_numbers)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", magic_numbers[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/* ... Other print functions ... */

/**
 * close_elf_descriptor - Closes an ELF file descriptor.
 * @elf_descriptor: The file descriptor of the ELF file.
 *
 * Description: Exits with code 98 if the file cannot be closed.
 */
void close_elf_descriptor(int elf_descriptor)
{
	if (close(elf_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf_descriptor);
		exit(98);
	}
}

/**
 * main - Displays information from the ELF header of a given file.
 * @argc: The number of arguments provided to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 98 if the file is not an ELF file or fails.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_descriptor, read_status;

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_descriptor(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	read_status = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_status == -1)
	{
		free(header);
		close_elf_descriptor(file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	verify_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic_numbers(header->e_ident);
	/* ... Other print function calls ... */

	free(header);
	close_elf_descriptor(file_descriptor);
	return (0);
}
