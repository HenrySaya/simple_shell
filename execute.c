#include "shell.h"

/**
 * execute - Forks a process and executes the command.
 * @cmd: The command to execute.
 *
 * Return: Always void
 */
void execute(const char *cmd)
{
	pid_t pid;
	int status;

	char *const envp[] = { NULL };

	pid = fork();

	if (pid == -1)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char **argv = malloc(sizeof(char *) * 2);

		if (argv == NULL)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}

		argv[0] = (char *)cmd;
		argv[1] = NULL;

		if (execve(cmd, argv, envp) == -1)
		{
			perror("./hsh");
			free(argv);
			exit(EXIT_FAILURE);
		}

		free(argv);
	}
	else
		/* Parent process */
		waitpid(pid, &status, 0);
}
