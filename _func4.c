#include "shell.h"

/**
 * find_tok_occ - find no. of occurences of token
 * @str: string to be searched
 * @tof: string to find
 *
 * Return: number of times delimiter occur
 */

int find_tok_occ(char *str, char *tof)
{
	char *tokenized = NULL, *new = NULL;
	int i = 0;

	if (_strlen(tof) > _strlen(str))
		return (0);
	new = _strdup(str);
	tokenized = _strtok(new, tof, 1);
	while (tokenized != NULL)
	{
		i++;
		tokenized = _strtok(NULL, tof, 1);
	}
	free(new);
	if (_strcmps(str + _strlen(str) - _strlen(tof), tof) == 1)
		i++;
	return (i - 1);
}
/**
 * find_n_rep - find and replace part of string
 * @str: string to be parsed
 * @torep: string to be replaced
 * @repwith: sting to replace
 *
 * Return: 0 on sucess and -1 on faliure
 */

int find_n_rep(char **str, char *torep, char *repwith)
{
	char *tokenized = NULL, *tmp, *new = _malloc(1);
	int rep = 0, tor = find_tok_occ(*str, torep), newlen = 0;

	tokenized = _strtok(*str, torep, 1);
	*new = '\0';
	while (tokenized != NULL)
	{
		newlen = _strlen(new) + _strlen(tokenized) + _strlen(repwith);
		tmp = _realloc(new, newlen +  2);
		new = tmp;
		_strcat(new, tokenized);
		if (rep < tor)
			_strcat(new, repwith);
		rep++, tokenized = _strtok(NULL, torep, 1);
	}
	free(*str);
	*str = new;
	return (0);
}


/**
 * remove_alias - remove node with key from linked list
 * @head: first node
 * @key: token key of node to remove
 *
 * Return: 0 on sucess -1 on faliure
 */

int remove_alias(alias **head, char *key)
{
	alias *_head, *tmp;

	if (!*head)
		return (-1);

	if (!_strcmp((*head)->key, key))
	{
		_head = *head;
		*head = (*head)->next;
		free(_head->key);
		free(_head->value);
		free(_head);
		return (0);
	}
	_head = *head;
	while (_head->next)
	{
		if (!_strcmp(_head->next->key, key))
		{
			tmp = _head->next;
			_head->next = _head->next->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
		_head = _head->next;
	}

	return (0);
}
