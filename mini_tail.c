#include "mini_lib.h"
#include <unistd.h>
#include <stdlib.h>//pour utiliser atoi()

int mini_tail(char *f, int n)
{
	MYFILE *file = mini_fopen(f,'r');
	int total_lignes = 1, i = 1, ind = 0;

	if(file == NULL)
		return-1;
	char c;
	char *ch = mini_calloc(sizeof(char), 2048);
	char *buffer = mini_calloc(sizeof(char), 2048);
	mini_fread(buffer, sizeof(char), 2048, file);

	for(int i=0; buffer[i]!='\0'; i++)
	{
		if(buffer[i] == '\n')
			total_lignes++;
	}


	file = mini_fopen(f,'r');
	i = 1;
	while((c = mini_fgetc(file)) != '\0')
	{
		if(total_lignes-i < n){
			ch[ind] = c;
			ind++;
		}
		if(c == '\n'){
			i++;
		}
	}

	mini_printf(ch);
	mini_printf("\n");
	
	mini_fclose(file);
	return 0;

}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		mini_perror("Arguments incorrects\nSaisir mini_tail fichier -n N");
		mini_exit(0);
	}
		int n = atoi(argv[3]);
		mini_tail(argv[1], n);
	return 0;
}

