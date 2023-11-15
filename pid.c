#include <stdio.h>
#include <unistd.h>
/*
 * main - pid
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t myPid, parentPid;

	myPid = getpid();
	parentPid = getppid();
	printf("child pid is :%u, Parent pid is : %u\n", myPid, parentPid);

	return (0);
}
