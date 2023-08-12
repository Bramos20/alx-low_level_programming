#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a specified number of letters from a text file and print to the standard output.
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to be read and printed.
 * Return: The actual number of bytes read and printed on success, or 0 if the function fails or the filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_descriptor;
	ssize_t bytes_read;
	ssize_t bytes_written;

	/* Open the file for reading */
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	bytes_read = read(file_descriptor, buffer, letters);

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);
	close(file_descriptor);

	return (bytes_written);
}
