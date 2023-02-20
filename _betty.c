#include "main.h"
/**
 * main - performs error checks in code using betty
 * @argc: argument count
 * @argv: array of arguments
 * @envp: environment variables
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv, char **envp)
{
	if (argc == 0)
		exit(EXIT_FAILURE);
	execve("/usr/bin/betty", argv, envp);

	return (0);
}
