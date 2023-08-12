#include "main.h"

/**
 * append_text_to_file - Append text to the end of a file
 * @filename: Name of the file
 * @text_content: String to be added to the end of the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, i;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);

	file_descriptor = open(filename, O_APPEND | O_WRONLY);
	if (file_descriptor == -1)
		return (-1);

	for (i = 0; text_content[i] != '\0'; i++)
		;
	write_status = write(file_descriptor, text_content, i);
	if (write_status == -1)
		return (-1);

	close(file_descriptor);
	return (1);
}
