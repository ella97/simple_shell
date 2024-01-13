#include "main.h"
/**
 * _prompt - Displays prompt
 * @mode: Checks kind of terminal
 * @line: Entered line
 * @ls: Alias list
 * Return: Entered input
*/
void _prompt(int mode, char **line, alias_t **ls)
{
	size_t line_cap = 0;
	int line_length = 0;

	if (mode == 1)
		write(1, "$ ", 2);
	line_length = _get_line(line, &line_cap, stdin);
	if (line_length == -1)
	{
		_free_alias(ls);
		exit(errno);
	}
}

/**
 * _get_line - Gets entered line
 * @line_ptr: Entered line
 * @line_cap: Line limit
 * @file_stream: File stream
 * Return: Length of line
*/

int _get_line(char **line_ptr, size_t *line_cap, FILE *file_stream)
{
	char ch = '0', *str;
	ssize_t fd, st;
	static size_t val;

	if (line_ptr == NULL || line_cap == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	str = malloc((*line_cap = *line_cap + 1) * sizeof(char));
	if (!str || val != 0)
		return (-1);
	fflush(file_stream);

	for (; ch != '\n'; val++)
	{
		fd = read(STDIN_FILENO, &ch, 1);
		if (fd == -1 || (fd == 0 && val == 0))
		{
			free(str);
			return (-1);
		}
		str[val] = ch;
		if (val == (*line_cap - 1))
		{
			str = _realloc(str, *line_cap, (*line_cap + 2));
			*line_cap += 2;
		}
	}
	str[val] = '\n';
	str[val++] = '\0';
	*line_ptr = str;

	st = val;
	if (st != 0)
		val = 0;

	return (st);
}

/**
 * _realloc - Reallocates memory
 * @ptr: Memory allocated
 * @old_size: Initial size
 * @new_size: New size
 * Return: Nothing
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ar, *tmp;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	ar = malloc(new_size);
	if (!ar)
		return (NULL);

	tmp = ptr;

	if (new_size > old_size)
		for (i = 0; i < old_size; i++)
			ar[i] = tmp[i];

	if (new_size < old_size)
		for (i = 0; i < new_size; i++)
			ar[i] = tmp[i];

	free(ptr);
	return (ar);
}

/**
 * _free_alias - frees a list_t list
 * @head: Beginning of the list
 * Return: Nothing
*/

void _free_alias(alias_t **head)
{
	alias_t *nextNode, *currentNode;

	if (head == NULL)
		return;
	currentNode = *head;
	while (currentNode)
	{
		nextNode = currentNode->next;
		free(currentNode->name);
		free(currentNode->val);
		free(currentNode);
		currentNode = nextNode;
	}
	*head = NULL;
}

