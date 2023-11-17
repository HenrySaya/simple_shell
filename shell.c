#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *cmd;
	char *token;

	while (true)
	{
		promptDisplay();
		cmd = read_cmd();

		token = strtok(cmd, " ");

		while (token != NULL)
		{
			execute(token);
			token = strtok(NULL, " ");
		}

		free_cmd(cmd);
	}
	return (0);
}
