#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


//Function Declaration
int c_cd(char **args);
int c_exit(char **args);

char *cm_str[] = {
        "cd",
        "exit"
};

int (*cm_func[]) (char **) = {
        &c_cd,
        &c_exit
};
//Returns the required memory size.
int c_num_cm() {
    return sizeof(cm_str) / sizeof(char *);
}


//Function implementations.
int c_cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "Note: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("c");
        }
    }
    return 1;
}

int c_exit(char **args)
{
    return 0;
}

int c_launch(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("c");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("c");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

int c_execute(char **args)
{
    int i;

    if (args[0] == NULL) {
        // An empty command was entered.
        return 1;
    }

    for (i = 0; i < c_num_cm(); i++) {
        if (strcmp(args[0], cm_str[i]) == 0) {
            return (*cm_func[i])(args);
        }
    }
    return c_launch(args);
}

char *c_read_line(void)
{
#ifdef C_GETLINE
     char *line = NULL;
     ssize_t bufsize = 0;
     if (getline(&line, &bufsize, stdin) == -1){
        if (feof(stdin)) {
      exit(EXIT_SUCCESS); //EOF exit
        }else{
          perror("c: getline\n");
          exit(EXIT_FAILURE); //error exit
         }
      }
      return line;
#else
#define CRL_BUFSIZE 1024
    int bufsize = CRL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "Note: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar(); //Use getchar() to read a character.
        if (c == EOF) {
            exit(EXIT_SUCCESS);
        } else if (c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        if (position >= bufsize) {
            bufsize += CRL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "Note: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
#endif
}

#define C_BUFSIZE 64
#define C_DELIM " \t\r\n\a"
//Split a line into tokens.
char **c_split_line(char *line)
{
    int bufsize = C_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token, **tokens_backup;

    if (!tokens) {
        fprintf(stderr, "Note: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, C_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;
         // Reallocate if exceed the buffer.
        if (position >= bufsize) {
            bufsize = C_BUFSIZE + bufsize;
            tokens_backup = tokens;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                free(tokens_backup);
                fprintf(stderr, "Note: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, C_DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

void c_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("Please enter your command > "); //Note: enter your command.
        line = c_read_line();
        args = c_split_line(line);
        status = c_execute(args);
        //free memory
        free(line);
        free(args);
    } while (status);
}

int main(int argc, char **argv)
{
    c_loop();  // Run the loop.
    return EXIT_SUCCESS;
}
