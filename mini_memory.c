#include <unistd.h>
#include <signal.h>
#include "mini_lib.h"

struct malloc_element *malloc_list = NULL;

/*---------------------------mini_calloc----------------------------------------*/

void* mini_calloc (int size_element, int number_element)
{
	if(number_element < 0 || size_element < 0)
	{
	        return NULL;
	}
	void *res;
	if((res = sbrk (size_element * number_element)) == (void*)(-1))
	{
		mini_perror("Error \n");
		return NULL;
	}

	for(int i = 0; i < number_element; i++)
		((char*)res)[i] = '\0'; //Cette opération permet d'initialiser le buffer de façon sécurisée

/*---------------------------malloc_element----------------------------------------*/
	/*int asked_size = size_element * number_element;

	struct malloc_element * current = malloc_list;

	while(current != NULL)
	{
		if(current->size <= asked_size && current->status == 0)
		{
			printf("Case dispo");
			current->p = res;
			current->size_element = size_element;
			current->number_element = number_element;
			current->size = asked_size;
			current->status = 1;
			break;
		}
		current = current->next_malloc;
	}



	if(current == NULL)
	{*/
		int asked_size = size_element * number_element;

	struct malloc_element * current = sbrk(sizeof(struct malloc_element));
	current = malloc_list;
		struct malloc_element *new_element = sbrk(sizeof(struct malloc_element));
		if(new_element == NULL)
		{
			mini_perror("Erreur allocation liste\n");
			mini_exit(1);
		}
		if(malloc_list == NULL){
			new_element->p = res;
			new_element->size = size_element * number_element;
			new_element->size_element = size_element;
			new_element->number_element = number_element;
			new_element->status = utilise;
			new_element->next_malloc = NULL;
			malloc_list = new_element;
		}

		else
		{
			while(current != NULL)
			{
				if(current->size <= asked_size && current->status == 0)
				{
					break;
				}
				current = current->next_malloc;
			}
			if(current != NULL){
				current->p = res;
				current->status = 1;
			}
			else{
				new_element->p = res;
				new_element->size = size_element * number_element;
				new_element->size_element = size_element;
				new_element->number_element = number_element;
				new_element->status = utilise;
				new_element->next_malloc = malloc_list;
				malloc_list = new_element;	
			}
		}
	//}


	return res;
}

// Question 6: La fonction free ne libère pas réellement l'espace mémoire, car tout simplement les données ne sont pas détruites mais cet espa// ce mémoire n'appartient plus au programme ce qui fait que on a plus le droit d'accèes à cet emplacement


/*----------------------------------mini_free--------------------------------------*/

void mini_free(void *ptr)
{

	
			struct malloc_element *temp;
			temp = malloc_list;
			while(temp->next_malloc != NULL)
			{
				if(temp->p == ptr)
					break;
				temp = temp->next_malloc;
			}
			temp->status = libre;
			for(int i = 0; i < temp->number_element; i++)
			{
				((char*)ptr)[i] = '\0';
			}
			


}

/*----------------------------------mini_exit--------------------------------------*/


void mini_exit(int i)
{
	if(i == 0)
		_exit(0);
	else
		_exit(1);
}
