#include <unistd.h>
#include "mini_lib.h"

int mini_rm(char *path)
{
	if(unlink(path) == -1)
		return -1;
	return 0;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		mini_printf("Veuillez saisir ./mini_rm 'fichier a supprimer'\n");
		mini_exit(0);
	}

	for(int i=1; i<argc ; i++)
	{
		if(mini_rm(argv[i]) == -1)
			mini_perror("mini_rm :");
	}
	return 0;
}