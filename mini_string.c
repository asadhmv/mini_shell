#include "mini_lib.h"
#include <unistd.h>
#include <string.h>//pour utiliser strerror()
#include <errno.h>
#define BUFFER_SIZE 1024

char *buffer;
int ind = -1;
extern int errno;

void mini_printf(char *toprint)
{
	if(ind == -1)
	{
		buffer = mini_calloc(sizeof(char), BUFFER_SIZE);
		if(buffer == NULL)
			mini_exit(0); 
		ind = 0;
	}	
	for(int i=0 ; toprint[i] != '\0'; i++)
	{
		if(toprint[i] == '\n') 
		{	buffer[ind] = toprint[i];
			ind++;
			if(write(STDOUT_FILENO,buffer,ind) == -1)
				mini_exit(0);
			ind = 0;
		}
		else if(ind == BUFFER_SIZE)
		{
			if(write(STDOUT_FILENO,buffer,ind) == -1)
				mini_exit(0);
			ind = 0;
		}
		else if(toprint[i] != '\n')
		{
			buffer[ind] = toprint[i];
			ind++;
		}

	}
	if(ind != 0)
	{
		if(write(STDOUT_FILENO,buffer,ind) == -1)
				mini_exit(1);
			ind = 0;	
	}
}

int mini_scanf(char* buffer, int size_buffer)
{
	if(size_buffer <= 0 || mini_strlen(buffer) > size_buffer)
	{
		mini_exit(0);
	}

    // On lit le texte saisi au clavier

    if (read(STDIN_FILENO, buffer, size_buffer ) == -1)  
        return -1; 
    else
    {
    	int i=0;
    	while(buffer[i]!='\0')
    		i++;    	
    	return i;
    }
}

int mini_strlen(char* s)
{
	int i=0;
	while(s[i] != '\0')
		i++;

	return i;
}

int mini_strcpy(char* s, char *d) 
{
	int i=0;

	if(sizeof(s) > sizeof(d) || d == NULL)
		return -1;
	while(s[i] != '\0' )
	{
		d[i] = s[i];
		i++;	
	}
	return i;
}

int mini_strcmp(char* s1, char* s2)
{
	int i=0;
	if(mini_strlen(s1) != mini_strlen(s2))
		return -1;
	while(s1[i] != '\0')
	{
		if(s1[i] != s2[i])
			return -1;
		i++;
	}
	return 0;
}

void mini_perror(char * message)
{
	mini_printf(message);
	mini_printf(strerror(errno));
}
