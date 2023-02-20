#include "main.h"

/**
 * _strcpy - copies a string
 * @dst: destination
 * @sorc: source
 * Return: pointer to destination
 */
char *_strcpy(char *dst, char *sorc)
{
	int y = 0;

	if (dst == sorc || sorc == 0)
		return (dst);
	while (sorc[y])
	{
		dst[y] = sorc[y];
		y++;
	}
	dst[y] = 0;
	return (dst);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *rt;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	rt = malloc(sizeof(char) * (len + 1));
	if (!rt)
		return (NULL);
	for (len++; len--;)
		rt[len] = *--str;
	return (rt);
}

/**
 * _puts - prints an input string
 * @str: string to be printed
 * Return: void
 */
void _puts(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_putchar(str[y]);
		y++;
	}
}

/**
 * _putchar - writes char c to stdout
 * @ch: character to print
 * Return: void
 */
int _putchar(char ch)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(1, buf, y);
		y = 0;
	}
	if (ch != BUF_FLUSH)
		buf[y++] = ch;
	return (y);
}
