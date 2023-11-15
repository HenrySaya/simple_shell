#include "shell.h"

/**
 * execute - Forks a process and executes the command.
 * @line: The command to execute.
 *
 * Return: Always void
 */
void execute(const char *line)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(line, line, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

}
