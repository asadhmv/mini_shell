#include "mini_lib.h"

int mini_echo(char *chaine)
{
	mini_printf(chaine);
	return 0;
}

int main(int argc, char **argv)
{
	for(int i=1 ; i<argc ; i++)
	{
		mini_echo(argv[i]);
		mini_echo(" ");
	}
	return 0;
}
