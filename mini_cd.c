#include "mini_lib.h"
#include <unistd.h>

int change_directory(char *path)
{
	if(chdir(path) == -1)
		return -1;
	return 0;
}

int main(int argc, char **argv)
{
	if(argc > 2)
	{
		mini_printf("Argument incorrect\nVeuillez saisir ./mini_cd 'path du dossier dans lequel se placer'");
		mini_exit(0);
	}

	if(change_directory(argv[1]) == -1)
	{
		mini_perror("Cd :");
		mini_exit(0);
	}
	return 0;
}