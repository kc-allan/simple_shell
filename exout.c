#include "main.h"

/**
 **_strncpy - copy a string
 *@dest: destination of string to be copied to
 *@soc: the source string
 *@cy: the amount of characters to be copied
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *soc, int cy)
{
	int y, g;
	char *h = dest;

	y = 0;
	while (soc[y] != '\0' && y < cy - 1)
	{
		dest[y] = soc[y];
		y++;
	}
	if (y < cy)
	{
		g = y;
		while (g < cy)
		{
			dest[g] = '\0';
			g++;
		}
	}
	return (h);
}

/**
 **_strncat - concatenates two strings
 *@fst: the first string
 *@sec: the second string
 *@m: amount of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *fst, char *sec, int m)
{
	int y, g;
	char *h = fst;

	y = 0;
	g = 0;
	while (fst[y] != '\0')
		y++;
	while (sec[g] != '\0' && g < m)
	{
		fst[y] = sec[g];
		y++;
		g++;
	}
	if (g < m)
		fst[y] = '\0';
	return (h);
}

/**
 **_strchr - locates character in a string
 *@st: the string to be parsed
 *@cha: the character to look for
 *Return: st a pointer to the memory area st
 */
char *_strchr(char *st, char cha)
{
	do {
		if (*st == cha)
			return (st);
	} while (*st++ != '\0');

	return (NULL);
}
