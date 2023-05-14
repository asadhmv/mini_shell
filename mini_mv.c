#include "mini_lib.h"
#include <unistd.h>

int mini_mv(char *src, char *dest)
{
	MYFILE *file_src = mini_fopen(src,'r');
	MYFILE *file_dest = mini_fopen(dest,'w');

	char c;

	if(file_src != NULL && file_dest != NULL)
	{
		while((c = mini_fgetc(file_src)) != '\0')
		{	
			mini_fputc(file_dest, c);
		}
	}
	else
		return -1;

	mini_fclose(file_src);
	mini_fclose(file_dest);

	if(unlink(src) == -1)
		return -1;

	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		mini_printf("Veuillez saisir ./mini_mv 'source' 'destination'\n");
		mini_exit(0);
	}
	if(mini_mv(argv[1], argv[2]) == -1)
		mini_perror("mini_mv :");
	return 0;
}