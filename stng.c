#include "main.h"

/**
 * _strlen - returns length of string
 * @h: string whose length to check
 * Return: integer length of string
 */
int _strlen(char *h)
{
	int y = 0;

	if (!h)
		return (0);
	while (*h++)
		y++;
	return (y);
}

/**
 * _strcmp - does comparison of two strings
 * @h1: first string
 * @h2: second string
 * Return: neg if (h1 < h2), pos if (h1 > h2), zero if (h1 == h2)
 */
int _strcmp(char *h1, char *h2)
{
	while (*h1 && *h2)
	{
		if (*h1 != *h2)
			return (*h1 - *h2);
		h1++;
		h2++;
	}
	if (*h1 == *h2)
		return (0);
	else
		return (*h1 < *h2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @hay: string to search
 * @ndle: the substring to find
 * Return: address of next char of hay or NULL
 */
char *starts_with(const char *hay, const char *ndle)
{
	while (*ndle)
		if (*ndle++ != *hay++)
			return (NULL);
	return ((char *)hay);
}

/**
 * _strcat - concentrates two strings
 * @dst: the destination buffer
 * @sroc: source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *dst, char *sroc)
{
	char *rt = dst;

	while (*dst)
		dst++;
	while (*sroc)
		*dst++ = *sroc++;
	*dst = *sroc;
	return (rt);
}
