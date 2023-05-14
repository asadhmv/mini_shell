#ifndef MINI_MEMORY_H
#define MINI_MEMORY_H

typedef enum{libre, utilise}bool;

struct malloc_element{
        void *p;
        int size_element;
        int number_element;
        int size;
        bool status;
        struct malloc_element *next_malloc;
};

//extern struct malloc_element *malloc_list;

void* mini_calloc (int size_element, int number_element);
void mini_free(void *ptr);
void mini_exit(int i);


void mini_printf(char *toprint);
int mini_scanf(char* buffer, int size_buffer);
int mini_strlen(char* s);
int mini_strcpy(char* s, char *d);
int mini_strcmp(char* s1, char* s2);
void mini_perror(char * message);


struct MYFILE
{
        int fd;
        void *buffer_read;
        void *buffer_write;
        int ind_read;
        int ind_write;
};

typedef struct MYFILE MYFILE;

MYFILE *mini_fopen(char *file, char mode);
int mini_fread(void* buffer,int size_element, int number_element, MYFILE* file);
int mini_fwrite(void* buffer,int size_element, int number_element, MYFILE* file);
int mini_fflush(MYFILE* file);
int mini_fclose(MYFILE* file);
int mini_fgetc(MYFILE* file);
int mini_fputc(MYFILE* file, char c);

int mini_touch(char *filename);
int mini_cp(char *src, char *dest);
int mini_echo(char *chaine);
int mini_cat(char *name);
int mini_head(char *f, int n);
int mini_tail(char *f, int n);
int mini_clean(char *name);
int mini_grep(char *name, char *mot);
int wc(char *name);


#endif
