#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

void status_file(char *file_name)
{
	struct stat *buf = malloc(1 * sizeof(struct stat));
	if(stat(file_name, buf) == -1)
	{
		perror("Fichier inexistant");
	}
	else
	{
		struct passwd *pw;
		struct group *g;
		pw = getpwuid(buf->st_uid);
		g = getgrgid(buf->st_gid);
		

		
		printf( (buf->st_mode & S_IRUSR) ? " r" : " -");
        printf( (buf->st_mode & S_IWUSR) ? "w" : "-");
        printf( (buf->st_mode & S_IXUSR) ? "x" : "-");
        printf( (buf->st_mode & S_IRGRP) ? "r" : "-");
        printf( (buf->st_mode & S_IWGRP) ? "w" : "-");
        printf( (buf->st_mode & S_IXGRP) ? "x" : "-");
        printf( (buf->st_mode & S_IROTH) ? "r" : "-");
        printf( (buf->st_mode & S_IWOTH) ? "w" : "-");
        printf( (buf->st_mode & S_IXOTH) ? "x" : "-");
        printf(" ");
		printf("%li  ", buf->st_nlink);
		printf("%s  ",pw->pw_name);
		printf("%s  ", g->gr_name);
		printf("%li  ", buf->st_size);
		char *time = ctime(&(buf->st_mtime));
		if(strlen(time) > 0)
			time[strlen(time) - 1] = '\0';
		printf("%s  ", time);
		printf("%s  ", file_name);

	}

}

void ls(char *file_name, char *option)
{
	struct stat *buf = malloc(1 * sizeof(struct stat));
	if(stat(file_name, buf) == -1)
	{
		perror("Fichier inexistant");
	}
	else
	{
		if(S_ISDIR(buf->st_mode))
		{
			struct dirent *dir;
			DIR *d = opendir(file_name);
			if(d)
			{
				while((dir = readdir(d)) != NULL)
				{
					if(strcmp(dir->d_name,".") == 0 || strcmp(dir->d_name, "..") == 0)
						continue;
					if(option != NULL)
						status_file(dir->d_name);
					else
						printf("%s", dir->d_name);
					printf("\n");
				}
			}
		}
	}
}



int main(int argc, char *argv[])
{
	ls(".", argv[1]);
	return 0;
}