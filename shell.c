#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *cmd;

	while (true)
	{
		promptDisplay();
		cmd = read_cmd();
		execute(cmd);

		free_cmd(cmd);
	}
	return (0);
}
