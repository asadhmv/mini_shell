#include "mini_lib.h"
#include <stddef.h>


int mini_grep(char *name, char *mot)
{
	MYFILE *file = mini_fopen(name, 'r');

	if(file == NULL)
	{
		mini_perror("fichier introuvable :");
		return -1;
	}
	int longueur = mini_strlen(mot);
	int eq = 0, k = 0; 
	char *getLine = mini_calloc(sizeof(char), 1024);
	char *buffer = mini_calloc(sizeof(char), 4096);

	mini_fread(buffer, sizeof(char), 4096, file);

	for(int i=0; i<4096; i++)
	{
		getLine[k] = buffer[i]; 
		k++;
		if(buffer[i] == '\n' || buffer[i] =='\0')
		{
			char *temp = getLine;
			char *tempMot = mot;
			while(*temp != '\0')
			{
				//printf("\nStrcompare = %i\n", mini_strcmp(temp, mot));
				if(*temp == *tempMot)
				{
					char *tempMot = mot;
					for(int l=0; l<longueur ; l++)
					{
						//printf("\nComparaison [%c][%c]", *temp, *tempMot);

						if(*temp != *tempMot)
							break;
						temp++;
						tempMot++;
						if(l == longueur-1)
							eq = 1;
					}
				}
				temp++;
				/*if((*temp == *mot) && mini_strcmp(temp, mot)==0)
				{
					eq = 1;
					break;
				}
				temp++;*/

			}
			//printf("\nEq = %i",eq);
			if(eq == 1)
				mini_printf(getLine);
			eq =0;

			for(int x=0 ; x<1024 ; x++)
				getLine[x] = '\0';
			k=0;
			if(buffer[i] =='\0')
				break;
		}

	}
	return 0;
}


int main(int argc, char **argv)
{
	if(argc<3)
	{
		mini_printf("Veuillez saisir mini_grep 'chaine a rechercher'  'fichier'\n");
		mini_exit(0);
	}
	mini_grep(argv[2], argv[1]);
	
	return 0;
}