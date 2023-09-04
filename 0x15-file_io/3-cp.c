#include "main.h"

#define BUFFER_SIZE 1204
#define STDERR_FILE_DESCRIPTOR STDERR_FILENO

/**
 * main - Create the copy bash script
 * @argc: Argument count
 * @argv: Arguments as strings
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int input_file_descriptor, output_file_descriptor, read_status, write_status;
	char buffer[BUFFER_SIZE];
	mode_t file_permissions;

	file_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		dprintf(STDERR_FILE_DESCRIPTOR, "Usage: cp file_from file_to\n"), exit(97);

	input_file_descriptor = open(argv[1], O_RDONLY);
	if (input_file_descriptor == -1)
		dprintf(STDERR_FILE_DESCRIPTOR, "Error: Can't read from file %s\n", argv[1]), exit(98);

	output_file_descriptor = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, file_permissions);
	if (output_file_descriptor == -1)
		dprintf(STDERR_FILE_DESCRIPTOR, "Error: Can't write to %s\n", argv[2]), exit(99);

	do {
		read_status = read(input_file_descriptor, buffer, BUFFER_SIZE);
		if (read_status == -1)
		{
			dprintf(STDERR_FILE_DESCRIPTOR, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		if (read_status > 0)
		{
			write_status = write(output_file_descriptor, buffer, (ssize_t)read_status);
			if (write_status == -1)
			{
				dprintf(STDERR_FILE_DESCRIPTOR, "Error: Can't write to %s\n", argv[2]);
				exit(99);
			}
		}
	} while (read_status > 0);

	read_status = close(input_file_descriptor);
	if (read_status == -1)
		dprintf(STDERR_FILE_DESCRIPTOR, "Error: Can't close fd %d\n", input_file_descriptor), exit(100);

	write_status = close(output_file_descriptor);
	if (write_status == -1)
		dprintf(STDERR_FILE_DESCRIPTOR, "Error: Can't close fd %d\n", output_file_descriptor), exit(100);

	return (0);
}
