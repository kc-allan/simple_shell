#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * betty - passes the betty checks
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{

	char *path = "/usr/bin/betty";

	execve(path, argv, NULL);
	return (0);
}
