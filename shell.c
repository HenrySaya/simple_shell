#include "shell.h"
/**
 * get_user_input - Handles printing the shell prompt and getting user input.
 * @line: Pointer to the buffer for user input.
 * @len: Pointer to the size of the buffer.
 *
 * Return: The number of characters read (including the newline character),
 *         or -1 on failure.
 */
ssize_t get_user_input(char **line, size_t *len)
{
	printf("#cisfun$ ");
	return (getline(line, len, stdin));
}

/**
 * fork_and_execute - Forks a process and executes the command.
 * @line: The command to execute.
 *
 * Return: The process ID (PID) of the child process.
 */
pid_t fork_and_execute(char *line)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		char *argv[] = {line, NULL};

		if (execve(line, argv, NULL))
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}

	return (pid);
}

/**
 * wait_for_child - Waits for the child process to complete.
 * @pid: The process ID (PID) of the child process.
 * @wstatus: Pointer to store the exit status of the child process.
 */

void wait_for_child(pid_t pid, int *wstatus)
{
	waitpid(pid, wstatus, 0);
}

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int wstatus;

	while (1)
	{
		read = get_user_input(&line, &len);

		if (read == EOF)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline: ");
				break;
			}
		}

		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}

		pid = fork_and_execute(line);
		wait_for_child(pid, &wstatus);
	}

	free(line);

	return (0);
}

