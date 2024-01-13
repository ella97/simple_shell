#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * struct alias - alias
 * @name: name of alias
 * @val: value of alias
 * @next: points to the next node
 */

typedef struct alias
{
	char *name;
	char *val;
	struct alias *next;
} alias_t;

/**
 * struct builtin - builtin
 * @builtin: name of builtin
 * @func: function of builtin
 */
typedef struct builtin
{
	char *builtin;
	int (*func)(char **text, int cnt, alias_t **ls);
} builtin_t;

#define MAX_ELEM 10

void _prompt(int mode, char **line, alias_t **ls);
char *_strcpy(char *dest, char *src);
void _remove_comments(char *buff);
void _prepare(char **text, int attempts, char **av, alias_t **ls);
char **_tokenizer(char *s, char *sep);
int _get_line(char **line_ptr, size_t *line_cap, FILE *file_stream);
void _free_alias(alias_t **head);
int (*builtins(char *s))(char **text, int attempts, alias_t **ls);
int _strcmp(char *s1, char *s2);
int _exitshell(char **text, int attempts, alias_t **h);
void _validator(char **text, char **argv, int attempts, alias_t **ls);
char *_strtok(char *str, char *sep);
int _delim(char charac, char *sep);
int _atoi(char *s);
char *_itoa(int value);
int _integer_length(int n);
int _execute(char **text, char **argv, char *cmd);
char *_get_path(char *path, char *cmd);
void _execute_error(char *prog, int count, char *cmd);
void _exit_error(int count, char *val);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *str);
#endif

