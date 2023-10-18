#include "shell.h"

/**
 * _strcmp - compare 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if true, 0 if false
 */

int _strcmp(char *s1, char *s2)
{
	if (!s1 && s2)
		return (-1);
	if (!s2 && s1)
		return (-1);

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++, s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);

}


/**
 * _strcmpd - custom strcmp
 * @fstring: fstring
 * @sub: subset
 *
 * Return: 1 on success and -1 on faliur
 */

int _strcmpd(char *fstring, const char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (!*fstring)
		return (-1);
	if (_strlen(fstring) < _strlen(sub))
		return (-1);
	while (*sub)
	{
		if (*sub == *fstring)
			return (1);
		sub++;
	}
	return (-1);
}


/**
 * _strcmps - alternate custom strcmp
 * @fstring: fstring
 * @sub: subset
 * Return: 1 on success and -1 on faliur
 */

int _strcmps(char *fstring, const char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (!*fstring)
		return (-1);
	if (_strlen(fstring) < _strlen(sub))
		return (-1);
	while (*sub && *fstring)
	{
		if (*sub != *fstring)
			return (-1);
		sub++, fstring++;
	}
	return (1);
}
