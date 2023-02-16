#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * betty - passes the betty checks
 * Return: 0 (Success)
 */
int betty(void)
{

	char *envp[] = {"HOME", NULL};
	char *argv[] = {"/bin/betty", "*.c", NULL};

	execve(argv[0], argv, envp);
	return (0);
}
