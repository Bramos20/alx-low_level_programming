#include "main.h"

/**
 * read_textfile - Read a text file and print to POSIX stdout
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 * Return: The number of letters read and printed, or 0 if there's an error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	ssize_t read_count, write_count;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDWR);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}
	read_count = read(file_descriptor, buffer, letters);
	if (read_count == -1)
		return (0);

	write_count = write(STDOUT_FILENO, buffer, read_count);
	if (write_count == -1 || read_count != write_count)
		return (0);
	free(buffer);

	close(file_descriptor);
	return (write_count);
}
