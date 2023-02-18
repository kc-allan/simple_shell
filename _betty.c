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
	execve("/usr/bin/betty", argv, envp);

	return (0);
}
