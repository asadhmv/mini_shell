#include <sys/stat.h>
#include <sys/types.h>
#include "mini_lib.h"

int mini_mkdir(char *path)
{
	if(mkdir(path, 0777) == -1)
		return -1;
	return 0;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		mini_printf("Veuillez saisir ./mini_mkdir 'chemin de repertoire a creer'\n");
		mini_exit(0);
	}

	for(int i=1; i<argc ; i++)
	{
		if(mini_mkdir(argv[i]) == -1)
			mini_perror("mini_mkdir :");
	}
	return 0;
}