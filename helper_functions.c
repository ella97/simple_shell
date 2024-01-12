#include "main.h"

/**
 * _strlen - Gets length of a string
 * @str: Given string
 * Return: Length
*/
int _strlen(char *str)
{
	int count = 0;

	if (str == NULL)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

/**
 * _strcpy - Copies string
 * @dest: Destination
 * @src: Source
 *
 * Return: Character
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - Compares two strings
 * @s1: String one
 * @s2: String two
 * Return: Difference
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int diff = 0;

	while (*s1 != '\0')
	{
		diff = *s1 - *s2;
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (diff);
}

