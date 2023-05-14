#include "mini_lib.h"
#include <stdlib.h>//pour utiliser atoi()
#include <unistd.h>

int mini_head(char *f, int n)
{
	MYFILE *file = mini_fopen(f,'r');

	if(file == NULL)
	{
		mini_perror("Fichier introuvable :");
		return -1;
	}
	
	int count = 1;
	char c;
	while(count <= n)
	{
		if((c = mini_fgetc(file)) == '\n')
			count++;
		mini_printf(&c);
	}
	mini_fclose(file);
	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		mini_perror("Arguments incorrects\nSaisir mini_head fichier -n N");
		mini_exit(0);
	}
		int n = atoi(argv[3]);
		mini_head(argv[1], n);
	return 0;
}