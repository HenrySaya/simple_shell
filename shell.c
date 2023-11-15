#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char line[MAX_COMMAND_LENGTH];

	while (true)
	{
		promptDisplay();
		readCmd(line, sizeof(line));
		execute(line);
	}
	return (0);
}
