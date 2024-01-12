#include "main.h"

/**
 * _execute - Executes command
 * @text: Given text
 * @argv: Argument list
 * @cmd: Command
 * Return: Integer
 */
int _execute(char **text, char **argv, char *cmd)
{
	pid_t child;
	int status;

	child = fork();
	if (child < 0)
	{
		perror(cmd);
		exit(-1);
	}
	else if (child == 0)
	{
		execve(cmd, text, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		errno = status;
	}

	return (status);
}

/**
 * _prepare - Prepares the text
 * @text: Given text
 * @attempts: Trials
 * @av: list argument
 * @ls: alias list
 */
void _prepare(char **text, int attempts, char **av, alias_t **ls)
{
	int (*builtin)(char **text, int attempts, alias_t **ls);

	if (_strcmp(text[0], "exit") == 0)
		_exitshell(text, attempts, ls);
	builtin = builtins(text[0]);
	if (builtin)
		builtin(text, attempts, ls);
	else
		_validator(text, av, attempts, ls);
}

/**
 * _validator - Validates command
 * @text: Given text
 * @argv: Argument ist
 * @attempts: Trials
 * @ls: Alias list
 * Return: Integer
 */
void _validator(char **text, char **argv, int attempts, alias_t **ls)
{
	char *cmd = NULL;
	int check = 0;
	alias_t *temp = *ls;

	cmd = text[0];
	for (; temp != NULL; temp = temp->next)
		if (!_strcmp(temp->name, cmd))
			cmd = temp->val;

	if (access(cmd, X_OK) == 0 && _strcmp(cmd, "hbtn_ls") == 0 && text[1])
	{
		_exec(text, argv, cmd);
		return;
	}

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		check = 1;
		cmd = _get_path("PATH", cmd);
	}

	if (!cmd || (access(cmd, X_OK) == -1))
	{
		_exec_error(argv[0], attempts, text[0]);
	}
	else
	{
		_exec(text, argv, cmd);
		if (check)
			free(cmd);
	}
}
