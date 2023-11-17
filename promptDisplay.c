#include "shell.h"
/**
 * promptDisplay - default text to display
 *
 * Return: Always void
 */
void promptDisplay(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
