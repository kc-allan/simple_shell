#include "main.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: array of arguments
 * @envp: environment variables
 * Return: 0 (Success)
 */
int main(int argc, char **argv, char **envp)
{
	char *command = NULL, *cmd;
	ssize_t bytes_read;
	size_t len = 0;
	pid_t pid;
	int status;	
	char *path = "/usr/bin/";

	while (argc == 1)
	{
		printf("($) ");
		bytes_read = getline(&command, &len, stdin);
		if (bytes_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(command);
				exit(EXIT_SUCCESS);
			}
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}
		if (command[bytes_read - 1] == '\n')
			command[bytes_read - 1] = '\0';
		setenv("PATH", path, 1);
		if (access(path, F_OK) == -1)
		{
			printf("%s: command not found\n", command);
			continue;
		}
		cmd = malloc(MAX_LEN);
		strcpy(cmd, path);
		strcat(cmd, command);
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(command);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(cmd, argv, envp) == -1)
			{
				printf("./hsh: 1: %s: not found\n", command);
				free(command);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	return (0);
}
