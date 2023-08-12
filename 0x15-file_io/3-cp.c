#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *filename);
void close_descriptor(int fd);

/**
 * allocate_buffer - Allocates memory for a buffer to store file contents.
 * @filename: The name of the file for which the buffer is allocated.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Unable to allocate buffer for %s\n", filename);
		exit(99);
	}

	return (buffer);
}

/**
 * close_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_descriptor(int fd)
{
	int close_status;

	close_status = close(fd);

	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to command-line arguments.
 *
 * Return: 0 on success, exit codes for errors.
 *
 * Description: Exits with code 97 if arguments are incorrect.
 * Exits with code 98 if source file cannot be read.
 * Exits with code 99 if destination file cannot be written to.
 * Exits with code 100 if file descriptors cannot be closed.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd, read_status, write_status;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_status = read(source_fd, buffer, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_fd == -1 || read_status == -1)
		{
			dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_status = write(dest_fd, buffer, read_status);
		if (dest_fd == -1 || write_status == -1)
		{
			dprintf(STDERR_FILENO, "Error: Unable to write to file %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_status = read(source_fd, buffer, 1024);
		dest_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_status > 0);

	free(buffer);
	close_descriptor(source_fd);
	close_descriptor(dest_fd);

	return (0);
}
