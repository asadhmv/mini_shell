#include "mini_lib.h"
#include <stddef.h>

int mini_cp(char *src, char *dest)
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

	mini_fclose(file_src);
	mini_fclose(file_dest);

	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		mini_perror("\nCopier de source vers destination\n");
		return -1;
	}

	mini_cp(argv[1], argv[2]);
	return 0;
}