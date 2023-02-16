#include "main.h"
/**
 * main - Entry point
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    char *path = "/bin:/usr/bin"; /* Default PATH */
    char *input = NULL, *token, *command;
    char **args;
    size_t input_len = 0;
    ssize_t bytes_read;
    pid_t pid;
    int i, status;

    while (1)
    {
        printf("($) ");
        bytes_read = getline(&input, &input_len, stdin);
        if (bytes_read == -1)
        {
            if (feof(stdin)) /* End-of-file condition */
            {
                printf("\n");
                free(input);
                exit(EXIT_SUCCESS);
            }
            perror("getline");
            free(input);
            exit(EXIT_FAILURE);
        }
        if (input[bytes_read - 1] == '\n')
            input[bytes_read - 1] = '\0';

        token = strtok(input, " ");
        command = token;
        args = malloc(sizeof(char*));
        args[0] = token;

        i = 1;
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            args = realloc(args, (i + 1) * sizeof(char *));
            args[i] = token;
            i++;
        }
        args[i - 1] = NULL;

        if (command == NULL)
        {
            free(args);
            continue;
        }

        if (access(command, F_OK) == -1)
        {
            token = strtok(path, ":");
            while (token != NULL)
            {
                char *path_command = malloc(strlen(token) + strlen(command) + 2);
                sprintf(path_command, "%s/%s", token, command);
                if (access(path_command, F_OK) == 0)
                {
                    command = path_command;
                    break;
                }
                free(path_command);
                token = strtok(NULL, ":");
            }
            if (token == NULL) /* Command not found */
            {
                printf("%s: command not found\n", args[0]);
                free(args);
                continue;
            }
        }

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            free(args);
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            if (execve(command, args, NULL) == -1)
            {
                perror("execve");
                free(args);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }

        free(args);
    }

    return (0);
}
