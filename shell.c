#include "main.h"

/**
* main - Entry point
* @argc: Argument count
* @argv: List of arguments
* Return: Integer
**/

int main(attribute((unused)) int argc, char argv)
{
char line[100000], dynamic = NULL;
int status = isatty(STDIN_FILENO), attempt = 0;
char **text = NULL, sep = " \n";
alias_t *aliasL = NULL;

errno = 0;
while (1 == 1)
{
attempt++;
_prompt(status, &dynamic, &aliasL);
_strcpy(line, dynamic);
free(dynamic);

_remove_comments(line);
text = _tokenizer(line, sep);
if (text[0] == NULL)
{
free(text);
continue;
}
_prepare(text, attempt, argv, &aliasL);

free(text);
}

return (errno);
}
