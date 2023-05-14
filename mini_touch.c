#include "mini_lib.h"

int mini_touch(char *filename)
{
	MYFILE *file = mini_fopen(filename, 'w');

	if(file->fd == -1)
	{
		mini_perror("\nCreation echouee :");
		return -1;
	}

	mini_fclose(file);
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		mini_perror("\nSaisir le nom de fichier a creer : ");
		mini_exit(0);
	}
	for(int i=1 ; i<argc ; i++)
	{
		if(mini_touch(argv[i]) == -1)
			mini_exit(0);
	}
	return 0;
}