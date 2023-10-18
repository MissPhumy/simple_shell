#include "shell.h"

/**
 * num_len - return length of stringized number
 * @num : number
 * Return: no. of digits
 */

int num_len(unsigned int num)
{
	int length = 0;

	if (!num)
		return (1);

	while (num)
	{
		num = num / 10;
		length += 1;
	}

	return (length);
}


/**
 * parse_args - parse arguments
 * @cmd: tokenized string with arguments
 * @del: delimeter
 * @args: argument vector
 * @mod: delimeter method 0-character 1-string
 *
 * Return: none
 */

void parse_args(char *cmd, const char *del, char ***args, int mod)
{
	char *tokenized = NULL, **tmp, *trimmed_arg;
	int index = 0, i;

	*args = NULL;
	tokenized = _strtok(cmd, del, mod);
	while (tokenized != NULL)
	{
		tmp = (char **)_malloc((_arlen(*args) +  2) * sizeof(char *));
		if (!*args)
			*args = tmp;
		else
		{
			i = 0;
			while ((*args)[i])
			{
				tmp[i] = _strdup((*args)[i]);
				i++;
			}
			free_pp(*args);
			*args = tmp;
		}
		(*args)[index] = NULL;
		trimmed_arg = tokenized;
		if ((tokenized[0] == '"' && tokenized[_strlen(tokenized) - 1] == '"') ||
				(tokenized[0] == '\'' && tokenized[_strlen(tokenized) - 1] == '\''))
		{
			trimmed_arg = _strdup(tokenized + 1);
			trimmed_arg[_strlen(trimmed_arg) - 1] = '\0';
		}
		trim_spaces(&((*args)[index]), trimmed_arg);
		(*args)[index + 1] = NULL;
		if (trimmed_arg != tokenized)
			free(trimmed_arg);
		tokenized = _strtok(NULL, del, mod);
		index++;
	}
}


/**
 * pow_b - exponent of a number to its base
 * @base : base
 * @power : exponent (power)
 *
 * Return: int
 */

int pow_b(unsigned int base, int power)
{
	int i, prod = 1;

	for (i = 0; i < power; i++)
	{
		prod = prod * base;
	}
	return (prod);
}


/**
 * runscript - run a file if executable
 * @name: filename
 * Return: 0 on sucess and -1 on faliure
 */

int runscript(char *name)
{
	char *path = NULL, *currentdir = NULL;
	int fd, i, cmdlen;
	size_t len = 0;
	char *input, **cmds, *errmsg, **cmds2;
	alias *head = NULL;

	if (name[0] != '.' && name[0] != '~' && name[0] != '/')
	{
		currentdir = _getenv("PWD");
		path = _malloc(_strlen(currentdir) + _strlen(name) + 4);
		_strcpy(path, currentdir);
		_strcat(path, "/"), _strcat(path, name);
	}
	else
		path = name;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		errno = -3;
		errmsg = _malloc(_strlen("No such file or directory ") + _strlen(name) + 4);
		_strcpy(errmsg, "No such file or directory ");
		print_error(name, NULL, errmsg);
		free(errmsg), free(path);
		return (127);
	}
	free(path);

	get_input(&input, &len, &cmds, fd), find_n_rep(&(cmds[0]), "\n", ";");
	parse_args(cmds[0], ";", &cmds2, 0), free(input), free_pp(cmds);

	i = 0, cmdlen = _arlen(cmds2);
	while (i < cmdlen)
		exec_cmd(cmds2, i, &head), i++;
	free_pp(cmds2);
	return (0);
}
