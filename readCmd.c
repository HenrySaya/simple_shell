#include "shell.h"
/**
 * read_cmd - function gets the command from input
 *
 * Return: Always void;
 */
char *read_cmd(void)
{
	char *cmd = NULL;
	size_t len = 0;

	if (getline(&cmd, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	/*Remove the newline character*/
	cmd[strcspn(cmd, "\n")] = '\0';

	return (cmd);
}
/**
 * free_cmd - Free the memory allocated for the command
 *
 * @cmd: command to be freed from memory
 */
void free_cmd(char *cmd)
{
	    free(cmd);
}
