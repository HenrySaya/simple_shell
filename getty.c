#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char **argv) 
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");
    read = getline(&line, &len, stdin);

    if (read != -1) 
    {
        execve(argv[0], argv, NULL);
	printf("$ ");
    }
    else 
    {
        perror("getline");
    }

    free(line);

    return (0);
}
