#include "shell.h"
/**
 * _strdup - copies a string
 * @s: string to copy
 * Return: copy of the string
 */
char *_strdup(char *s)
{
	char *copy_s;
	int i, len_s;

	if (s == NULL)
	{
		return (NULL);
	}
	len_s = 0;
	while (s[len_s] != NULL)
	{
		len_s++;
	}
	copy_s = malloc(sizeof(char) * (len_s + 1));
	if (copy_s == NULL)
	{
		return (NULL);
	}
	for (i = 0 ; s[i] != NULL ; i++)
	{
		copy_s[i] = s[i];
	}
	copy_s[len_s] = '\0';
	return (copy_s);
}
