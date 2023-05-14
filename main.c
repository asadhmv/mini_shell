#include <stdio.h>
#include <unistd.h>
#include "mini_lib.h"
#include <string.h>
int main( int argc, char **argv)
{
	printf("Bonjour on va tester toutes les fonctions que nous avons implemente\n\n");
	
	char *tab =  mini_calloc(sizeof(char), 20);
	printf("On alloue de la memoire pour char *tab avec mini_calloc\n");
	printf("Nous allons copier la chaine 'Hello World!' dans tab avec mini_strcpy\n");
	mini_strcpy("Hello World!", tab);
	mini_printf(tab);
	mini_printf("\nCe message vient d'etre affiche avec mini_printf\n");

	printf("mini_strlen(tab) = %i\n", mini_strlen(tab));	

	printf("\nVeuillez saisir une chaine:\n");
	char *buffer = mini_calloc(sizeof(char), 30);
	int longueur = mini_scanf(buffer, 30);
	printf("\nVoici le texte saisi:");
	printf("%s",buffer);
	printf("\n%i caracteres ont ete saisis\n", longueur);
	//mini_perror("erreur: ");

	printf("\n\n-----------------------------Gestion Entree Sortie----------------------------\n\n");


	char *fichier = mini_calloc(sizeof(char), 10);
	mini_strcpy("test",fichier);	
	MYFILE *file = mini_fopen(fichier, 'b');
	printf("\nNous allons ouvir le fichier test en mode binary");	
	char *buff = mini_calloc(sizeof(char), 2048);
	int lus = mini_fread(buff, sizeof(char), 2048, file);
	printf("\nAppel de la fonction mini_fread...");	

	printf("\n%i caracteres on ete lus du fichier",lus);
	printf("\n\nDesormais on va tester d'ajouter une chaine dans le fichier avec mini_fwrite\nVeuillez saisir un contenu a ajouter:\n");
	char* ajout =mini_calloc(sizeof(char),30);
	mini_scanf(ajout, 30);
	int ecrits = mini_fwrite(ajout, sizeof(char), 25, file);
	printf("\n%i caracteres ont ete ecrits dans le fichier ", ecrits);
	mini_fclose(file);

	printf("\nOn execute mini_fclose pour que le mini_fflsuh flush le contenu ajoute");
	file = mini_fopen(fichier, 'b');
	printf("\nNous allons tester fgetc et fputc le caractere $");
	char getc = mini_fgetc(file);
	printf("\nfgetc=%c",getc);
	printf("\nfgetc=%c",mini_fgetc(file));


	mini_fputc(file, '$');

	mini_fclose(file);		
	printf("\nToutes les fonctions ont ete testees, nous allons mini_exit()");
	mini_exit(0);

	return 0;
}
