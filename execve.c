#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int wstatus;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for(int i = 0; i < 5; ++i)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("ERROR: ");
			return (-1);
		}
		if (pid == 0)
			execve(argv[0], argv, NULL);
		else
			wait(&wstatus);
	}

	return (0);
}
