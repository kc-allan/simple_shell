#include "main.h"
/**
 * execute_command - runs commamd provided to the shell
 * @argv: array of argument variables
 * @envp: environment variables
 *
 * Return: void
 */
void execute_command(char **argv, char **envp)
{
	char *path = "/usr/bin/", *cmd;
	pid_t pid;
	int status;
	size_t cmd_size = (strlen(path) + strlen(argv[0]) + 1);

	setenv("PATH", path, 1);
	if (access(path, F_OK) == -1)
	{
		printf("%s: command not found\n", argv[0]);
		return;
	}
	cmd = malloc(cmd_size);
	strcpy(cmd, path);
	strcat(cmd, argv[0]);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(cmd, argv, envp) == -1)
		{
			printf("./hsh: 1: %s: not found\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(cmd);
}

/**
 * main - Entry point
 * @argc: argument count
 * @envp: environment variables
 *
 * Return: 0 (Success)
 */
int main(int argc, char **envp)
{
	char *command = NULL, **argv;
	ssize_t bytes_read;
	size_t len = 0;

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
		argv = get_token(command);
		execute_command(argv, envp);
	}
	free(command);
	return (0);
}
