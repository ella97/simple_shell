#include "main.h"

/**
 * _execute_error - Executes error message
 * @prog: Program
 * @count: Count
 * @cmd: Command
 */
void _execute_error(char *prog, int count, char *cmd)
{
	char *str = _itoa(count);

	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);

	free(str);
	errno = 127;
}

/**
 * _exit_error - Prints error message
 * @count: Count
 * @val: Value
 */
void _exit_error(int count, char *val)
{
	char *str = _itoa(count);

	write(STDERR_FILENO, "./hsh: ", 7);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": exit: Illegal number: ", 24);
	write(STDERR_FILENO, val, _strlen(val));
	write(STDERR_FILENO, "\n", 1);
	free(str);
}
