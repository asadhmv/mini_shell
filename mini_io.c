#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "mini_lib.h"
#define IOBUFFER_SIZE 2048


MYFILE *mini_fopen(char *file, char mode)
{
	MYFILE *myfile = mini_calloc(sizeof(MYFILE),1);
	myfile->buffer_read = NULL;
	myfile->buffer_write = NULL;
	myfile->ind_write = -1;
	myfile->ind_read = -1;

	if(mode == 'r')
	{
		if((myfile->fd = open(file, O_RDONLY)) == -1)
		{
			mini_perror("\nOuverture Echouee\n");
			return NULL;
		}
	}
	if(mode == 'w')
	{
		if((myfile->fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXO | S_IRWXU)) == -1)
		{
			mini_perror("\nOuverture Echouee\n");
			return NULL;
		}
	}
	if(mode == 'b')
	{
		if((myfile->fd = open(file, O_RDWR | O_CREAT, S_IRWXO | S_IRWXU)) == -1)
		{
			mini_perror("\nOuverture Echouee\n");
			return NULL;
		}
	}
	if(mode == 'a')
	{
		if((myfile->fd = open(file, O_WRONLY |O_APPEND | O_CREAT, S_IRWXO | S_IRWXU)) == -1)
		{
			mini_perror("\nOuverture Echouee\n");
			return NULL;
		}
	}

	return myfile;
}

int mini_fread(void* buffer,int size_element, int number_element, MYFILE* file)
{
	if(file == NULL || buffer == NULL || size_element < 0 || number_element < 0)
	{
		mini_perror("\nImpossible de lire\n");
		return -1;
	}

	if(file->ind_read == -1)
	{
		file->buffer_read = mini_calloc(size_element, IOBUFFER_SIZE);
		file->ind_read = 0;
		if(read(file->fd, file->buffer_read, IOBUFFER_SIZE) == -1)
			return -1;
	}

	int i = 0;
	while( i < number_element && ((char*)file->buffer_read)[file->ind_read] != '\0')
	{
		if(file->ind_read == IOBUFFER_SIZE - 1)
		{
			file->ind_read = 0;
			break;
		}

		((char*)buffer)[i] = ((char*)file->buffer_read)[file->ind_read];
		file->ind_read++;
		i++;
	}

	return i;
}	

int mini_fwrite(void* buffer,int size_element, int number_element, MYFILE* file)
{
	if(file == NULL || buffer == NULL || size_element < 0 || number_element < 0)
	{
		mini_perror("\nImpossible d'ecrire\n");
		mini_exit(9);
		return -1;
	}
	if(file->ind_write == -1)
	{
		file->buffer_write = mini_calloc(size_element, IOBUFFER_SIZE);
		file->ind_write = 0;
	}

	int i = 0;
	while(i < number_element && ((char*)buffer)[file->ind_write] != '\0')
	{
		if(file->ind_write == IOBUFFER_SIZE - 1)
			break;

		((char*)file->buffer_write)[file->ind_write] = ((char*)buffer)[i];
		file->ind_write++;
		i++;
	}
	
	if(file->ind_write == IOBUFFER_SIZE - 1)
	{
		if(write(file->fd, file->buffer_write, IOBUFFER_SIZE) == -1)
			return -1;
	}
	return file->ind_write;
}

int mini_fflush(MYFILE* file)
{
	if(file != NULL && file->buffer_write != NULL && file->fd != -1)
	{
		if(write(file->fd, file->buffer_write, file->ind_write) == -1)
		{
			mini_perror("Ecriture Echouee");
			return -1;
		}

		return file->ind_write;
	}

	return -1;
}

int mini_fclose(MYFILE* file)
{
	if(file != NULL)
	{
		if(file->buffer_write != NULL)
		{
			mini_fflush(file);
			mini_free(file->buffer_write);
		}
		if(file->buffer_read != NULL)
			mini_free(file->buffer_read);

		file->ind_write = -1;
		file->ind_read = -1;

		mini_free(file);
		return 0;
	}
	return -1;
}

int mini_fgetc(MYFILE* file)
{
	if(file->fd != -1)
	{
		if(file->buffer_read == NULL)
		{
			file->buffer_read = mini_calloc(sizeof(char), IOBUFFER_SIZE);
			file->ind_read = 0;
			if(read(file->fd, file->buffer_read, IOBUFFER_SIZE) == -1)
			{
				mini_perror("Erreur lecture");
				mini_exit(9);
			}

			
		}
		return ((char*)file->buffer_read)[file->ind_read++];
	}

	return -1;
}

int mini_fputc(MYFILE* file, char c)
{
	if(file->fd != -1)
	{
		if(file->buffer_write == NULL)
		{
			file->buffer_write = mini_calloc(sizeof(char), IOBUFFER_SIZE);
			file->ind_write = 0;
		}
			((char*)file->buffer_write)[file->ind_write] = c;
			if(write(file->fd, file->buffer_write, 0) == -1)
			{
				mini_perror("Erreur ecriture");
				mini_exit(9);
			}
			file->ind_write++;
			return 0;
		
	}

	return -1;
}