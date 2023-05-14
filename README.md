# mini_shell

Projet pour les appels systèmes.
Projet de Réimplémentation des fonctions basiques en C et commandes d'un shell avec uniquement des appels système. 

Les fonction suivantes sont implémentées :
  * calloc() --> mini_calloc()
  * free()   --> mini_free()
  * printf() --> mini_printf()
  * scanf()  --> mini_scanf()
  * strlen() --> mini_strlen()
  * strcpy() --> mini_strcpy()
  * strcmp() --> mini_strcmp()
  * perror() --> mini_perror()
  * fopen()  --> mini_fopen()
  * fread()  --> mini_fread()
  * fwrite() --> mini_fwrite()
  * fflush() --> mini_fflush()
  * fclose() --> mini_fclose()
  * fgetc()  --> mini_fgetc()
  * fputc()  --> mini_fputc()

Le commandes shell suivantes ont été implémentées avec la réimplémentation des fonctions basiques susmentionnées :
  * cat
  * cd
  * chmod
  * clean
  * cp
  * echo
  * grep
  * head
  * ln
  * ls
  * mkdir
  * mv
  * quickdiff
  * rm
  * rmdir
  * tail
  * touch
  * wc
  
Afin de tester par vous  même, veuillez éxecuter uniquement la commande make qui compilera tous les fichiers et vous mène directement au mini_shell. 
Dans le mini_shell vous devez saisir les commandes présuivies de "mini_".
