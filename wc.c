#include "mini_lib.h"
#include <stddef.h>

/* A utility function to reverse a string  */
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
    	char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
 
// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;
 
    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
 
    return str;
}


int wc(char *name)
{
	MYFILE *file = mini_fopen(name, 'r');

	if(file == NULL)
	{
		mini_perror("fichier introuvable :");
		return -1;
	}
	char *buffer = mini_calloc(1, 4096);
	mini_fread(buffer, sizeof(char), 4096, file);

	int count_mots = 0;
	for(int i=0 ; buffer[i] != '\0' ; i++)
	{
		if(buffer[i] == '\n' || buffer[i] == ' ')
			count_mots++;
	}
	count_mots++;
	char *chaine = mini_calloc(sizeof(char), sizeof(int));
	chaine = itoa(count_mots, chaine, 10);
	mini_printf("Ce fichier contient ");
	mini_printf(chaine);
	mini_printf(" mots\n");
	mini_fclose(file);
	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		mini_perror("Saisir wc 'nom de fichier'");
		mini_exit(0);
	}
	wc(argv[1]);
	return 0;
}