#include "mini_lib.h"

int mini_clean(char *name)
{
	MYFILE *file = mini_fopen(name, 'w');
	mini_fclose(file);
	return 0;
}

int main(int argc, char **argv)
{
	if(argc<2)
	{
		mini_perror("Too few arguments : ");
		mini_exit(0);
	}
	for(int i = 1; i<argc ; i++)
	{
		mini_clean(argv[i]);
	}
	return 0;
}