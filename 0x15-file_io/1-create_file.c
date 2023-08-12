#include "main.h"

/**
 * create_file - Create a file with read/write access for the user
 * @filename: Name of the file to create
 * @text_content: String to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, i;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_descriptor == -1)
		return (-1);

	if (text_content)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;
		write_status = write(file_descriptor, text_content, i);
		if (write_status == -1)
			return (-1);
	}

	close(file_descriptor);
	return (1);
}
