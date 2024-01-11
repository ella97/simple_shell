#include "main.h"
/**
 * _exitshell - Exits shell
 * @text: Argument list
 * @count: Count
 * @h: Head alias
 * Return: 0
*/
int _exitshell(char **text, int count, alias_t **h)
{
	int status = errno;

	if (text[1])
	{
		status = _atoi(text[1]);
		if (status <= 0)
		{
			_exit_error(count, text[1]);
			status = 2;
		}
	}
	_free_alias(h);
	free(text);
	exit(status);
}
