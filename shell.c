#include "mini_lib.h"
#include <sys/wait.h>
#include <unistd.h>

void mini_shell()


char** decomposer_commandes(char *line, int length)
{
    char **tokens = mini_calloc(length * sizeof(char), 256);

    int i=0, j=0;
    while(*line != '\0')
    {
        tokens[j] = 
    }
}
char* read_line() 
{
    char *line = mini_calloc(sizeof(char), 256);
    mini_scanf(line, 256);
    int i=0
    int argc = 1;
    while(line[i] != '\0')
    {
        if(line[i] == ' ')
            argc++;
        i++;
    }
    char **arguments = (char**)mini_calloc(sizeof(char*), argc);



    return line;
}
int main() {
    while (1) {
        mini_printf("> ");
        char *line = kash_read_line();
        char **tokens = kash_split_line(line);

        if (tokens[0] != NULL) {
            kash_exec(tokens);
        }

        free(tokens);
        free(line);
    }
}