#include "mini_lib.h"
#include <stddef.h>

int mini_cat(char *name)
{
	MYFILE *file = mini_fopen(name, 'r');

	if(file != NULL)
	{
		char c;
		while((c = mini_fgetc(file)) != '\0')
		{
			mini_printf(&c);
		}
		return 0;
	}
	return -1;
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		mini_perror("Saisir un fichier :");
	}

	mini_cat(argv[1]);
	return 0;
}