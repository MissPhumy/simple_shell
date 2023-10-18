#include "shell.h"

/**
 * _strcat - concatinate 2 strings
 * @dest: string destination
 * @src: source string
 *
 * Return: concatinated string
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
		*p++ = *src++;

	*p = '\0';

	return (dest);
}


/**
 * *_strcpy - copy string
 * @dest: destination string
 * @src: source string
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	if (!dest)
		return (NULL);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ptr);
}


/**
 * _strdup - duplicate a string
 * @str: string to be duplicated
 * Return: duplicated string
 */

char *_strdup(char *str)
{

	char *copy, *_copy;

	if (!str)
		return (NULL);
	copy = _malloc((_strlen(str) + 1) * sizeof(char));
	_copy = copy;

	while (*str)
		*_copy = *str, str += 1, _copy += 1;

	*_copy = '\0';
	return (copy);
}


/**
 * _strlen - return length of string
 * @str: the string
 * Return: length of string
 */

int _strlen(const char *str)
{
	int length;

	if (!str)
		return (0);

	length = 0;
	while (*str)
	{
		str += 1;
		length += 1;
	}

	return (length);

}
