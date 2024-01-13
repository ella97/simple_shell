#include "main.h"
/**
 * _remove_comments - Removes comments
 * @s: Given string
 */
void _remove_comments(char *s)
{
	int i = 0;

	if (!s)
		return;
	for (; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' && s[i + 1] == '#')
			s[i + 1] = '\0';
		else if (s[i] == '#' && s[i + 1] == '\0')
			s[i] = '\0';
		else if (s[i] == '#' && i == 0)
		{
			s[i] = '\0';
			break;
		}
	}
}

/**
 * _atoi - Converts a string to an integer
 * @s: Given string
 *
 * Return: Value
 */
int _atoi(char *s)
{
	int i = 0, j = 0, n = 0, len = 0, f = 0, digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++j;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (j % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
 * _itoa - String integer
 * @value: Given value
 * Return: String
 */
char *_itoa(int value)
{
	char *buffer;
	int len = _integer_length(value), i;

	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	for (i = (len - 1); i >= 0; i--)
	{
		if (value < 0)
			buffer[0] = '-';

		buffer[i] = (value % 10) + '0';
		value /= 10;
	}
	buffer[len] = '\0';
	return (buffer);
}

/**
 * _integer_length - Get integer length
 * @n: Given integer
 * Return: Length
 */
int _integer_length(int n)
{
	unsigned int count = 0;

	if (n < 0)
	{
		n = -n;
		count++;
	}

	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

