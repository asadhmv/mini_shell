#include "mini_lib.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>//pour faire appel a system() permettant d'ajouter la couleur

extern char **environ;

int mini_shell(void)
{
	char *commande = mini_calloc(sizeof(char), 1024);
	char *cmd = mini_calloc(1, 20);

	while(1)
	{
		system("echo -n '\033[0;34;1masad@mini_shell$ \033[m'");	
		mini_scanf(commande, 1024);
		int argc=0, i=0, j=0;
		char **argv;

		while(commande[i] != '\0')
		{
			if(commande[i] == ' ')
				argc++;
			i++;
		}
		argc++;

		argv = (char**)mini_calloc(sizeof(char*), argc);

		for(i=0 ; i<argc ; i++)
		{
			argv[i] = (char*)mini_calloc(sizeof(char), 100);
			for(j=0 ; commande[j] != ' '; j++)
			{
				if(commande[j] == '\n')
					break;
				argv[i][j] = commande[j];
			}
			if(commande[j] == '\n')
				break;
			commande = commande+j+1;
		}
		cmd = argv[0];

		if(mini_strcmp(cmd, "exit") == 0)
			mini_exit(0);
		if(mini_strcmp(argv[0], "mini_cd") == 0)
		{
			if(chdir(argv[1]) == -1)
				mini_perror("cd :");
			continue;
		}
		if(mini_strcmp(argv[0], "mini_env") == 0)
		{
			char **env = environ;
			//printf("%li", sizeof(environ));
			while(env != NULL)
			{
				//printf("%s\n",*environ);
				mini_printf(*env);
				mini_printf("\n");
				env++;
			}

			continue;
		}
		if(mini_strcmp(argv[0], "mini_getenv") == 0)
		{
			if(argc < 2)
				mini_printf("Saisir une variable d'env\n");
			else
			{
				for(int i = 1; i<argc; i++)
				{
					mini_printf(argv[i]);
					mini_printf(" = ");
					mini_printf(getenv(argv[i]));
					mini_printf("\n");
				}
			}
			continue;
		}

		pid_t pid;

        int  status;

        if ((pid = fork()) < 0) {     
            mini_perror("*** ERROR: forking child process failed = ");
            mini_exit(1);
        }
        else if (pid == 0) {          
            if (execvp(cmd, argv) < 0) {     
                mini_perror("*** ERROR: exec failed = ");
                mini_exit(1);
            }
        }
        else                                  
        while (wait(&status) != pid)       
            ;
        mini_printf("\n");
	}

	return 0;
}

int main(int argc, char **argv)
{

	mini_shell();
	return 0;
}