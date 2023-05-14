#include <unistd.h>
#include "mini_lib.h"

int lien_symbolique(char *cible, char *nom)
{
	if(symlink(cible, nom) == -1)
		return -1;
	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		mini_printf("Veuillez saisir ./mini_ln 'fichier cible' 'nom fichier pointe");
		mini_exit(0);
	}

	lien_symbolique(argv[1], argv[2]);

	return 0;
}