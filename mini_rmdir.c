#include <unistd.h>
#include "mini_lib.h"

int mini_rmdir(char *path)
{
	if(rmdir(path) == -1)
		return -1;
	return 0;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		mini_printf("Veuillez saisir ./mini_rm 'dossier a supprimer'\n");
		mini_exit(0);
	}

	for(int i=1; i<argc ; i++)
	{
		if(mini_rmdir(argv[i]) == -1)
			mini_perror("mini_rmdir :");
	}
	return 0;
}