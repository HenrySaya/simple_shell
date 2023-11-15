#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t tokenize(char *str, char *delim)
{
	size_t words_count = 0;

	if (strtok(str, delim))
			++words_count;
	while (strtok(NULL, delim))
			++words_count;

	return (words_count);
}

char **words_list(char *str, char *delim)
{
	char **arr = NULL;
	size_t arr_iter = 0;
	size_t arr_size = 0;
	size_t str_size = strlen(str);
	size_t str_iter;
	char prev_char = '\0';

	if ((arr_size = tokenize(str, delim)) > 0)
	{
		arr = malloc(sizeof(char *) * (arr_size + 1));
		if  (arr == NULL)
			exit(EXIT_FAILURE);

		for (str_iter = 0; str_iter < str_size; ++str_iter)
		{
			if (str[str_iter] != '\0' && prev_char == '\0')
			{
				arr[arr_iter] = str + str_iter;
				++arr_iter;
			}

			prev_char = str[str_iter];
		}

		arr[arr_iter] = NULL;
	}

	return (arr);
}

int main(void)
{
	char *str = strdup("Hello Dad1");
	char **arr = words_list(str, " ");
	int i;

	for (i = 0; arr[i] != NULL; ++i)
		printf("%s\n", arr[i]);

	return (0);
}
