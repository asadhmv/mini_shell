#include "mini_lib.h"
#include <stdlib.h>//pour utiliser atoi()
#include <unistd.h>
#include <stdio.h>


#define BUFFER_SIZE 4096

int mini_quickdiff(char *f1, char *f2)
{
	MYFILE *file1 = mini_fopen(f1,'r');
	MYFILE *file2 = mini_fopen(f2,'r');

	if(file1 == NULL || file2 == NULL)
	{
		mini_printf("Fichier introuvable :");
		return -1;
	}

	char *buffer1 = mini_calloc(1, BUFFER_SIZE);
	char *buffer2 = mini_calloc(1, BUFFER_SIZE);
	char *ligne1 = mini_calloc(1, BUFFER_SIZE);
	char *ligne2 = mini_calloc(1, BUFFER_SIZE);
	
	if(mini_fread(buffer1, sizeof(char), BUFFER_SIZE, file1) <= 0)
		return -1;

	if(mini_fread(buffer2, sizeof(char), BUFFER_SIZE, file2) <= 0)
		return -1;
	
	int debut_ligne1 = 0;int fin_ligne1 = 0;int debut_ligne2 = 0;int fin_ligne2 = 0;
	int i = 0;int l = 0;int j = 0;int comparer = 0;

	while(buffer1[i] != '\0')
	{
		if(buffer1[i] == '\n')
		{
			debut_ligne1 = fin_ligne1;
			fin_ligne1 = i;
			j = 0;
			for(int k=debut_ligne1 + 1 ; k<=fin_ligne1 ; k++)
			{
				ligne1[j] = buffer1[k];
				j++;
			}
			comparer = 1;
		}
		if(buffer2[l] == '\n')
		{
			debut_ligne2 = fin_ligne2;
			fin_ligne2 = l;
			j = 0;
			for(int k=debut_ligne2 + 1 ; k<=fin_ligne2 ; k++)
			{
				ligne2[j] = buffer2[k];
				j++;
			}

		}
		if(comparer)
		{
			if(mini_strcmp(ligne1, ligne2) != 0)
				mini_printf(ligne1);
			for(int x=0 ; x<BUFFER_SIZE ; x++)
			{
				ligne1[x] = '\0';
				ligne2[x] = '\0';
			}
			comparer = 0;
		}
		l++;i++;
	}
	
	mini_fclose(file1);
	mini_fclose(file2);

	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		mini_printf("Arguments incorrects\nSaisir mini_head 'fichier 1' 'fichier 2'");
		mini_exit(0);
	}

	mini_quickdiff(argv[1], argv[2]);

	return 0;
}