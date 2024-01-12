#include "main.h"
/**
 * _tokenizer - Splits the entered string
 * @s: Array of string characters
 * @sep: Seperator
 * Return: Array of each word in string
 */
char **_tokenizer(char *s, char *sep)
{
	int n = 0;

	char **arr, *token;

	arr = malloc(30 * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	token = _strtok(s, sep);
	while (token != NULL)
	{
		arr[n] = token;
		token = _strtok(NULL, sep);
		n++;
	}
	arr[n] = NULL;
	return (arr);
}

/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @sep: seperator
 * Return: Token or Null
 */
char *_strtok(char *str, char *sep)
{
	static char *ptr_str;

	char *ret;

	if (!str)
		str = ptr_str;
	if (!str)
		return (NULL);
	while (1)
	{
		if (_delim(*str, sep))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}
	ret = str;
	while (1)
	{
		if (*str == '\0')
		{
			ptr_str = str;
			return (ret);
		}
		if (_delim(*str, sep))
		{
			*str = '\0';
			ptr_str = str + 1;
			return (ret);
		}
		str++;
	}
}

/**
 * _delim - checks if character matches seperator
 * @charac: character
 * @sep: seperator
 * Return: 1 if it matches 0 if it doesnt
 */
int _delim(char charac, char *sep)
{
	while (*sep != '\0')
	{
		if (charac == *sep)
			return (1);
		sep++;
	}
	return (0);
}
