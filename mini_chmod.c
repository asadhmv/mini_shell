#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "mini_lib.h"

int mini_chmod(char *filename, char *m)
{
	mode_t md = 00000;
	int unite = 100;
	for(int i=0; i<3 ; i++)
	{
		mode_t right = (m[i] - 48) * unite;
		printf("%i",right);
		md = md | right;
		printf("\nmod = %i\n",md);
		unite = unite / 10; 
	}
	printf("\n%i\n", md);
	int mode = strtol(m, NULL, 8);
	if(chmod(filename, mode) == -1)
		return -1;
	return 0;
}

int main(int argc, char **argv)
{
	if(mini_strlen(argv[1]) != 3)
	{
		mini_printf("Veuillez saisir ./mini_chmod 'mode' 'nom du fichier'\n");
		mini_exit(0);
	}

	if(mini_chmod(argv[2], argv[1]) == -1)
		mini_perror("mini_chmod :");
	return 0;
}