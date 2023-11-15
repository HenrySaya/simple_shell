#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100

void promptDisplay(void);
void execute(const char *line);
void readCmd(char *line, size_t size);

#endif
