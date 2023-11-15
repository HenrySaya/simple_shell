#include "shell.h"
/**
 * readCmd - function gets the command from input
 * @line: command to be executed
 * @size: length of the command
 *
 * Return: Always void;
 */
void readCmd(char *line, size_t size)
{
	if (fgets(line, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
	/* Remove any newline in the command*/
	line[strcspn(line, "\n")] = '\0';
}
