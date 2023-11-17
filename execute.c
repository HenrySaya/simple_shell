#include "shell.h"

/**
 * execute - Forks a process and executes the command.
 * @cmd: The command to execute.
 *
 * Return: Always void
 */
void execute(const char *cmd)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *const argv[] = { (char *)cmd, NULL };
		char *const envp[] = { NULL };

		if (execve(cmd, argv, envp) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
		/* Parent process */
		waitpid(pid, &status, 0);
}
